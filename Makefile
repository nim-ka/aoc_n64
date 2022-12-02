# Makefile to rebuild SM64 split image

### Default target ###

default: all

### Build Options ###

# These options can either be changed by modifying the makefile, or
# by building with 'make SETTING=value'. 'make clean' may be required.

TARGET := aoc64
VERSION_CFLAGS := -DVERSION_US
VERSION_ASFLAGS := --defsym VERSION_US=1

GRUCODE_CFLAGS := -DF3D_OLD
GRUCODE_ASFLAGS := --defsym F3D_OLD=1

MATCH_CFLAGS := -DNON_MATCHING -DAVOID_UB
MATCH_ASFLAGS := --defsym AVOID_UB=1

################### Universal Dependencies ###################

# (This is a bit hacky, but a lot of rules implicitly depend
# on tools and assets, and we use directory globs further down
# in the makefile that we want should cover assets.)

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),distclean)

# Make sure assets exist
DUMMY != ./extract_assets.py us >&2 || echo FAIL
ifeq ($(DUMMY),FAIL)
  $(error Failed to extract assets)
endif

# Make tools if out of date
DUMMY != make -s -C tools >&2 || echo FAIL
ifeq ($(DUMMY),FAIL)
  $(error Failed to build tools)
endif

endif
endif

################ Target Executable and Sources ###############

# BUILD_DIR is location where all build artifacts are placed
BUILD_DIR := build

LIBULTRA := $(BUILD_DIR)/libultra.a
ROM := $(BUILD_DIR)/$(TARGET).z64
ELF := $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT := sm64.ld
TEXTURE_DIR := textures

# Directories containing source files
SRC_DIRS := src src/buffers src/game src/game/aoc data
ASM_DIRS := asm asm/aoc lib

ULTRA_SRC_DIRS := lib/src lib/src/math
ULTRA_ASM_DIRS := lib/asm lib/data

MIPSISET := -mips2
MIPSBIT := -32

MIPSISET := -mips3

OPT_FLAGS := -O2

# File dependencies and variables for specific files
# --------------------------------------
# General Rules
# --------------------------------------

# obtain a list of segments from the *.c files in bin directory
TEXTURE_DIRS := textures/ipl3_raw

# NOTE: textures assume naming convention "texture.<encoding>.png" generates "texture.<encoding>"

