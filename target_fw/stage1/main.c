/*
 * main.c
 *
 * Main routine of the firmware.
 *
 * Copyright (C) 2008 Ingenic Semiconductor Inc.
 *
 */
#include "jz4760.h"
#include "configs.h"

volatile u32 i;

void c_main(void)
{
	unsigned int cpu_id;
	cpu_id = *((volatile u32*) (0XBFC0132C));

	gpio_init_4760();
	
	if(cpu_id == 0x352920e4)
	{
		// for jz4760B
		__cpm_start_uart1();
		REG_MDMAC_DMACKES = 0x3;
	}

	__cpm_start_ddr();
	__cpm_start_mdma();
	__cpm_start_dmac();
	__cpm_start_uart1();
	__cpm_start_bch();
	__cpm_start_nemc();
	
	serial_init();
	if(cpu_id == 0x352920e4)
	{
		serial_puts("Setup JZ4760B fw args finish!\n");
	}
	else
	{
		serial_puts("Setup JZ4760 fw args finish!\n");
	}
	pll_init_4760();
	sdram_init_4760(cpu_id);

	serial_puts("Setup fw args finish!\n");
	__asm__ (
		"li  $31, 0xbfc012e0 \n\t"
		"jr  $31 \n\t "
		);
}


