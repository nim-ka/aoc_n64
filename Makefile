# Makefile to rebuild SM64 split image

### Build Options ###
# Version of the game to build
VERSION ?= jp
# If COMPARE is 1, check the output sha1sum when building 'all'
COMPARE ?= 1

ifeq ($(VERSION),jp)
  VERSION_CFLAGS := -DVERSION_JP=1
  VERSION_ASFLAGS := --defsym VERSION_JP=1
  TARGET := sm64.j
else
ifeq ($(VERSION),us)
  VERSION_CFLAGS := -DVERSION_US=1
  VERSION_ASFLAGS := --defsym VERSION_US=1
  TARGET := sm64.u
else
  $(error unknown version "$(VERSION)")
endif
endif

################ Target Executable and Sources ###############

# BUILD_DIR is location where all build artifacts are placed
BUILD_DIR := build

ROM := $(BUILD_DIR)/$(TARGET).z64
ELF := $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT := sm64.ld
MIO0_DIR := $(BUILD_DIR)/mio0
TEXTURE_DIR := textures

# Directories containing source files
SRC_DIRS := src src/libultra src/goddard
ASM_DIRS := asm data geo levels sound demos anims text
BIN_DIRS := bin

MIPSISET := -mips2

# Source code files
C_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
SEG_IN_FILES := $(foreach dir,$(BIN_DIRS),$(wildcard $(dir)/*.s.in))
SEG_S_FILES := $(foreach dir,$(BIN_DIRS),$(wildcard $(dir)/*.s)) \
               $(foreach file,$(SEG_IN_FILES),$(file:.s.in=.s))

# Object files
O_FILES := $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
           $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o))

# Automatic dependency files
DEP_FILES := $(O_FILES:.o=.d)

# Segment elf files
SEG_FILES := $(foreach file,$(SEG_S_FILES),$(BUILD_DIR)/$(file:.s=.elf))

##################### Compiler Options #######################
IRIX_ROOT := tools/ido5.3_compiler
CROSS     := mips-linux-gnu-
AS        := $(CROSS)as
CC        := $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc
CPP       := cpp -P
LD        := $(CROSS)ld
OBJDUMP   := $(CROSS)objdump
OBJCOPY   := $(CROSS)objcopy

# Check code syntax with host compiler
CC_CHECK := gcc -fsyntax-only -fsigned-char -I include -std=gnu90 -Wall -Wextra -Wno-format-security $(VERSION_CFLAGS)

ASFLAGS := -march=vr4300 -mabi=32 -I include $(VERSION_ASFLAGS)
CFLAGS := -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm -Xfullwarn -g -signed -I include $(VERSION_CFLAGS)
OBJCOPYFLAGS := --pad-to=0x800000 --gap-fill=0xFF
SYMBOL_LINKING_FLAGS := $(addprefix -R ,$(SEG_FILES))
LDFLAGS := -T undefined_syms.txt -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(BUILD_DIR)/sm64.map --no-check-sections $(SYMBOL_LINKING_FLAGS)

ifeq ($(shell getconf LONG_BIT), 32)
  # Work around memory allocation bug in QEMU
  export QEMU_GUEST_BASE := 1
else
  # Ensure that gcc treats the code as 32-bit
  CC_CHECK += -m32
endif

####################### Other Tools #########################

# N64 tools
TOOLS_DIR = tools
MIO0TOOL = $(TOOLS_DIR)/mio0
N64CKSUM = $(TOOLS_DIR)/n64cksum
N64GRAPHICS = $(TOOLS_DIR)/n64graphics
TEXTCONV = $(TOOLS_DIR)/textconv
EMULATOR = mupen64plus
EMU_FLAGS = --noosd
LOADER = loader64
LOADER_FLAGS = -vwf
SHA1SUM = sha1sum

###################### Dependency Check #####################

BINUTILS_VER_MAJOR := $(shell $(LD) --version | grep ^GNU | sed 's/^.* //; s/\..*//g')
BINUTILS_VER_MINOR := $(shell $(LD) --version | grep ^GNU | sed 's/^[^.]*\.//; s/\..*//g')
BINUTILS_DEPEND := $(shell expr $(BINUTILS_VER_MAJOR) \>= 2 \& $(BINUTILS_VER_MINOR) \>= 27)
ifeq ($(BINUTILS_DEPEND),0)
$(error binutils version 2.27 required, version $(BINUTILS_VER_MAJOR).$(BINUTILS_VER_MINOR) detected)
endif

ifndef QEMU_IRIX
$(error env variable QEMU_IRIX should point to the qemu-mips binary)
endif

######################## Targets #############################

default: all

# file dependencies generated by splitter
include Makefile.split

all: $(ROM)
ifeq ($(COMPARE),1)
	@$(SHA1SUM) -c $(TARGET).sha1
endif

clean:
	$(RM) -r $(BUILD_DIR) src/text_strings.h text/us/*.s text/jp/*.s

test: $(ROM)
	$(EMULATOR) $(EMU_FLAGS) $<

load: $(ROM)
	$(LOADER) $(LOADER_FLAGS) $<

src/text_strings.h: src/text_strings.h.in
	$(TEXTCONV) charmap.txt $< $@

text/%.s: text/%.s.in
	$(TEXTCONV) charmap.txt $< $@

bin/segment2.s: text/$(VERSION)/debug.s text/$(VERSION)/dialog.s text/$(VERSION)/level.s text/$(VERSION)/star.s

$(MIO0_DIR)/%.mio0: bin/%.bin
	$(MIO0TOOL) $< $@

$(BUILD_DIR):
	mkdir $(BUILD_DIR) $(addprefix $(BUILD_DIR)/,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS) $(TEXTURE_DIRS)) $(MIO0_DIR)

# Make sure build directory exists before compiling objects
$(O_FILES): | $(BUILD_DIR)

$(BUILD_DIR)/src/star_select.o: src/text_strings.h
$(BUILD_DIR)/src/file_select.o: src/text_strings.h

# texture generation
$(BUILD_DIR)/bin/%.rgba16: textures/%.rgba16.png
	$(N64GRAPHICS) -i $@ -g $< -f rgba16

$(BUILD_DIR)/bin/%.ia16: textures/%.ia16.png
	$(N64GRAPHICS) -i $@ -g $< -f ia16

$(BUILD_DIR)/bin/%.ia8: textures/%.ia8.png
	$(N64GRAPHICS) -i $@ -g $< -f ia8

$(BUILD_DIR)/bin/%.ia4: textures/%.ia4.png
	$(N64GRAPHICS) -i $@ -g $< -f ia4

$(BUILD_DIR)/bin/%.ia1: textures/%.ia1.png
	$(N64GRAPHICS) -i $@ -g $< -f ia1

# compressed segment generation
$(BUILD_DIR)/bin/%.o: bin/%.s
	$(AS) $(ASFLAGS) --no-pad-sections -o $@ $<

# TODO: ideally this would be `-Trodata-segment=0x07000000` but that doesn't set the address
$(BUILD_DIR)/bin/%.elf: $(BUILD_DIR)/bin/%.o
	$(LD) -e 0 -Ttext=$(SEGMENT_ADDRESS) -Map $@.map -o $@ $<

$(BUILD_DIR)/bin/%.bin: $(BUILD_DIR)/bin/%.elf
	$(OBJCOPY) -j .rodata $< -O binary $@

$(MIO0_DIR)/%.mio0: $(BUILD_DIR)/bin/%.bin
	$(MIO0TOOL) $< $@

$(MIO0_DIR)/%.mio0.o: $(MIO0_DIR)/%.mio0.s
	$(AS) $(ASFLAGS) -o $@ $<

$(MIO0_DIR)/%.mio0.s: $(MIO0_DIR)/%.mio0
	printf ".section .data\n\n.incbin \"$<\"\n" > $@

# Source code

$(BUILD_DIR)/src/goddard/%.o: MIPSISET := -mips1

$(BUILD_DIR)/%.o: %.c
	@$(CC_CHECK) -MMD -MT $@ -MF $(BUILD_DIR)/$*.d $<
	$(CC) -c $(CFLAGS) $(MIPSISET) -o $@ $<

$(BUILD_DIR)/%.o: %.s $(MIO0_FILES)
	$(AS) $(ASFLAGS) -MD $(BUILD_DIR)/$*.d -o $@ $<

$(BUILD_DIR)/$(LD_SCRIPT): $(LD_SCRIPT)
	$(CPP) $(VERSION_CFLAGS) $< > $@

$(ELF): $(O_FILES) $(MIO0_OBJ_FILES) $(SEG_FILES) $(BUILD_DIR)/$(LD_SCRIPT) undefined_syms.txt
	$(LD) $(LDFLAGS) -o $@ $(O_FILES) $(LIBS)

$(ROM): $(ELF)
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $(@:.z64=.bin) -O binary
	$(N64CKSUM) $(@:.z64=.bin) $@

$(BUILD_DIR)/$(TARGET).objdump: $(ELF)
	$(OBJDUMP) -D $< > $@

.PHONY: all clean default diff test load
.PRECIOUS: $(BUILD_DIR)/mio0/%.mio0 $(BUILD_DIR)/bin/%.elf $(BUILD_DIR)/mio0/%.mio0.s

-include $(DEP_FILES)