IPL3_TEXTURE_FILES          := $(wildcard $(TEXTURE_DIR)/ipl3_raw/*.png)
IPL3_RAW_FILES              := $(addprefix $(BUILD_DIR)/,$(patsubst %.png,%,$(IPL3_TEXTURE_FILES)))

# Source code files
C_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c)) $(LEVEL_C_FILES)
S_FILES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
ULTRA_C_FILES := $(foreach dir,$(ULTRA_SRC_DIRS),$(wildcard $(dir)/*.c))
ULTRA_S_FILES := $(foreach dir,$(ULTRA_ASM_DIRS),$(wildcard $(dir)/*.s))

# Object files
O_FILES := $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
           $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
           $(foreach file,$(GENERATED_C_FILES),$(file:.c=.o))

ULTRA_O_FILES := $(foreach file,$(ULTRA_S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
                 $(foreach file,$(ULTRA_C_FILES),$(BUILD_DIR)/$(file:.c=.o))

# Automatic dependency files
DEP_FILES := $(O_FILES:.o=.d) $(ULTRA_O_FILES:.o=.d) $(BUILD_DIR)/$(LD_SCRIPT).d

##################### Compiler Options #######################
ifeq ($(shell type mips-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
  CROSS := mips-linux-gnu-
else ifeq ($(shell type mips64-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
  CROSS := mips64-linux-gnu-
else
  CROSS := mips64-elf-
endif

AS        := $(CROSS)as
CC        := $(CROSS)gcc
CPP       := cpp -P -Wno-trigraphs
LD        := $(CROSS)ld
AR        := $(CROSS)ar
OBJDUMP   := $(CROSS)objdump
OBJCOPY   := $(CROSS)objcopy
PYTHON    := python3

TARGET_CFLAGS := -nostdinc -I include/libc -DTARGET_N64 -D_LANGUAGE_C
CC_CFLAGS := -fno-builtin

INCLUDE_CFLAGS := -I include -I $(BUILD_DIR) -I $(BUILD_DIR)/include -I src -I .

COMMON_CFLAGS = $(OPT_FLAGS) $(TARGET_CFLAGS) $(INCLUDE_CFLAGS) $(VERSION_CFLAGS) $(MATCH_CFLAGS) $(MIPSISET) $(GRUCODE_CFLAGS)

ASFLAGS := -march=vr4300 -mabi=32 -I include -I $(BUILD_DIR) $(VERSION_ASFLAGS) $(MATCH_ASFLAGS) $(GRUCODE_ASFLAGS)
CFLAGS = -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm -Xfullwarn -signed $(COMMON_CFLAGS) $(MIPSBIT)
SYMBOL_LINKING_FLAGS := $(addprefix -R ,$(SEG_FILES))
LDFLAGS := -T undefined_syms.txt -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(BUILD_DIR)/$(TARGET).map --no-check-sections $(SYMBOL_LINKING_FLAGS)

CFLAGS := -march=vr4300 -mfix4300 -mabi=32 -mno-shared -G 0 -mhard-float -fno-stack-protector -fno-common -fno-zero-initialized-in-bss -I include -I src/ -I $(BUILD_DIR)/include -fno-PIC -mno-abicalls -fno-strict-aliasing -fno-inline-functions -ffreestanding -fwrapv -Wall -Wextra $(COMMON_CFLAGS)

ifeq ($(shell getconf LONG_BIT), 32)
  # Work around memory allocation bug in QEMU
  export QEMU_GUEST_BASE := 1
endif

# Prevent a crash with -sopt
export LANG := C

####################### Other Tools #########################

# N64 tools
TOOLS_DIR = tools
MIO0TOOL = $(TOOLS_DIR)/mio0
N64CKSUM = $(TOOLS_DIR)/n64cksum
N64GRAPHICS = $(TOOLS_DIR)/n64graphics

ifeq (, $(shell which armips 2>/dev/null))
  RSPASM := $(TOOLS_DIR)/armips
else
  RSPASM = armips
endif

######################## Targets #############################

all: $(ROM)

clean:
	$(RM) -r $(BUILD_DIR)

distclean:
	$(RM) -r $(BUILD_DIR)
	./extract_assets.py --clean

libultra: $(BUILD_DIR)/libultra.a

$(BUILD_DIR)/asm/boot.o: $(IPL3_RAW_FILES)

$(BUILD_DIR)/lib/rsp.o: $(BUILD_DIR)/rsp/rspboot.bin $(BUILD_DIR)/rsp/fast3d.bin $(BUILD_DIR)/rsp/audio.bin

$(BUILD_DIR)/lib/src/math/%.o: CFLAGS += -fno-builtin

RSP_DIRS := $(BUILD_DIR)/rsp
ALL_DIRS := $(BUILD_DIR) $(addprefix $(BUILD_DIR)/,$(SRC_DIRS) $(ASM_DIRS) $(ULTRA_SRC_DIRS) $(ULTRA_ASM_DIRS) $(TEXTURE_DIRS) include) $(RSP_DIRS)

# Make sure build directory exists before compiling anything
DUMMY != mkdir -p $(ALL_DIRS)

# RGBA32, RGBA16, IA16, IA8, IA4, IA1, I8, I4
$(BUILD_DIR)/%: %.png
	$(N64GRAPHICS) -i $@ -g $< -f $(lastword $(subst ., ,$@))

$(BUILD_DIR)/rsp/%.bin $(BUILD_DIR)/rsp/%_data.bin: rsp/%.s
	$(RSPASM) -sym $@.sym -definelabel VERSION_US 1 -definelabel F3D_OLD 1 -strequ CODE_FILE $(BUILD_DIR)/rsp/$*.bin -strequ DATA_FILE $(BUILD_DIR)/rsp/$*_data.bin $<

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: $(BUILD_DIR)/%.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) -MD $(BUILD_DIR)/$*.d -o $@ $<

$(BUILD_DIR)/$(LD_SCRIPT): $(LD_SCRIPT)
	$(CPP) $(VERSION_CFLAGS) -MMD -MP -MT $@ -MF $@.d -I include/ -I . -DBUILD_DIR=$(BUILD_DIR) -o $@ $<

$(BUILD_DIR)/libultra.a: $(ULTRA_O_FILES)
	$(AR) rcs -o $@ $(ULTRA_O_FILES)

$(ELF): $(O_FILES) $(BUILD_DIR)/$(LD_SCRIPT) undefined_syms.txt $(BUILD_DIR)/libultra.a
	$(LD) -L $(BUILD_DIR) $(LDFLAGS) -o $@ $(O_FILES)$(LIBS) -lultra

$(ROM): $(ELF)
	$(OBJCOPY) $< $(@:.z64=.bin) -O binary
	$(N64CKSUM) $(@:.z64=.bin) $@

$(BUILD_DIR)/$(TARGET).objdump: $(ELF)
	$(OBJDUMP) -D $< > $@

.PHONY: all clean distclean default diff libultra
# with no prerequisites, .SECONDARY causes no intermediate target to be removed
.SECONDARY:

# Remove built-in rules, to improve performance
MAKEFLAGS += --no-builtin-rules

-include $(DEP_FILES)

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
