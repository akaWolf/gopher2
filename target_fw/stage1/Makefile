#
# Copyright (C) 2006 Ingenic Semiconductor Inc.
#
# Makefile for the JZ4760 internal bootrom code.
#

CROSS	:= mipsel-linux-

CFLAGS	:= -O2 -mips32 -fno-pic -mno-abicalls
LDFLAGS	:= -nostdlib -EL -T target.ld 

OBJS	= head.o main.o common.o board_4760.o debug.o jz4760_ddr2.o

all: fw_ddr2.bin

fw_ddr2.bin: fw_ddr2.elf
	$(CROSS)objcopy -O binary $< $@
	$(CROSS)objdump -D $< > fw.dump
	$(CROSS)objdump -h $< > fw.map
	$(CROSS)nm -n $< > System.map
fw_ddr2.elf: $(OBJS)
	$(CROSS)ld $(LDFLAGS) $(OBJS) -o $@

.c.o:
	$(CROSS)gcc $(CFLAGS) -c $< -o $@
.S.o:
	$(CROSS)gcc $(CFLAGS) -c $< -o $@
clean:
	rm -fr *.o *.elf *.bin *.dump *.map
