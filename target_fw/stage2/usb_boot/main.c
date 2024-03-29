/*  special main file!
 *  do not edit!
 */
//#include "jz4740.h"

extern void usb_main();
unsigned int start_addr,got_start,got_end;
extern unsigned int UART_BASE;

void c_main(void)
{
	volatile unsigned int addr,offset;
	/* get absolute start address  */
	__asm__ __volatile__(			
		"move %0, $20\n\t"
		: "=r"(start_addr)
		: 
		);			

	/* get related GOT address  */
	__asm__ __volatile__(			
		"la $4, _GLOBAL_OFFSET_TABLE_\n\t"
		"move %0, $4\n\t"
		"la $5, _got_end\n\t"
		"move %1, $5\n\t"
		: "=r"(got_start),"=r"(got_end)
		: 
		);			

	/* calculate offset and correct GOT*/
	offset = start_addr - 0x80000000;	
 	got_start += offset;
	got_end  += offset;

	for ( addr = got_start + 8; addr < got_end; addr += 4 )
	{
		*((volatile unsigned int *)(addr)) += offset;   //add offset to correct all GOT
	}
	
	serial_puts("\nStart address is :");
	serial_put_hex(start_addr);
	serial_puts("Address offset is:");
	serial_put_hex(offset);
	serial_puts("GOT correct to   :");
	serial_put_hex(got_start);

	usb_main();
}
