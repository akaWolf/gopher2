#!/bin/sh

set -euxo pipefail

clean_goal=""
while getopts "c" o; do
	case "${o}" in
		c)
			clean_goal=clean
			;;
		*)
			exit 1
			;;
	esac
done
shift $((OPTIND-1))

which mipsel-linux-gcc

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

make -C "$DIR/target_fw/stage1" $clean_goal
if [ -z ${clean_goal} ]
then
	cp "$DIR/target_fw/stage1/fw_ddr2.bin" "$DIR"
else
	rm -f "$DIR/fw_ddr2.bin"
fi

make -C "$DIR/target_fw/stage2" $clean_goal
if [ -z ${clean_goal} ]
then
	cp "$DIR/target_fw/stage2/usb_boot.bin" "$DIR"
else
	rm -f "$DIR/usb_boot.bin"
fi

make -C "$DIR/host_tools/rom_tool" $clean_goal
if [ -z ${clean_goal} ]
then
	cp "$DIR/host_tools/rom_tool/rom_tool" "$DIR"
else
	rm -f "$DIR/rom_tool"
fi

make -C "$DIR/host_tools/stage2_tool" $clean_goal
if [ -z ${clean_goal} ]
then
	cp "$DIR/host_tools/stage2_tool/stage2_tool" "$DIR"
else
	rm -f "$DIR/stage2_tool"
fi
