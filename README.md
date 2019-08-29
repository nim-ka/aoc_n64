# Super Mario 64

This repo contains a full decompilation of Super Mario 64 (J) and (U).
The source and data have been decompiled but complete naming and documentation
all of the code and data is still a work in progress. Decompiling the (E) ROM
is also an ongoing effort.

It builds the following ROMs:

* sm64.jp.z64 `sha1: 8a20a5c83d6ceb0f0506cfc9fa20d8f438cafe51`
* sm64.us.z64 `sha1: 9bef1128717f958171a4afac3ed78ee2bb4e86ce`

This repo does not include all assets necessary for compiling the ROMs.
A prior copy of the game is required to extract the required assets.

## Installation

### Linux

1. For each version (jp/us/eu) that you want to build a ROM for, put an existing ROM at
`./baserom.<version>.z64` for asset extraction.

2. Install the following packages:

__Debian / Ubuntu__
* git
* binutils-mips-linux-gnu (>= 2.27)
* python3 (>= 3.6)
* build-essential
* pkg-config
* zlib1g-dev
* libaudiofile-dev

__Arch Linux__
* base-devel
* python
* audiofile
* [mips64-elf-binutils](https://aur.archlinux.org/packages/mips64-elf-binutils) (AUR)
* [qemu-irix-git](https://aur.archlinux.org/packages/qemu-irix-git) (AUR)


3. Install qemu-irix

   a. Options:
      1. Clone https://github.com/n64decomp/qemu-irix to somewhere and follow its
         install instructions in the README.
      2. Optionally, grab the prebuilt qemu-irix from the Releases section.
      3. (Arch) Use AUR package [qemu-irix-git](https://aur.archlinux.org/packages/qemu-irix-git)

   b. (For the first two options), copy executable `qemu-irix` from irix-linux-user to
      somewhere convenient with a relatively short path.
```
mkdir -p /opt/qemu-irix/bin
cp irix-linux-user/qemu-irix /opt/qemu-irix/bin
```

   c. Define `QEMU_IRIX` environment variable in your `~/.bashrc` to point to
      this qemu-irix executable.
```
export QEMU_IRIX=/opt/qemu-irix/bin/qemu-irix
```

4. Run `make` to build the ROM (defaults to `VERSION=us`). Make sure your path to
   the repo is not too long or else this process will error, as the emulated
   IDO compiler cannot handle paths longer than 255 characters.
Build examples:
```
make VERSION=jp -j4       # build (J) version instead with 4 jobs
make VERSION=eu COMPARE=0 # non-matching EU version still WIP
```

## Windows

For Windows, install WSL and a distro of your choice and follow the Linux guide.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to
discuss what you would like to change.

Run clang-format on your code to ensure it meets the project's coding standards.

Official discord: https://discord.gg/27JtCWs
