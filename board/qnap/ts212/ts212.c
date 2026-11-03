// SPDX-License-Identifier: GPL-2.0+

#include <asm/arch/soc.h>
#include <asm/arch/mpp.h>
#include <netdev.h>
#include <asm/arch/cpu.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/gpio.h>
#include <asm/global_data.h>
#include <asm/mach-types.h>
#include <command.h>
#include <init.h>
#include <linux/bitops.h>

DECLARE_GLOBAL_DATA_PTR;

int board_early_init_f(void)
{
	/* Multi-Purpose Pins Functionality configuration */
	u32 kwmpp_config[] = {
                MPP0_SPI_SCn,
                MPP1_SPI_MOSI,
                MPP2_SPI_SCK,
                MPP3_SPI_MISO,
                MPP4_SATA1_ACTn,
                MPP5_SATA0_ACTn,
                MPP8_TW_SDA,		/* I2c */
                MPP9_TW_SCK,		/* I2c */
                MPP10_UART0_TXD,
                MPP11_UART0_RXD,
                MPP13_UART1_TXD,        /* PIC controller */
                MPP14_UART1_RXD,        /* PIC controller */
                MPP15_GPIO,             /* USB Copy button (on devices with 88F6281) */
                MPP16_GPIO,             /* Reset button (on devices with 88F6281) */
                MPP36_GPIO,             /* RAM: 0: 256 MB, 1: 512 MB */
                MPP37_GPIO,             /* Reset button (on devices with 88F6282) */
                MPP43_GPIO,             /* USB Copy button (on devices with 88F6282) */
                MPP44_GPIO,             /* Board ID: 0: TS-11x, 1: TS-21x */
                0
	};
	kirkwood_mpp_conf(kwmpp_config, NULL);
	return 0;
}

int board_eth_init(struct bd_info *bis)
{
	return cpu_eth_init(bis);
}

int board_init(void)
{
	/*
	 * arch number of board
	 */
	gd->bd->bi_arch_number = MACH_TYPE_TS219;

	/* address of boot parameters */
	gd->bd->bi_boot_params = mvebu_sdram_bar(0) + 0x100;

	return 0;
}
