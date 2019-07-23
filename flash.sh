#!/bin/sh

set -euxo pipefail

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

export PATH="$DIR":"$PATH"

stage2_tool config="$DIR/empty.bin"

stage2_tool sdinit

stage2_tool sdif="$1/mbr-uboot-msc.bin@0x00000000#1"

stage2_tool sdif="$1/uImage@0x00400000#1"

stage2_tool sdif="$1/rootfs.ext3@0x01000000#1"

stage2_tool sdif="$1/appfs.ext3@0x07400000#1"

stage2_tool sdif="$1/configfs.ext3@0x09200000#1"
