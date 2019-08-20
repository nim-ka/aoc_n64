# Linux

1] For each version (jp/us/eu) that you want to build a ROM for, put an existing ROM at `baserom.<version>.z64`.
This will be used for asset extraction.

2] Install the following packages:

* make
* git
* binutils-mips-linux-gnu (>= 2.27)
* python3
* build-essential
* pkg-config
* zlib1g-dev
* libglib2.0-dev
* libpixman-1-dev
* libcapstone3
* libaudiofile-dev

3] Clone https://github.com/camthesaxman/qemu-irix to somewhere and follow its install instructions in the README.

3b] Optionally, grab the prebuilt qemu-irix from the Releases section.

4] Take the executable `qemu-irix` in irix-linux-user and put it somewhere where you will define an environment variable to it.

5] Define `QEMU_IRIX` in your bashrc to point to this qemu-irix executable.

6] After setting this repository up, run `make` to build the ROM. Make sure your path is not too long or else this process will error, as the emulated IDO compiler cannot handle paths longer than 255 characters.

# Windows

For Windows, install WSL and a distro of your choice and follow the Linux guide.
