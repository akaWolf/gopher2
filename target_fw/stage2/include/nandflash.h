#ifndef __NANDLIB_H__
#define __NANDLIB_H__

#ifndef NULL
#define NULL	0
#endif

#define u8	unsigned char
#define u16	unsigned short
#define u32	unsigned int

#define NAND_MAX_PAGESIZE	8192
#define NAND_MAX_OOBSIZE	1024
#define NAND_MAX_BAD		NAND_MAX_PAGESIZE + NAND_MAX_OOBSIZE
#define NAND_MAX_BAD_PAGES	256
#define NAND_MAX_OOB_PAR	64
#define NAND_MAX_DATA_PAR	1280

/*  Jz4760 nandflash interface */
unsigned int nand_query_4760(u8 *);
int nand_init_4760(int bus_width, int row_cycle, int page_size, int page_per_block,
		   int bch_bit, int ecc_pos, int bad_pos, int bad_page, int force, int nand_os, int nand_bchstyle);
int nand_fini_4760(void);
u32 nand_program_4760(void *context, int spage, int pages, int option);
u32 nand_erase_4760(int blk_num, int sblk, int force);
u32 nand_read_4760(void *buf, u32 startpage, u32 pagenum,int option);
u32 nand_read_oob_4760(void *buf, u32 startpage, u32 pagenum);
u32 nand_read_raw_4760(void *buf, u32 startpage, u32 pagenum,int);
u32 nand_mark_bad_4760(int bad);
void nand_enable_4760(u32 csn);
void nand_disable_4760(u32 csn);
unsigned int nand_mark_erase_4760(void);
int hw_reset_4760(void);

#endif
