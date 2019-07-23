# About

This is repository with the sources of stage1 and stage2 bootloaders and host tools which can be used to flash Gopher 2 (and similar) boards.
Forked from [GCW](https://github.com/gcwnow/ingenic-boot/).

# Preparations

You need host gcc toolchain and `mipsel-linux-` one at your PATH.

# Building

Just run `build.sh`.
Note: `build.sh -c` will clear all builded binaries.

# Flashing

1. Run `upload_fw.sh` to upload and run stage1 and stage2 bootloaders.
2. Run `flash.sh /path/to/images` to flash your board.

# Known issues

* Sometimes stage1 is failed, so you need to run `upload_fw.sh` again.

# Limitations

* Currently only JZ4760B+eMMC variant is supported.
