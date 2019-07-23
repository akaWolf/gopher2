#!/bin/sh

set -euxo pipefail

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

if [ -z ${1+x} ]; then stage1="$DIR/fw_ddr2.bin"; else stage1="$1"; fi
if [ -z ${2+x} ]; then stage2="$DIR/usb_boot.bin"; else stage2="$2"; fi

export PATH="$DIR":"$PATH"

rom_tool probe

rom_tool addr=0x80000000

rom_tool if="$stage1"

rom_tool start=1@0x80000000

rom_tool probe

rom_tool addr=0x80000000

rom_tool if="$stage2"

rom_tool flush

rom_tool start=2@0x80000000

rom_tool probe
