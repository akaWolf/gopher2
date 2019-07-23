#ifndef _CONFIGS_H
#define _CONFIGS_H

extern void gpio_init_4760(void);
extern void sdram_init_4760(unsigned int);
extern void serial_init_4760(void);
extern void pll_init_4760(void);

extern void serial_puts(const char *s);

#endif 
