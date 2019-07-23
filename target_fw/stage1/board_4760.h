/*
 * jz4760_board.h
 *
 * JZ4760 board definitions.
 *
 * Copyright (c) 2005-2008 Ingenic Semiconductor Inc.
 *
 */
#ifndef __BOARD_JZ4760_H__
#define __BOARD_JZ4760_H__

/*-------------------------------------------------------------------
 * Frequency of the external OSC in Hz.
 */
#define CFG_EXTAL		12000000
/*-------------------------------------------------------------------
 * CPU speed.
 */
#define CFG_CPU_SPEED		400000000	/* CPU clock */

/*-------------------------------------------------------------------
 * Serial console.
 */
#define CFG_UART_BASE		UART1_BASE
#define CONFIG_BAUDRATE		57600

#define __CFG_EXTAL     (CFG_EXTAL / 1000000)
#define __CFG_PLL_OUT   (CFG_CPU_SPEED / 1000000)

#ifdef CFG_PLL1_FRQ
    #define __CFG_PLL1_OUT  ((CFG_PLL1_FRQ)/1000000)    /* Set PLL1 default: 240MHz */
#else
    #define __CFG_PLL1_OUT  (432)                       /* Set PLL1 default: 432MHZ  UHC:48MHZ TVE:27MHZ */
#endif

/*pll_0*/ 
#if (__CFG_PLL_OUT > 1500)
	#error "PLL output can NOT more than 1500"
#elif (__CFG_PLL_OUT >= 624)
	#define __PLL_OD          0
	#define __PLL_NO          1
#elif (__CFG_PLL_OUT >= 336)
        #define __PLL_OD          1
        #define __PLL_NO          2
#elif (__CFG_PLL_OUT >= 168)
        #define __PLL_OD          2
        #define __PLL_NO          4
#elif (__CFG_PLL_OUT >= 72)
        #define __PLL_OD          3
        #define __PLL_NO          8
#else
	#error "PLL ouptput can NOT less than 72"
#endif

#define __PLL_N		2
#define __PLL_M		(((__CFG_PLL_OUT / __CFG_EXTAL) * __PLL_NO * __PLL_N) >> 1)


#if ((__PLL_M > 127) || (__PLL_M < 2))
	#error "Can NOT set the value to PLL_M"
#endif


#define CPCCR_M_N_OD	((__PLL_M << 24) | (__PLL_N << 18) | (__PLL_OD << 16))

/*pll_1*/
#if (__CFG_PLL1_OUT > 1500)
    #error "PLL1 output can NOT more than 1500"
#elif (__CFG_PLL1_OUT >= 624)
    #define __PLL1_OD          0
    #define __PLL1_NO          1
#elif (__CFG_PLL1_OUT >= 336)
    #define __PLL1_OD          1
    #define __PLL1_NO          2
#elif (__CFG_PLL1_OUT >= 168)
    #define __PLL1_OD          2
    #define __PLL1_NO          4
#elif (__CFG_PLL1_OUT >= 72)
    #define __PLL1_OD          3
    #define __PLL1_NO          8
#else
    #error "PLL1 ouptput can NOT less than 72"
#endif

#define __PLL1_N        2
#define __PLL1_M        (((__CFG_PLL1_OUT / __CFG_EXTAL) * __PLL1_NO * __PLL1_N) >> 1)

#if ((__PLL1_M > 127) || (__PLL1_M < 2))
    #error "Can NOT set the value to PLL1_M"
#endif

#define CPCCR1_M_N_OD   ((__PLL1_M << CPM_CPPCR1_PLL1M_BIT) | (__PLL1_N << CPM_CPPCR1_PLL1N_BIT) | (__PLL1_OD << CPM_CPPCR1_PLL1OD_BIT))


#endif /* __BOARD_JZ4760_H__ */
