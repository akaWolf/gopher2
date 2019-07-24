#!/bin/sh

set -euxo pipefail

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

export PATH="$DIR":"$PATH"

stage2_tool config="$DIR/empty.bin"

stage2_tool sdinit

stage2_tool sdif="$1@0x01000000#1"
