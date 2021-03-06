/*
 * Copyright (C) 2017 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <mt-plat/mtk_io.h>
#include <mt-plat/sync_write.h>
/* #include <mt-plat/mtk_secure_api.h> */

#include <mtk_dcm_internal.h>
#include <mtk_dcm_autogen.h>
#include <mtk_dcm.h>

#define INFRACFG_AO_INFRA_BUS_DCM_REG0_MASK ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x1 << 3) | \
			(0x1 << 4) | \
			(0x1f << 5) | \
			(0x1f << 10) | \
			(0x1 << 20) | \
			(0x1 << 23) | \
			(0x1 << 30))
#define INFRACFG_AO_INFRA_BUS_DCM_REG0_ON ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x0 << 3) | \
			(0x0 << 4) | \
			(0x10 << 5) | \
			(0x10 << 10) | \
			(0x1 << 20) | \
			(0x1 << 23) | \
			(0x1 << 30))
#define INFRACFG_AO_INFRA_BUS_DCM_REG0_OFF ((0x0 << 0) | \
			(0x0 << 1) | \
			(0x0 << 3) | \
			(0x0 << 4) | \
			(0x10 << 5) | \
			(0x10 << 10) | \
			(0x0 << 20) | \
			(0x0 << 23) | \
			(0x0 << 30))

bool dcm_infracfg_ao_infra_bus_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(INFRA_BUS_DCM_CTRL) &
		INFRACFG_AO_INFRA_BUS_DCM_REG0_MASK) ==
		(unsigned int) INFRACFG_AO_INFRA_BUS_DCM_REG0_ON);

	return ret;
}

void dcm_infracfg_ao_infra_bus_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'infracfg_ao_infra_bus_dcm'" */
		reg_write(INFRA_BUS_DCM_CTRL,
			(reg_read(INFRA_BUS_DCM_CTRL) &
			~INFRACFG_AO_INFRA_BUS_DCM_REG0_MASK) |
			INFRACFG_AO_INFRA_BUS_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'infracfg_ao_infra_bus_dcm'" */
		reg_write(INFRA_BUS_DCM_CTRL,
			(reg_read(INFRA_BUS_DCM_CTRL) &
			~INFRACFG_AO_INFRA_BUS_DCM_REG0_MASK) |
			INFRACFG_AO_INFRA_BUS_DCM_REG0_OFF);
	}
}

#define INFRACFG_AO_INFRA_EMI_LOCAL_DCM_REG0_MASK ((0x1 << 27))
#define INFRACFG_AO_INFRA_EMI_LOCAL_DCM_REG0_ON ((0x1 << 27))
#define INFRACFG_AO_INFRA_EMI_LOCAL_DCM_REG0_OFF ((0x0 << 27))

bool dcm_infracfg_ao_infra_emi_local_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(MEM_DCM_CTRL) &
		INFRACFG_AO_INFRA_EMI_LOCAL_DCM_REG0_MASK) ==
		(unsigned int) INFRACFG_AO_INFRA_EMI_LOCAL_DCM_REG0_ON);

	return ret;
}

void dcm_infracfg_ao_infra_emi_local_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'infracfg_ao_infra_emi_local_dcm'" */
		reg_write(MEM_DCM_CTRL,
			(reg_read(MEM_DCM_CTRL) &
			~INFRACFG_AO_INFRA_EMI_LOCAL_DCM_REG0_MASK) |
			INFRACFG_AO_INFRA_EMI_LOCAL_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'infracfg_ao_infra_emi_local_dcm'" */
		reg_write(MEM_DCM_CTRL,
			(reg_read(MEM_DCM_CTRL) &
			~INFRACFG_AO_INFRA_EMI_LOCAL_DCM_REG0_MASK) |
			INFRACFG_AO_INFRA_EMI_LOCAL_DCM_REG0_OFF);
	}
}

#define INFRACFG_AO_INFRA_RX_P2P_DCM_REG0_MASK ((0xf << 0))
#define INFRACFG_AO_INFRA_RX_P2P_DCM_REG0_ON ((0x0 << 0))
#define INFRACFG_AO_INFRA_RX_P2P_DCM_REG0_OFF ((0xf << 0))

bool dcm_infracfg_ao_infra_rx_p2p_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(P2P_RX_CLK_ON) &
		INFRACFG_AO_INFRA_RX_P2P_DCM_REG0_MASK) ==
		(unsigned int) INFRACFG_AO_INFRA_RX_P2P_DCM_REG0_ON);

	return ret;
}

void dcm_infracfg_ao_infra_rx_p2p_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'infracfg_ao_infra_rx_p2p_dcm'" */
		reg_write(P2P_RX_CLK_ON,
			(reg_read(P2P_RX_CLK_ON) &
			~INFRACFG_AO_INFRA_RX_P2P_DCM_REG0_MASK) |
			INFRACFG_AO_INFRA_RX_P2P_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'infracfg_ao_infra_rx_p2p_dcm'" */
		reg_write(P2P_RX_CLK_ON,
			(reg_read(P2P_RX_CLK_ON) &
			~INFRACFG_AO_INFRA_RX_P2P_DCM_REG0_MASK) |
			INFRACFG_AO_INFRA_RX_P2P_DCM_REG0_OFF);
	}
}

#define INFRACFG_AO_PERI_BUS_DCM_REG0_MASK ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x1 << 3) | \
			(0x1 << 4) | \
			(0x1f << 5) | \
			(0x1f << 10) | \
			(0x1f << 15) | \
			(0x1 << 20) | \
			(0x1 << 21))
#define INFRACFG_AO_PERI_BUS_DCM_REG0_ON ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x0 << 3) | \
			(0x0 << 4) | \
			(0x1f << 5) | \
			(0x0 << 10) | \
			(0x1f << 15) | \
			(0x1 << 20) | \
			(0x1 << 21))
#define INFRACFG_AO_PERI_BUS_DCM_REG0_OFF ((0x0 << 0) | \
			(0x0 << 1) | \
			(0x0 << 3) | \
			(0x0 << 4) | \
			(0x1f << 5) | \
			(0x1f << 10) | \
			(0x0 << 15) | \
			(0x0 << 20) | \
			(0x0 << 21))

bool dcm_infracfg_ao_peri_bus_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(PERI_BUS_DCM_CTRL) &
		INFRACFG_AO_PERI_BUS_DCM_REG0_MASK) ==
		(unsigned int) INFRACFG_AO_PERI_BUS_DCM_REG0_ON);

	return ret;
}

void dcm_infracfg_ao_peri_bus_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'infracfg_ao_peri_bus_dcm'" */
		reg_write(PERI_BUS_DCM_CTRL,
			(reg_read(PERI_BUS_DCM_CTRL) &
			~INFRACFG_AO_PERI_BUS_DCM_REG0_MASK) |
			INFRACFG_AO_PERI_BUS_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'infracfg_ao_peri_bus_dcm'" */
		reg_write(PERI_BUS_DCM_CTRL,
			(reg_read(PERI_BUS_DCM_CTRL) &
			~INFRACFG_AO_PERI_BUS_DCM_REG0_MASK) |
			INFRACFG_AO_PERI_BUS_DCM_REG0_OFF);
	}
}

#define INFRACFG_AO_PERI_MODULE_DCM_REG0_MASK ((0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define INFRACFG_AO_PERI_MODULE_DCM_REG0_ON ((0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define INFRACFG_AO_PERI_MODULE_DCM_REG0_OFF ((0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))

bool dcm_infracfg_ao_peri_module_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(PERI_BUS_DCM_CTRL) &
		INFRACFG_AO_PERI_MODULE_DCM_REG0_MASK) ==
		(unsigned int) INFRACFG_AO_PERI_MODULE_DCM_REG0_ON);

	return ret;
}

void dcm_infracfg_ao_peri_module_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'infracfg_ao_peri_module_dcm'" */
		reg_write(PERI_BUS_DCM_CTRL,
			(reg_read(PERI_BUS_DCM_CTRL) &
			~INFRACFG_AO_PERI_MODULE_DCM_REG0_MASK) |
			INFRACFG_AO_PERI_MODULE_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'infracfg_ao_peri_module_dcm'" */
		reg_write(PERI_BUS_DCM_CTRL,
			(reg_read(PERI_BUS_DCM_CTRL) &
			~INFRACFG_AO_PERI_MODULE_DCM_REG0_MASK) |
			INFRACFG_AO_PERI_MODULE_DCM_REG0_OFF);
	}
}

bool dcm_pwrap_pmic_wrap_is_on(void)
{
	bool ret = true;

	return ret;
}

void dcm_pwrap_pmic_wrap(int on)
{
}

#define EMI_DCM_EMI_GROUP_REG0_MASK ((0xff << 24))
#define EMI_DCM_EMI_GROUP_REG1_MASK ((0xff << 24))
#define EMI_DCM_EMI_GROUP_REG0_ON ((0x0 << 24))
#define EMI_DCM_EMI_GROUP_REG1_ON ((0x0 << 24))
#define EMI_DCM_EMI_GROUP_REG0_OFF ((0xff << 24))
#define EMI_DCM_EMI_GROUP_REG1_OFF ((0xff << 24))

bool dcm_emi_dcm_emi_group_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(EMI_CONM) &
		EMI_DCM_EMI_GROUP_REG0_MASK) ==
		(unsigned int) EMI_DCM_EMI_GROUP_REG0_ON);
	ret &= ((reg_read(EMI_CONN) &
		EMI_DCM_EMI_GROUP_REG1_MASK) ==
		(unsigned int) EMI_DCM_EMI_GROUP_REG1_ON);

	return ret;
}

void dcm_emi_dcm_emi_group(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'emi_dcm_emi_group'" */
		reg_write(EMI_CONM,
			(reg_read(EMI_CONM) &
			~EMI_DCM_EMI_GROUP_REG0_MASK) |
			EMI_DCM_EMI_GROUP_REG0_ON);
		reg_write(EMI_CONN,
			(reg_read(EMI_CONN) &
			~EMI_DCM_EMI_GROUP_REG1_MASK) |
			EMI_DCM_EMI_GROUP_REG1_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'emi_dcm_emi_group'" */
		reg_write(EMI_CONM,
			(reg_read(EMI_CONM) &
			~EMI_DCM_EMI_GROUP_REG0_MASK) |
			EMI_DCM_EMI_GROUP_REG0_OFF);
		reg_write(EMI_CONN,
			(reg_read(EMI_CONN) &
			~EMI_DCM_EMI_GROUP_REG1_MASK) |
			EMI_DCM_EMI_GROUP_REG1_OFF);
	}
}

#define DRAMC_CH0_TOP0_DDRPHY_REG0_MASK ((0x1 << 9) | \
			(0x1 << 10) | \
			(0x1 << 11) | \
			(0x1 << 12) | \
			(0x1 << 13) | \
			(0x1 << 14) | \
			(0x1 << 15) | \
			(0x1 << 16) | \
			(0x1 << 17) | \
			(0x1 << 19))
#define DRAMC_CH0_TOP0_DDRPHY_REG1_MASK ((0x1 << 6) | \
			(0x1 << 7) | \
			(0x1f << 21) | \
			(0x1 << 26))
#define DRAMC_CH0_TOP0_DDRPHY_REG2_MASK ((0x1 << 26) | \
			(0x1 << 27))
#define DRAMC_CH0_TOP0_DDRPHY_REG3_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG4_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG5_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG6_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG7_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG8_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG9_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG10_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG11_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG12_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG13_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG14_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG0_ON ((0x0 << 9) | \
			(0x0 << 10) | \
			(0x0 << 11) | \
			(0x0 << 12) | \
			(0x0 << 13) | \
			(0x0 << 14) | \
			(0x0 << 15) | \
			(0x0 << 16) | \
			(0x0 << 17) | \
			(0x0 << 19))
#define DRAMC_CH0_TOP0_DDRPHY_REG1_ON ((0x0 << 6) | \
			(0x0 << 7) | \
			(0x8 << 21) | \
			(0x0 << 26))
#define DRAMC_CH0_TOP0_DDRPHY_REG2_ON ((0x0 << 26) | \
			(0x0 << 27))
#define DRAMC_CH0_TOP0_DDRPHY_REG3_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG4_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG5_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG6_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG7_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG8_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG9_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG10_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG11_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG12_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG13_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG14_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG0_OFF ((0x1 << 9) | \
			(0x1 << 10) | \
			(0x1 << 11) | \
			(0x1 << 12) | \
			(0x1 << 13) | \
			(0x1 << 14) | \
			(0x1 << 15) | \
			(0x1 << 16) | \
			(0x1 << 17) | \
			(0x1 << 19))
#define DRAMC_CH0_TOP0_DDRPHY_REG1_OFF ((0x1 << 6) | \
			(0x1 << 7) | \
			(0x0 << 21) | \
			(0x0 << 26))
#define DRAMC_CH0_TOP0_DDRPHY_REG2_OFF ((0x1 << 26) | \
			(0x1 << 27))
#define DRAMC_CH0_TOP0_DDRPHY_REG3_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG4_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG5_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG6_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG7_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG8_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG9_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG10_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG11_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG12_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG13_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP0_DDRPHY_REG14_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))

bool dcm_dramc_ch0_top0_ddrphy_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(DRAMC_CH0_TOP0_MISC_CG_CTRL0) &
		DRAMC_CH0_TOP0_DDRPHY_REG0_MASK) ==
		(unsigned int) DRAMC_CH0_TOP0_DDRPHY_REG0_ON);
	ret &= ((reg_read(DRAMC_CH0_TOP0_MISC_CG_CTRL2) &
		DRAMC_CH0_TOP0_DDRPHY_REG1_MASK) ==
		(unsigned int) DRAMC_CH0_TOP0_DDRPHY_REG1_ON);
	ret &= ((reg_read(DRAMC_CH0_TOP0_MISC_CTRL3) &
		DRAMC_CH0_TOP0_DDRPHY_REG2_MASK) ==
		(unsigned int) DRAMC_CH0_TOP0_DDRPHY_REG2_ON);
	ret &= ((reg_read(DRAMC_CH0_TOP0_SHU1_B0_DQ8) &
		DRAMC_CH0_TOP0_DDRPHY_REG3_MASK) ==
		(unsigned int) DRAMC_CH0_TOP0_DDRPHY_REG3_ON);
	ret &= ((reg_read(DRAMC_CH0_TOP0_SHU1_B1_DQ8) &
		DRAMC_CH0_TOP0_DDRPHY_REG4_MASK) ==
		(unsigned int) DRAMC_CH0_TOP0_DDRPHY_REG4_ON);
	ret &= ((reg_read(DRAMC_CH0_TOP0_SHU1_CA_CMD8) &
		DRAMC_CH0_TOP0_DDRPHY_REG5_MASK) ==
		(unsigned int) DRAMC_CH0_TOP0_DDRPHY_REG5_ON);
	ret &= ((reg_read(DRAMC_CH0_TOP0_SHU2_B0_DQ8) &
		DRAMC_CH0_TOP0_DDRPHY_REG6_MASK) ==
		(unsigned int) DRAMC_CH0_TOP0_DDRPHY_REG6_ON);
	ret &= ((reg_read(DRAMC_CH0_TOP0_SHU2_B1_DQ8) &
		DRAMC_CH0_TOP0_DDRPHY_REG7_MASK) ==
		(unsigned int) DRAMC_CH0_TOP0_DDRPHY_REG7_ON);
	ret &= ((reg_read(DRAMC_CH0_TOP0_SHU2_CA_CMD8) &
		DRAMC_CH0_TOP0_DDRPHY_REG8_MASK) ==
		(unsigned int) DRAMC_CH0_TOP0_DDRPHY_REG8_ON);
	ret &= ((reg_read(DRAMC_CH0_TOP0_SHU3_B0_DQ8) &
		DRAMC_CH0_TOP0_DDRPHY_REG9_MASK) ==
		(unsigned int) DRAMC_CH0_TOP0_DDRPHY_REG9_ON);
	ret &= ((reg_read(DRAMC_CH0_TOP0_SHU3_B1_DQ8) &
		DRAMC_CH0_TOP0_DDRPHY_REG10_MASK) ==
		(unsigned int) DRAMC_CH0_TOP0_DDRPHY_REG10_ON);
	ret &= ((reg_read(DRAMC_CH0_TOP0_SHU3_CA_CMD8) &
		DRAMC_CH0_TOP0_DDRPHY_REG11_MASK) ==
		(unsigned int) DRAMC_CH0_TOP0_DDRPHY_REG11_ON);
	ret &= ((reg_read(DRAMC_CH0_TOP0_SHU4_B0_DQ8) &
		DRAMC_CH0_TOP0_DDRPHY_REG12_MASK) ==
		(unsigned int) DRAMC_CH0_TOP0_DDRPHY_REG12_ON);
	ret &= ((reg_read(DRAMC_CH0_TOP0_SHU4_B1_DQ8) &
		DRAMC_CH0_TOP0_DDRPHY_REG13_MASK) ==
		(unsigned int) DRAMC_CH0_TOP0_DDRPHY_REG13_ON);
	ret &= ((reg_read(DRAMC_CH0_TOP0_SHU4_CA_CMD8) &
		DRAMC_CH0_TOP0_DDRPHY_REG14_MASK) ==
		(unsigned int) DRAMC_CH0_TOP0_DDRPHY_REG14_ON);

	return ret;
}

void dcm_dramc_ch0_top0_ddrphy(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'dramc_ch0_top0_ddrphy'" */
		reg_write(DRAMC_CH0_TOP0_MISC_CG_CTRL0,
			(reg_read(DRAMC_CH0_TOP0_MISC_CG_CTRL0) &
			~DRAMC_CH0_TOP0_DDRPHY_REG0_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG0_ON);
		reg_write(DRAMC_CH0_TOP0_MISC_CG_CTRL2,
			(reg_read(DRAMC_CH0_TOP0_MISC_CG_CTRL2) &
			~DRAMC_CH0_TOP0_DDRPHY_REG1_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG1_ON);
		reg_write(DRAMC_CH0_TOP0_MISC_CTRL3,
			(reg_read(DRAMC_CH0_TOP0_MISC_CTRL3) &
			~DRAMC_CH0_TOP0_DDRPHY_REG2_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG2_ON);
		reg_write(DRAMC_CH0_TOP0_SHU1_B0_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU1_B0_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG3_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG3_ON);
		reg_write(DRAMC_CH0_TOP0_SHU1_B1_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU1_B1_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG4_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG4_ON);
		reg_write(DRAMC_CH0_TOP0_SHU1_CA_CMD8,
			(reg_read(DRAMC_CH0_TOP0_SHU1_CA_CMD8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG5_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG5_ON);
		reg_write(DRAMC_CH0_TOP0_SHU2_B0_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU2_B0_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG6_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG6_ON);
		reg_write(DRAMC_CH0_TOP0_SHU2_B1_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU2_B1_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG7_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG7_ON);
		reg_write(DRAMC_CH0_TOP0_SHU2_CA_CMD8,
			(reg_read(DRAMC_CH0_TOP0_SHU2_CA_CMD8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG8_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG8_ON);
		reg_write(DRAMC_CH0_TOP0_SHU3_B0_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU3_B0_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG9_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG9_ON);
		reg_write(DRAMC_CH0_TOP0_SHU3_B1_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU3_B1_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG10_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG10_ON);
		reg_write(DRAMC_CH0_TOP0_SHU3_CA_CMD8,
			(reg_read(DRAMC_CH0_TOP0_SHU3_CA_CMD8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG11_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG11_ON);
		reg_write(DRAMC_CH0_TOP0_SHU4_B0_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU4_B0_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG12_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG12_ON);
		reg_write(DRAMC_CH0_TOP0_SHU4_B1_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU4_B1_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG13_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG13_ON);
		reg_write(DRAMC_CH0_TOP0_SHU4_CA_CMD8,
			(reg_read(DRAMC_CH0_TOP0_SHU4_CA_CMD8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG14_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG14_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'dramc_ch0_top0_ddrphy'" */
		reg_write(DRAMC_CH0_TOP0_MISC_CG_CTRL0,
			(reg_read(DRAMC_CH0_TOP0_MISC_CG_CTRL0) &
			~DRAMC_CH0_TOP0_DDRPHY_REG0_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG0_OFF);
		reg_write(DRAMC_CH0_TOP0_MISC_CG_CTRL2,
			(reg_read(DRAMC_CH0_TOP0_MISC_CG_CTRL2) &
			~DRAMC_CH0_TOP0_DDRPHY_REG1_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG1_OFF);
		reg_write(DRAMC_CH0_TOP0_MISC_CTRL3,
			(reg_read(DRAMC_CH0_TOP0_MISC_CTRL3) &
			~DRAMC_CH0_TOP0_DDRPHY_REG2_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG2_OFF);
		reg_write(DRAMC_CH0_TOP0_SHU1_B0_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU1_B0_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG3_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG3_OFF);
		reg_write(DRAMC_CH0_TOP0_SHU1_B1_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU1_B1_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG4_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG4_OFF);
		reg_write(DRAMC_CH0_TOP0_SHU1_CA_CMD8,
			(reg_read(DRAMC_CH0_TOP0_SHU1_CA_CMD8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG5_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG5_OFF);
		reg_write(DRAMC_CH0_TOP0_SHU2_B0_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU2_B0_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG6_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG6_OFF);
		reg_write(DRAMC_CH0_TOP0_SHU2_B1_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU2_B1_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG7_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG7_OFF);
		reg_write(DRAMC_CH0_TOP0_SHU2_CA_CMD8,
			(reg_read(DRAMC_CH0_TOP0_SHU2_CA_CMD8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG8_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG8_OFF);
		reg_write(DRAMC_CH0_TOP0_SHU3_B0_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU3_B0_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG9_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG9_OFF);
		reg_write(DRAMC_CH0_TOP0_SHU3_B1_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU3_B1_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG10_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG10_OFF);
		reg_write(DRAMC_CH0_TOP0_SHU3_CA_CMD8,
			(reg_read(DRAMC_CH0_TOP0_SHU3_CA_CMD8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG11_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG11_OFF);
		reg_write(DRAMC_CH0_TOP0_SHU4_B0_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU4_B0_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG12_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG12_OFF);
		reg_write(DRAMC_CH0_TOP0_SHU4_B1_DQ8,
			(reg_read(DRAMC_CH0_TOP0_SHU4_B1_DQ8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG13_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG13_OFF);
		reg_write(DRAMC_CH0_TOP0_SHU4_CA_CMD8,
			(reg_read(DRAMC_CH0_TOP0_SHU4_CA_CMD8) &
			~DRAMC_CH0_TOP0_DDRPHY_REG14_MASK) |
			DRAMC_CH0_TOP0_DDRPHY_REG14_OFF);
	}
}

#define DRAMC_CH0_TOP1_DRAMC_DCM_REG0_MASK ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x1 << 2) | \
			(0x1 << 26) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP1_DRAMC_DCM_REG1_MASK ((0x1 << 31))
#define DRAMC_CH0_TOP1_DRAMC_DCM_REG0_ON ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x1 << 2) | \
			(0x0 << 26) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH0_TOP1_DRAMC_DCM_REG1_ON ((0x1 << 31))
#define DRAMC_CH0_TOP1_DRAMC_DCM_REG0_OFF ((0x0 << 0) | \
			(0x0 << 1) | \
			(0x0 << 2) | \
			(0x1 << 26) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH0_TOP1_DRAMC_DCM_REG1_OFF ((0x0 << 31))

bool dcm_dramc_ch0_top1_dramc_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(DRAMC_CH0_TOP1_DRAMC_PD_CTRL) &
		DRAMC_CH0_TOP1_DRAMC_DCM_REG0_MASK) ==
		(unsigned int) DRAMC_CH0_TOP1_DRAMC_DCM_REG0_ON);
	ret &= ((reg_read(DRAMC_CH0_TOP1_CLKAR) &
		DRAMC_CH0_TOP1_DRAMC_DCM_REG1_MASK) ==
		(unsigned int) DRAMC_CH0_TOP1_DRAMC_DCM_REG1_ON);

	return ret;
}

void dcm_dramc_ch0_top1_dramc_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'dramc_ch0_top1_dramc_dcm'" */
		reg_write(DRAMC_CH0_TOP1_DRAMC_PD_CTRL,
			(reg_read(DRAMC_CH0_TOP1_DRAMC_PD_CTRL) &
			~DRAMC_CH0_TOP1_DRAMC_DCM_REG0_MASK) |
			DRAMC_CH0_TOP1_DRAMC_DCM_REG0_ON);
		reg_write(DRAMC_CH0_TOP1_CLKAR,
			(reg_read(DRAMC_CH0_TOP1_CLKAR) &
			~DRAMC_CH0_TOP1_DRAMC_DCM_REG1_MASK) |
			DRAMC_CH0_TOP1_DRAMC_DCM_REG1_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'dramc_ch0_top1_dramc_dcm'" */
		reg_write(DRAMC_CH0_TOP1_DRAMC_PD_CTRL,
			(reg_read(DRAMC_CH0_TOP1_DRAMC_PD_CTRL) &
			~DRAMC_CH0_TOP1_DRAMC_DCM_REG0_MASK) |
			DRAMC_CH0_TOP1_DRAMC_DCM_REG0_OFF);
		reg_write(DRAMC_CH0_TOP1_CLKAR,
			(reg_read(DRAMC_CH0_TOP1_CLKAR) &
			~DRAMC_CH0_TOP1_DRAMC_DCM_REG1_MASK) |
			DRAMC_CH0_TOP1_DRAMC_DCM_REG1_OFF);
	}
}

#define CHN0_EMI_DCM_EMI_GROUP_REG0_MASK ((0xff << 24))
#define CHN0_EMI_DCM_EMI_GROUP_REG0_ON ((0x0 << 24))
#define CHN0_EMI_DCM_EMI_GROUP_REG0_OFF ((0xff << 24))

bool dcm_chn0_emi_dcm_emi_group_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(CHN0_EMI_CHN_EMI_CONB) &
		CHN0_EMI_DCM_EMI_GROUP_REG0_MASK) ==
		(unsigned int) CHN0_EMI_DCM_EMI_GROUP_REG0_ON);

	return ret;
}

void dcm_chn0_emi_dcm_emi_group(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'chn0_emi_dcm_emi_group'" */
		reg_write(CHN0_EMI_CHN_EMI_CONB,
			(reg_read(CHN0_EMI_CHN_EMI_CONB) &
			~CHN0_EMI_DCM_EMI_GROUP_REG0_MASK) |
			CHN0_EMI_DCM_EMI_GROUP_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'chn0_emi_dcm_emi_group'" */
		reg_write(CHN0_EMI_CHN_EMI_CONB,
			(reg_read(CHN0_EMI_CHN_EMI_CONB) &
			~CHN0_EMI_DCM_EMI_GROUP_REG0_MASK) |
			CHN0_EMI_DCM_EMI_GROUP_REG0_OFF);
	}
}

#define DRAMC_CH1_TOP0_DDRPHY_REG0_MASK ((0x1 << 9) | \
			(0x1 << 10) | \
			(0x1 << 11) | \
			(0x1 << 12) | \
			(0x1 << 13) | \
			(0x1 << 14) | \
			(0x1 << 15) | \
			(0x1 << 16) | \
			(0x1 << 17) | \
			(0x1 << 19))
#define DRAMC_CH1_TOP0_DDRPHY_REG1_MASK ((0x1 << 6) | \
			(0x1 << 7) | \
			(0x1f << 21) | \
			(0x1 << 26))
#define DRAMC_CH1_TOP0_DDRPHY_REG2_MASK ((0x1 << 26) | \
			(0x1 << 27))
#define DRAMC_CH1_TOP0_DDRPHY_REG3_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG4_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG5_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG6_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG7_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG8_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG9_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG10_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG11_MASK ((0xf << 0))
#define DRAMC_CH1_TOP0_DDRPHY_REG12_MASK ((0x1 << 20) | \
			(0x1 << 21) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG13_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG14_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG15_MASK ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG0_ON ((0x0 << 9) | \
			(0x0 << 10) | \
			(0x0 << 11) | \
			(0x0 << 12) | \
			(0x0 << 13) | \
			(0x0 << 14) | \
			(0x0 << 15) | \
			(0x0 << 16) | \
			(0x0 << 17) | \
			(0x0 << 19))
#define DRAMC_CH1_TOP0_DDRPHY_REG1_ON ((0x0 << 6) | \
			(0x0 << 7) | \
			(0x8 << 21) | \
			(0x0 << 26))
#define DRAMC_CH1_TOP0_DDRPHY_REG2_ON ((0x0 << 26) | \
			(0x0 << 27))
#define DRAMC_CH1_TOP0_DDRPHY_REG3_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG4_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG5_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG6_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG7_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG8_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG9_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG10_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG11_ON ((0x0 << 0))
#define DRAMC_CH1_TOP0_DDRPHY_REG12_ON ((0x0 << 20) | \
			(0x0 << 21) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG13_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG14_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG15_ON ((0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG0_OFF ((0x1 << 9) | \
			(0x1 << 10) | \
			(0x1 << 11) | \
			(0x1 << 12) | \
			(0x1 << 13) | \
			(0x1 << 14) | \
			(0x1 << 15) | \
			(0x1 << 16) | \
			(0x1 << 17) | \
			(0x1 << 19))
#define DRAMC_CH1_TOP0_DDRPHY_REG1_OFF ((0x1 << 6) | \
			(0x1 << 7) | \
			(0x0 << 21) | \
			(0x0 << 26))
#define DRAMC_CH1_TOP0_DDRPHY_REG2_OFF ((0x1 << 26) | \
			(0x1 << 27))
#define DRAMC_CH1_TOP0_DDRPHY_REG3_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG4_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG5_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG6_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG7_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG8_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG9_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG10_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG11_OFF ((0x1 << 0))
#define DRAMC_CH1_TOP0_DDRPHY_REG12_OFF ((0x1 << 20) | \
			(0x1 << 21) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG13_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG14_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP0_DDRPHY_REG15_OFF ((0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 30) | \
			(0x1 << 31))

bool dcm_dramc_ch1_top0_ddrphy_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(DRAMC_CH1_TOP0_MISC_CG_CTRL0) &
		DRAMC_CH1_TOP0_DDRPHY_REG0_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG0_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP0_MISC_CG_CTRL2) &
		DRAMC_CH1_TOP0_DDRPHY_REG1_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG1_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP0_MISC_CTRL3) &
		DRAMC_CH1_TOP0_DDRPHY_REG2_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG2_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP0_SHU1_B0_DQ8) &
		DRAMC_CH1_TOP0_DDRPHY_REG3_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG3_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP0_SHU1_B1_DQ8) &
		DRAMC_CH1_TOP0_DDRPHY_REG4_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG4_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP0_SHU1_CA_CMD8) &
		DRAMC_CH1_TOP0_DDRPHY_REG5_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG5_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP0_SHU2_B0_DQ8) &
		DRAMC_CH1_TOP0_DDRPHY_REG6_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG6_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP0_SHU2_B1_DQ8) &
		DRAMC_CH1_TOP0_DDRPHY_REG7_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG7_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP0_SHU2_CA_CMD8) &
		DRAMC_CH1_TOP0_DDRPHY_REG8_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG8_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP0_SHU3_B0_DQ8) &
		DRAMC_CH1_TOP0_DDRPHY_REG9_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG9_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP0_SHU3_B1_DQ8) &
		DRAMC_CH1_TOP0_DDRPHY_REG10_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG10_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP0_SHU3_CA_CMD7) &
		DRAMC_CH1_TOP0_DDRPHY_REG11_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG11_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP0_SHU3_CA_CMD8) &
		DRAMC_CH1_TOP0_DDRPHY_REG12_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG12_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP0_SHU4_B0_DQ8) &
		DRAMC_CH1_TOP0_DDRPHY_REG13_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG13_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP0_SHU4_B1_DQ8) &
		DRAMC_CH1_TOP0_DDRPHY_REG14_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG14_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP0_SHU4_CA_CMD8) &
		DRAMC_CH1_TOP0_DDRPHY_REG15_MASK) ==
		(unsigned int) DRAMC_CH1_TOP0_DDRPHY_REG15_ON);

	return ret;
}

void dcm_dramc_ch1_top0_ddrphy(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'dramc_ch1_top0_ddrphy'" */
		reg_write(DRAMC_CH1_TOP0_MISC_CG_CTRL0,
			(reg_read(DRAMC_CH1_TOP0_MISC_CG_CTRL0) &
			~DRAMC_CH1_TOP0_DDRPHY_REG0_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG0_ON);
		reg_write(DRAMC_CH1_TOP0_MISC_CG_CTRL2,
			(reg_read(DRAMC_CH1_TOP0_MISC_CG_CTRL2) &
			~DRAMC_CH1_TOP0_DDRPHY_REG1_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG1_ON);
		reg_write(DRAMC_CH1_TOP0_MISC_CTRL3,
			(reg_read(DRAMC_CH1_TOP0_MISC_CTRL3) &
			~DRAMC_CH1_TOP0_DDRPHY_REG2_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG2_ON);
		reg_write(DRAMC_CH1_TOP0_SHU1_B0_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU1_B0_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG3_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG3_ON);
		reg_write(DRAMC_CH1_TOP0_SHU1_B1_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU1_B1_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG4_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG4_ON);
		reg_write(DRAMC_CH1_TOP0_SHU1_CA_CMD8,
			(reg_read(DRAMC_CH1_TOP0_SHU1_CA_CMD8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG5_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG5_ON);
		reg_write(DRAMC_CH1_TOP0_SHU2_B0_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU2_B0_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG6_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG6_ON);
		reg_write(DRAMC_CH1_TOP0_SHU2_B1_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU2_B1_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG7_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG7_ON);
		reg_write(DRAMC_CH1_TOP0_SHU2_CA_CMD8,
			(reg_read(DRAMC_CH1_TOP0_SHU2_CA_CMD8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG8_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG8_ON);
		reg_write(DRAMC_CH1_TOP0_SHU3_B0_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU3_B0_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG9_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG9_ON);
		reg_write(DRAMC_CH1_TOP0_SHU3_B1_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU3_B1_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG10_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG10_ON);
		reg_write(DRAMC_CH1_TOP0_SHU3_CA_CMD7,
			(reg_read(DRAMC_CH1_TOP0_SHU3_CA_CMD7) &
			~DRAMC_CH1_TOP0_DDRPHY_REG11_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG11_ON);
		reg_write(DRAMC_CH1_TOP0_SHU3_CA_CMD8,
			(reg_read(DRAMC_CH1_TOP0_SHU3_CA_CMD8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG12_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG12_ON);
		reg_write(DRAMC_CH1_TOP0_SHU4_B0_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU4_B0_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG13_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG13_ON);
		reg_write(DRAMC_CH1_TOP0_SHU4_B1_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU4_B1_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG14_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG14_ON);
		reg_write(DRAMC_CH1_TOP0_SHU4_CA_CMD8,
			(reg_read(DRAMC_CH1_TOP0_SHU4_CA_CMD8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG15_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG15_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'dramc_ch1_top0_ddrphy'" */
		reg_write(DRAMC_CH1_TOP0_MISC_CG_CTRL0,
			(reg_read(DRAMC_CH1_TOP0_MISC_CG_CTRL0) &
			~DRAMC_CH1_TOP0_DDRPHY_REG0_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG0_OFF);
		reg_write(DRAMC_CH1_TOP0_MISC_CG_CTRL2,
			(reg_read(DRAMC_CH1_TOP0_MISC_CG_CTRL2) &
			~DRAMC_CH1_TOP0_DDRPHY_REG1_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG1_OFF);
		reg_write(DRAMC_CH1_TOP0_MISC_CTRL3,
			(reg_read(DRAMC_CH1_TOP0_MISC_CTRL3) &
			~DRAMC_CH1_TOP0_DDRPHY_REG2_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG2_OFF);
		reg_write(DRAMC_CH1_TOP0_SHU1_B0_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU1_B0_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG3_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG3_OFF);
		reg_write(DRAMC_CH1_TOP0_SHU1_B1_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU1_B1_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG4_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG4_OFF);
		reg_write(DRAMC_CH1_TOP0_SHU1_CA_CMD8,
			(reg_read(DRAMC_CH1_TOP0_SHU1_CA_CMD8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG5_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG5_OFF);
		reg_write(DRAMC_CH1_TOP0_SHU2_B0_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU2_B0_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG6_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG6_OFF);
		reg_write(DRAMC_CH1_TOP0_SHU2_B1_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU2_B1_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG7_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG7_OFF);
		reg_write(DRAMC_CH1_TOP0_SHU2_CA_CMD8,
			(reg_read(DRAMC_CH1_TOP0_SHU2_CA_CMD8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG8_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG8_OFF);
		reg_write(DRAMC_CH1_TOP0_SHU3_B0_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU3_B0_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG9_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG9_OFF);
		reg_write(DRAMC_CH1_TOP0_SHU3_B1_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU3_B1_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG10_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG10_OFF);
		reg_write(DRAMC_CH1_TOP0_SHU3_CA_CMD7,
			(reg_read(DRAMC_CH1_TOP0_SHU3_CA_CMD7) &
			~DRAMC_CH1_TOP0_DDRPHY_REG11_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG11_OFF);
		reg_write(DRAMC_CH1_TOP0_SHU3_CA_CMD8,
			(reg_read(DRAMC_CH1_TOP0_SHU3_CA_CMD8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG12_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG12_OFF);
		reg_write(DRAMC_CH1_TOP0_SHU4_B0_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU4_B0_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG13_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG13_OFF);
		reg_write(DRAMC_CH1_TOP0_SHU4_B1_DQ8,
			(reg_read(DRAMC_CH1_TOP0_SHU4_B1_DQ8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG14_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG14_OFF);
		reg_write(DRAMC_CH1_TOP0_SHU4_CA_CMD8,
			(reg_read(DRAMC_CH1_TOP0_SHU4_CA_CMD8) &
			~DRAMC_CH1_TOP0_DDRPHY_REG15_MASK) |
			DRAMC_CH1_TOP0_DDRPHY_REG15_OFF);
	}
}

#define DRAMC_CH1_TOP1_DRAMC_DCM_REG0_MASK ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x1 << 2) | \
			(0x1 << 26) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP1_DRAMC_DCM_REG1_MASK ((0x1 << 31))
#define DRAMC_CH1_TOP1_DRAMC_DCM_REG0_ON ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x1 << 2) | \
			(0x0 << 26) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_CH1_TOP1_DRAMC_DCM_REG1_ON ((0x1 << 31))
#define DRAMC_CH1_TOP1_DRAMC_DCM_REG0_OFF ((0x0 << 0) | \
			(0x0 << 1) | \
			(0x0 << 2) | \
			(0x1 << 26) | \
			(0x0 << 30) | \
			(0x0 << 31))
#define DRAMC_CH1_TOP1_DRAMC_DCM_REG1_OFF ((0x0 << 31))

bool dcm_dramc_ch1_top1_dramc_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(DRAMC_CH1_TOP1_DRAMC_PD_CTRL) &
		DRAMC_CH1_TOP1_DRAMC_DCM_REG0_MASK) ==
		(unsigned int) DRAMC_CH1_TOP1_DRAMC_DCM_REG0_ON);
	ret &= ((reg_read(DRAMC_CH1_TOP1_CLKAR) &
		DRAMC_CH1_TOP1_DRAMC_DCM_REG1_MASK) ==
		(unsigned int) DRAMC_CH1_TOP1_DRAMC_DCM_REG1_ON);

	return ret;
}

void dcm_dramc_ch1_top1_dramc_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'dramc_ch1_top1_dramc_dcm'" */
		reg_write(DRAMC_CH1_TOP1_DRAMC_PD_CTRL,
			(reg_read(DRAMC_CH1_TOP1_DRAMC_PD_CTRL) &
			~DRAMC_CH1_TOP1_DRAMC_DCM_REG0_MASK) |
			DRAMC_CH1_TOP1_DRAMC_DCM_REG0_ON);
		reg_write(DRAMC_CH1_TOP1_CLKAR,
			(reg_read(DRAMC_CH1_TOP1_CLKAR) &
			~DRAMC_CH1_TOP1_DRAMC_DCM_REG1_MASK) |
			DRAMC_CH1_TOP1_DRAMC_DCM_REG1_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'dramc_ch1_top1_dramc_dcm'" */
		reg_write(DRAMC_CH1_TOP1_DRAMC_PD_CTRL,
			(reg_read(DRAMC_CH1_TOP1_DRAMC_PD_CTRL) &
			~DRAMC_CH1_TOP1_DRAMC_DCM_REG0_MASK) |
			DRAMC_CH1_TOP1_DRAMC_DCM_REG0_OFF);
		reg_write(DRAMC_CH1_TOP1_CLKAR,
			(reg_read(DRAMC_CH1_TOP1_CLKAR) &
			~DRAMC_CH1_TOP1_DRAMC_DCM_REG1_MASK) |
			DRAMC_CH1_TOP1_DRAMC_DCM_REG1_OFF);
	}
}

#define CHN1_EMI_DCM_EMI_GROUP_REG0_MASK ((0xff << 24))
#define CHN1_EMI_DCM_EMI_GROUP_REG0_ON ((0x0 << 24))
#define CHN1_EMI_DCM_EMI_GROUP_REG0_OFF ((0xff << 24))

bool dcm_chn1_emi_dcm_emi_group_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(CHN1_EMI_CHN_EMI_CONB) &
		CHN1_EMI_DCM_EMI_GROUP_REG0_MASK) ==
		(unsigned int) CHN1_EMI_DCM_EMI_GROUP_REG0_ON);

	return ret;
}

void dcm_chn1_emi_dcm_emi_group(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'chn1_emi_dcm_emi_group'" */
		reg_write(CHN1_EMI_CHN_EMI_CONB,
			(reg_read(CHN1_EMI_CHN_EMI_CONB) &
			~CHN1_EMI_DCM_EMI_GROUP_REG0_MASK) |
			CHN1_EMI_DCM_EMI_GROUP_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'chn1_emi_dcm_emi_group'" */
		reg_write(CHN1_EMI_CHN_EMI_CONB,
			(reg_read(CHN1_EMI_CHN_EMI_CONB) &
			~CHN1_EMI_DCM_EMI_GROUP_REG0_MASK) |
			CHN1_EMI_DCM_EMI_GROUP_REG0_OFF);
	}
}

#define MP0_CPUCFG_MP0_RGU_DCM_REG0_MASK ((0x1 << 0))
#define MP0_CPUCFG_MP0_RGU_DCM_REG0_ON ((0x1 << 0))
#define MP0_CPUCFG_MP0_RGU_DCM_REG0_OFF ((0x0 << 0))

bool dcm_mp0_cpucfg_mp0_rgu_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(CPUSYS_RGU_SYNC_DCM) &
		MP0_CPUCFG_MP0_RGU_DCM_REG0_MASK) ==
		(unsigned int) MP0_CPUCFG_MP0_RGU_DCM_REG0_ON);

	return ret;
}

void dcm_mp0_cpucfg_mp0_rgu_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mp0_cpucfg_mp0_rgu_dcm'" */
		reg_write(CPUSYS_RGU_SYNC_DCM,
			(reg_read(CPUSYS_RGU_SYNC_DCM) &
			~MP0_CPUCFG_MP0_RGU_DCM_REG0_MASK) |
			MP0_CPUCFG_MP0_RGU_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mp0_cpucfg_mp0_rgu_dcm'" */
		reg_write(CPUSYS_RGU_SYNC_DCM,
			(reg_read(CPUSYS_RGU_SYNC_DCM) &
			~MP0_CPUCFG_MP0_RGU_DCM_REG0_MASK) |
			MP0_CPUCFG_MP0_RGU_DCM_REG0_OFF);
	}
}

#define MCU_MISCCFG_ADB400_DCM_REG0_MASK ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x1 << 2) | \
			(0x1 << 3) | \
			(0x1 << 4) | \
			(0x1 << 5) | \
			(0x1 << 6) | \
			(0x1 << 11))
#define MCU_MISCCFG_ADB400_DCM_REG0_ON ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x1 << 2) | \
			(0x1 << 3) | \
			(0x1 << 4) | \
			(0x1 << 5) | \
			(0x1 << 6) | \
			(0x1 << 11))
#define MCU_MISCCFG_ADB400_DCM_REG0_OFF ((0x0 << 0) | \
			(0x0 << 1) | \
			(0x0 << 2) | \
			(0x0 << 3) | \
			(0x0 << 4) | \
			(0x0 << 5) | \
			(0x0 << 6) | \
			(0x0 << 11))

bool dcm_mcu_misccfg_adb400_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(CCI_ADB400_DCM_CONFIG) &
		MCU_MISCCFG_ADB400_DCM_REG0_MASK) ==
		(unsigned int) MCU_MISCCFG_ADB400_DCM_REG0_ON);

	return ret;
}

void dcm_mcu_misccfg_adb400_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcu_misccfg_adb400_dcm'" */
		reg_write(CCI_ADB400_DCM_CONFIG,
			(reg_read(CCI_ADB400_DCM_CONFIG) &
			~MCU_MISCCFG_ADB400_DCM_REG0_MASK) |
			MCU_MISCCFG_ADB400_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcu_misccfg_adb400_dcm'" */
		reg_write(CCI_ADB400_DCM_CONFIG,
			(reg_read(CCI_ADB400_DCM_CONFIG) &
			~MCU_MISCCFG_ADB400_DCM_REG0_MASK) |
			MCU_MISCCFG_ADB400_DCM_REG0_OFF);
	}
}

#define MCU_MISCCFG_BUS_ARM_PLL_DIVIDER_DCM_REG0_MASK ((0x1 << 11) | \
			(0x1 << 24) | \
			(0x1 << 25))
#define MCU_MISCCFG_BUS_ARM_PLL_DIVIDER_DCM_REG0_ON ((0x1 << 11) | \
			(0x1 << 24) | \
			(0x1 << 25))
#define MCU_MISCCFG_BUS_ARM_PLL_DIVIDER_DCM_REG0_OFF ((0x0 << 11) | \
			(0x0 << 24) | \
			(0x0 << 25))

bool dcm_mcu_misccfg_bus_arm_pll_divider_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(BUS_PLL_DIVIDER_CFG) &
		MCU_MISCCFG_BUS_ARM_PLL_DIVIDER_DCM_REG0_MASK) ==
		(unsigned int) MCU_MISCCFG_BUS_ARM_PLL_DIVIDER_DCM_REG0_ON);

	return ret;
}

void dcm_mcu_misccfg_bus_arm_pll_divider_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcu_misccfg_bus_arm_pll_divider_dcm'" */
		reg_write(BUS_PLL_DIVIDER_CFG,
			(reg_read(BUS_PLL_DIVIDER_CFG) &
			~MCU_MISCCFG_BUS_ARM_PLL_DIVIDER_DCM_REG0_MASK) |
			MCU_MISCCFG_BUS_ARM_PLL_DIVIDER_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcu_misccfg_bus_arm_pll_divider_dcm'" */
		reg_write(BUS_PLL_DIVIDER_CFG,
			(reg_read(BUS_PLL_DIVIDER_CFG) &
			~MCU_MISCCFG_BUS_ARM_PLL_DIVIDER_DCM_REG0_MASK) |
			MCU_MISCCFG_BUS_ARM_PLL_DIVIDER_DCM_REG0_OFF);
	}
}

#define MCU_MISCCFG_BUS_SYNC_DCM_REG0_MASK ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x7f << 2))
#define MCU_MISCCFG_BUS_SYNC_DCM_REG0_ON ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x0 << 2))
#define MCU_MISCCFG_BUS_SYNC_DCM_REG0_OFF ((0x0 << 0) | \
			(0x1 << 1) | \
			(0x0 << 2))

bool dcm_mcu_misccfg_bus_sync_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(SYNC_DCM_CONFIG) &
		MCU_MISCCFG_BUS_SYNC_DCM_REG0_MASK) ==
		(unsigned int) MCU_MISCCFG_BUS_SYNC_DCM_REG0_ON);

	return ret;
}

void dcm_mcu_misccfg_bus_sync_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcu_misccfg_bus_sync_dcm'" */
		reg_write(SYNC_DCM_CONFIG,
			(reg_read(SYNC_DCM_CONFIG) &
			~MCU_MISCCFG_BUS_SYNC_DCM_REG0_MASK) |
			MCU_MISCCFG_BUS_SYNC_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcu_misccfg_bus_sync_dcm'" */
		reg_write(SYNC_DCM_CONFIG,
			(reg_read(SYNC_DCM_CONFIG) &
			~MCU_MISCCFG_BUS_SYNC_DCM_REG0_MASK) |
			MCU_MISCCFG_BUS_SYNC_DCM_REG0_OFF);
	}
}

#define MCU_MISCCFG_BUS_CLOCK_DCM_REG0_MASK ((0x1 << 8))
#define MCU_MISCCFG_BUS_CLOCK_DCM_REG0_ON ((0x1 << 8))
#define MCU_MISCCFG_BUS_CLOCK_DCM_REG0_OFF ((0x0 << 8))

bool dcm_mcu_misccfg_bus_clock_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(CCI_CLK_CTRL) &
		MCU_MISCCFG_BUS_CLOCK_DCM_REG0_MASK) ==
		(unsigned int) MCU_MISCCFG_BUS_CLOCK_DCM_REG0_ON);

	return ret;
}

void dcm_mcu_misccfg_bus_clock_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcu_misccfg_bus_clock_dcm'" */
		reg_write(CCI_CLK_CTRL,
			(reg_read(CCI_CLK_CTRL) &
			~MCU_MISCCFG_BUS_CLOCK_DCM_REG0_MASK) |
			MCU_MISCCFG_BUS_CLOCK_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcu_misccfg_bus_clock_dcm'" */
		reg_write(CCI_CLK_CTRL,
			(reg_read(CCI_CLK_CTRL) &
			~MCU_MISCCFG_BUS_CLOCK_DCM_REG0_MASK) |
			MCU_MISCCFG_BUS_CLOCK_DCM_REG0_OFF);
	}
}

#define MCU_MISCCFG_BUS_FABRIC_DCM_REG0_MASK ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x1 << 2) | \
			(0x1 << 3) | \
			(0x1 << 4) | \
			(0x1 << 5) | \
			(0x1 << 6) | \
			(0x1 << 7) | \
			(0x1 << 8) | \
			(0x1 << 9) | \
			(0x1 << 10) | \
			(0x1 << 11) | \
			(0x1 << 12) | \
			(0x1 << 16) | \
			(0x1 << 17) | \
			(0x1 << 18) | \
			(0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 21) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29))
#define MCU_MISCCFG_BUS_FABRIC_DCM_REG0_ON ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x1 << 2) | \
			(0x1 << 3) | \
			(0x1 << 4) | \
			(0x1 << 5) | \
			(0x1 << 6) | \
			(0x1 << 7) | \
			(0x1 << 8) | \
			(0x1 << 9) | \
			(0x1 << 10) | \
			(0x1 << 11) | \
			(0x1 << 12) | \
			(0x1 << 16) | \
			(0x1 << 17) | \
			(0x1 << 18) | \
			(0x1 << 19) | \
			(0x1 << 20) | \
			(0x1 << 21) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29))
#define MCU_MISCCFG_BUS_FABRIC_DCM_REG0_OFF ((0x0 << 0) | \
			(0x0 << 1) | \
			(0x0 << 2) | \
			(0x0 << 3) | \
			(0x0 << 4) | \
			(0x0 << 5) | \
			(0x0 << 6) | \
			(0x0 << 7) | \
			(0x0 << 8) | \
			(0x0 << 9) | \
			(0x0 << 10) | \
			(0x0 << 11) | \
			(0x0 << 12) | \
			(0x0 << 16) | \
			(0x0 << 17) | \
			(0x0 << 18) | \
			(0x0 << 19) | \
			(0x0 << 20) | \
			(0x0 << 21) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 26) | \
			(0x0 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29))

bool dcm_mcu_misccfg_bus_fabric_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(BUS_FABRIC_DCM_CTRL) &
		MCU_MISCCFG_BUS_FABRIC_DCM_REG0_MASK) ==
		(unsigned int) MCU_MISCCFG_BUS_FABRIC_DCM_REG0_ON);

	return ret;
}

void dcm_mcu_misccfg_bus_fabric_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcu_misccfg_bus_fabric_dcm'" */
		reg_write(BUS_FABRIC_DCM_CTRL,
			(reg_read(BUS_FABRIC_DCM_CTRL) &
			~MCU_MISCCFG_BUS_FABRIC_DCM_REG0_MASK) |
			MCU_MISCCFG_BUS_FABRIC_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcu_misccfg_bus_fabric_dcm'" */
		reg_write(BUS_FABRIC_DCM_CTRL,
			(reg_read(BUS_FABRIC_DCM_CTRL) &
			~MCU_MISCCFG_BUS_FABRIC_DCM_REG0_MASK) |
			MCU_MISCCFG_BUS_FABRIC_DCM_REG0_OFF);
	}
}

#define MCU_MISCCFG_GIC_SYNC_DCM_REG0_MASK ((0x1 << 0) | \
			(0x1 << 1))
#define MCU_MISCCFG_GIC_SYNC_DCM_REG0_ON ((0x1 << 0) | \
			(0x1 << 1))
#define MCU_MISCCFG_GIC_SYNC_DCM_REG0_OFF ((0x0 << 0) | \
			(0x0 << 1))

bool dcm_mcu_misccfg_gic_sync_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(MP_GIC_RGU_SYNC_DCM) &
		MCU_MISCCFG_GIC_SYNC_DCM_REG0_MASK) ==
		(unsigned int) MCU_MISCCFG_GIC_SYNC_DCM_REG0_ON);

	return ret;
}

void dcm_mcu_misccfg_gic_sync_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcu_misccfg_gic_sync_dcm'" */
		reg_write(MP_GIC_RGU_SYNC_DCM,
			(reg_read(MP_GIC_RGU_SYNC_DCM) &
			~MCU_MISCCFG_GIC_SYNC_DCM_REG0_MASK) |
			MCU_MISCCFG_GIC_SYNC_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcu_misccfg_gic_sync_dcm'" */
		reg_write(MP_GIC_RGU_SYNC_DCM,
			(reg_read(MP_GIC_RGU_SYNC_DCM) &
			~MCU_MISCCFG_GIC_SYNC_DCM_REG0_MASK) |
			MCU_MISCCFG_GIC_SYNC_DCM_REG0_OFF);
	}
}

#define MCU_MISCCFG_L2_SHARED_DCM_REG0_MASK ((0x1 << 0))
#define MCU_MISCCFG_L2_SHARED_DCM_REG0_ON ((0x1 << 0))
#define MCU_MISCCFG_L2_SHARED_DCM_REG0_OFF ((0x0 << 0))

bool dcm_mcu_misccfg_l2_shared_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(L2C_SRAM_CTRL) &
		MCU_MISCCFG_L2_SHARED_DCM_REG0_MASK) ==
		(unsigned int) MCU_MISCCFG_L2_SHARED_DCM_REG0_ON);

	return ret;
}

void dcm_mcu_misccfg_l2_shared_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcu_misccfg_l2_shared_dcm'" */
		reg_write(L2C_SRAM_CTRL,
			(reg_read(L2C_SRAM_CTRL) &
			~MCU_MISCCFG_L2_SHARED_DCM_REG0_MASK) |
			MCU_MISCCFG_L2_SHARED_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcu_misccfg_l2_shared_dcm'" */
		reg_write(L2C_SRAM_CTRL,
			(reg_read(L2C_SRAM_CTRL) &
			~MCU_MISCCFG_L2_SHARED_DCM_REG0_MASK) |
			MCU_MISCCFG_L2_SHARED_DCM_REG0_OFF);
	}
}

#define MCU_MISCCFG_MP0_ARM_PLL_DIVIDER_DCM_REG0_MASK ((0x1 << 11) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 31))
#define MCU_MISCCFG_MP0_ARM_PLL_DIVIDER_DCM_REG0_ON ((0x1 << 11) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 31))
#define MCU_MISCCFG_MP0_ARM_PLL_DIVIDER_DCM_REG0_OFF ((0x0 << 11) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 31))

bool dcm_mcu_misccfg_mp0_arm_pll_divider_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(MP0_PLL_DIVIDER_CFG) &
		MCU_MISCCFG_MP0_ARM_PLL_DIVIDER_DCM_REG0_MASK) ==
		(unsigned int) MCU_MISCCFG_MP0_ARM_PLL_DIVIDER_DCM_REG0_ON);

	return ret;
}

void dcm_mcu_misccfg_mp0_arm_pll_divider_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcu_misccfg_mp0_arm_pll_divider_dcm'" */
		reg_write(MP0_PLL_DIVIDER_CFG,
			(reg_read(MP0_PLL_DIVIDER_CFG) &
			~MCU_MISCCFG_MP0_ARM_PLL_DIVIDER_DCM_REG0_MASK) |
			MCU_MISCCFG_MP0_ARM_PLL_DIVIDER_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcu_misccfg_mp0_arm_pll_divider_dcm'" */
		reg_write(MP0_PLL_DIVIDER_CFG,
			(reg_read(MP0_PLL_DIVIDER_CFG) &
			~MCU_MISCCFG_MP0_ARM_PLL_DIVIDER_DCM_REG0_MASK) |
			MCU_MISCCFG_MP0_ARM_PLL_DIVIDER_DCM_REG0_OFF);
	}
}

#define MCU_MISCCFG_MP0_SYNC_DCM_ENABLE_REG0_MASK ((0x1 << 10) | \
			(0x1 << 11) | \
			(0x7f << 12))
#define MCU_MISCCFG_MP0_SYNC_DCM_ENABLE_REG0_ON ((0x1 << 10) | \
			(0x1 << 11) | \
			(0x0 << 12))
#define MCU_MISCCFG_MP0_SYNC_DCM_ENABLE_REG0_OFF ((0x0 << 10) | \
			(0x1 << 11) | \
			(0x0 << 12))

bool dcm_mcu_misccfg_mp0_sync_dcm_enable_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(SYNC_DCM_CONFIG) &
		MCU_MISCCFG_MP0_SYNC_DCM_ENABLE_REG0_MASK) ==
		(unsigned int) MCU_MISCCFG_MP0_SYNC_DCM_ENABLE_REG0_ON);

	return ret;
}

void dcm_mcu_misccfg_mp0_sync_dcm_enable(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcu_misccfg_mp0_sync_dcm_enable'" */
		reg_write(SYNC_DCM_CONFIG,
			(reg_read(SYNC_DCM_CONFIG) &
			~MCU_MISCCFG_MP0_SYNC_DCM_ENABLE_REG0_MASK) |
			MCU_MISCCFG_MP0_SYNC_DCM_ENABLE_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcu_misccfg_mp0_sync_dcm_enable'" */
		reg_write(SYNC_DCM_CONFIG,
			(reg_read(SYNC_DCM_CONFIG) &
			~MCU_MISCCFG_MP0_SYNC_DCM_ENABLE_REG0_MASK) |
			MCU_MISCCFG_MP0_SYNC_DCM_ENABLE_REG0_OFF);
	}
}

#define MCU_MISCCFG_MP0_STALL_DCM_REG0_MASK ((0x1 << 7))
#define MCU_MISCCFG_MP0_STALL_DCM_REG0_ON ((0x1 << 7))
#define MCU_MISCCFG_MP0_STALL_DCM_REG0_OFF ((0x0 << 7))

bool dcm_mcu_misccfg_mp0_stall_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(SYNC_DCM_CLUSTER_CONFIG) &
		MCU_MISCCFG_MP0_STALL_DCM_REG0_MASK) ==
		(unsigned int) MCU_MISCCFG_MP0_STALL_DCM_REG0_ON);

	return ret;
}

void dcm_mcu_misccfg_mp0_stall_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcu_misccfg_mp0_stall_dcm'" */
		reg_write(SYNC_DCM_CLUSTER_CONFIG,
			(reg_read(SYNC_DCM_CLUSTER_CONFIG) &
			~MCU_MISCCFG_MP0_STALL_DCM_REG0_MASK) |
			MCU_MISCCFG_MP0_STALL_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcu_misccfg_mp0_stall_dcm'" */
		reg_write(SYNC_DCM_CLUSTER_CONFIG,
			(reg_read(SYNC_DCM_CLUSTER_CONFIG) &
			~MCU_MISCCFG_MP0_STALL_DCM_REG0_MASK) |
			MCU_MISCCFG_MP0_STALL_DCM_REG0_OFF);
	}
}

#define MCU_MISCCFG_MP2_ARM_PLL_DIVIDER_DCM_REG0_MASK ((0x1 << 11) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 31))
#define MCU_MISCCFG_MP2_ARM_PLL_DIVIDER_DCM_REG0_ON ((0x1 << 11) | \
			(0x1 << 24) | \
			(0x1 << 25) | \
			(0x1 << 31))
#define MCU_MISCCFG_MP2_ARM_PLL_DIVIDER_DCM_REG0_OFF ((0x0 << 11) | \
			(0x0 << 24) | \
			(0x0 << 25) | \
			(0x0 << 31))

bool dcm_mcu_misccfg_mp2_arm_pll_divider_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(MP2_PLL_DIVIDER_CFG) &
		MCU_MISCCFG_MP2_ARM_PLL_DIVIDER_DCM_REG0_MASK) ==
		(unsigned int) MCU_MISCCFG_MP2_ARM_PLL_DIVIDER_DCM_REG0_ON);

	return ret;
}

void dcm_mcu_misccfg_mp2_arm_pll_divider_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcu_misccfg_mp2_arm_pll_divider_dcm'" */
		reg_write(MP2_PLL_DIVIDER_CFG,
			(reg_read(MP2_PLL_DIVIDER_CFG) &
			~MCU_MISCCFG_MP2_ARM_PLL_DIVIDER_DCM_REG0_MASK) |
			MCU_MISCCFG_MP2_ARM_PLL_DIVIDER_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcu_misccfg_mp2_arm_pll_divider_dcm'" */
		reg_write(MP2_PLL_DIVIDER_CFG,
			(reg_read(MP2_PLL_DIVIDER_CFG) &
			~MCU_MISCCFG_MP2_ARM_PLL_DIVIDER_DCM_REG0_MASK) |
			MCU_MISCCFG_MP2_ARM_PLL_DIVIDER_DCM_REG0_OFF);
	}
}

#define MCU_MISCCFG_MP_STALL_DCM_REG0_MASK ((0xf << 24))
#define MCU_MISCCFG_MP_STALL_DCM_REG0_ON ((0x5 << 24))
#define MCU_MISCCFG_MP_STALL_DCM_REG0_OFF ((0xf << 24))

bool dcm_mcu_misccfg_mp_stall_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(SYNC_DCM_CLUSTER_CONFIG) &
		MCU_MISCCFG_MP_STALL_DCM_REG0_MASK) ==
		(unsigned int) MCU_MISCCFG_MP_STALL_DCM_REG0_ON);

	return ret;
}

void dcm_mcu_misccfg_mp_stall_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcu_misccfg_mp_stall_dcm'" */
		reg_write(SYNC_DCM_CLUSTER_CONFIG,
			(reg_read(SYNC_DCM_CLUSTER_CONFIG) &
			~MCU_MISCCFG_MP_STALL_DCM_REG0_MASK) |
			MCU_MISCCFG_MP_STALL_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcu_misccfg_mp_stall_dcm'" */
		reg_write(SYNC_DCM_CLUSTER_CONFIG,
			(reg_read(SYNC_DCM_CLUSTER_CONFIG) &
			~MCU_MISCCFG_MP_STALL_DCM_REG0_MASK) |
			MCU_MISCCFG_MP_STALL_DCM_REG0_OFF);
	}
}

#define MCU_MISCCFG_MCU_MISC_DCM_REG0_MASK ((0x1 << 0) | \
			(0x1 << 8))
#define MCU_MISCCFG_MCU_MISC_DCM_REG0_ON ((0x1 << 0) | \
			(0x1 << 8))
#define MCU_MISCCFG_MCU_MISC_DCM_REG0_OFF ((0x0 << 0) | \
			(0x0 << 8))

bool dcm_mcu_misccfg_mcu_misc_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(MCU_MISC_DCM_CTRL) &
		MCU_MISCCFG_MCU_MISC_DCM_REG0_MASK) ==
		(unsigned int) MCU_MISCCFG_MCU_MISC_DCM_REG0_ON);

	return ret;
}

void dcm_mcu_misccfg_mcu_misc_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcu_misccfg_mcu_misc_dcm'" */
		reg_write(MCU_MISC_DCM_CTRL,
			(reg_read(MCU_MISC_DCM_CTRL) &
			~MCU_MISCCFG_MCU_MISC_DCM_REG0_MASK) |
			MCU_MISCCFG_MCU_MISC_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcu_misccfg_mcu_misc_dcm'" */
		reg_write(MCU_MISC_DCM_CTRL,
			(reg_read(MCU_MISC_DCM_CTRL) &
			~MCU_MISCCFG_MCU_MISC_DCM_REG0_MASK) |
			MCU_MISCCFG_MCU_MISC_DCM_REG0_OFF);
	}
}

#define MCU_MISC1CFG_MCSIB_DCM_PRESET_REG0_MASK (0xffff << 0)

#define MCU_MISC1CFG_MCSIB_DCM_PRESET_REG0_ON (0xffff << 0)

#define MCU_MISC1CFG_MCSIB_DCM_PRESET_REG0_OFF (0x0 << 0)

#define MCU_MISC1CFG_MCSIB_DCM_REG0_MASK	(0xffff << 16)
#define MCU_MISC1CFG_MCSIB_DCM_REG0_ON		(0xffff << 16)
#define MCU_MISC1CFG_MCSIB_DCM_REG0_OFF		(0x0 << 16)

void dcm_mcu_misc1cfg_mcsib_dcm_preset(int on)
{
	if (on) {
		/* TINFO = "Turn ON IDLE STATE 'mcu_misc1cfg_mcsib_dcm'" */
		reg_write(MCSIB_DCM_EN,
			(reg_read(MCSIB_DCM_EN) &
			~MCU_MISC1CFG_MCSIB_DCM_PRESET_REG0_MASK) |
			MCU_MISC1CFG_MCSIB_DCM_PRESET_REG0_ON);
	} else {
		/* TINFO = "Turn OFF IDLE STATE 'mcu_misc1cfg_mcsib_dcm'" */
		reg_write(MCSIB_DCM_EN,
			(reg_read(MCSIB_DCM_EN) &
			~MCU_MISC1CFG_MCSIB_DCM_PRESET_REG0_MASK) |
			MCU_MISC1CFG_MCSIB_DCM_PRESET_REG0_OFF);
	}
}

bool dcm_mcu_misc1cfg_mcsib_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(MCSIB_DCM_EN) &
		MCU_MISC1CFG_MCSIB_DCM_REG0_MASK) ==
		(unsigned int) MCU_MISC1CFG_MCSIB_DCM_REG0_ON);

	return ret;
}

void dcm_mcu_misc1cfg_mcsib_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcu_misc1cfg_mcsib_dcm'" */
		reg_write(MCSIB_DCM_EN,
			(reg_read(MCSIB_DCM_EN) &
			~MCU_MISC1CFG_MCSIB_DCM_REG0_MASK) |
			MCU_MISC1CFG_MCSIB_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcu_misc1cfg_mcsib_dcm'" */
		reg_write(MCSIB_DCM_EN,
			(reg_read(MCSIB_DCM_EN) &
			~MCU_MISC1CFG_MCSIB_DCM_REG0_MASK) |
			MCU_MISC1CFG_MCSIB_DCM_REG0_OFF);
	}
}

#define MP2_CA15M_CONFIG_SYNC_DCM_CFG_REG0_MASK ((0x1 << 0))
#define MP2_CA15M_CONFIG_SYNC_DCM_CFG_REG0_ON ((0x1 << 0))
#define MP2_CA15M_CONFIG_SYNC_DCM_CFG_REG0_OFF ((0x0 << 0))

bool dcm_mp2_ca15m_config_sync_dcm_cfg_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(MP2_CA15M_SYNC_DCM) &
		MP2_CA15M_CONFIG_SYNC_DCM_CFG_REG0_MASK) ==
		(unsigned int) MP2_CA15M_CONFIG_SYNC_DCM_CFG_REG0_ON);

	return ret;
}

void dcm_mp2_ca15m_config_sync_dcm_cfg(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mp2_ca15m_config_sync_dcm_cfg'" */
		reg_write(MP2_CA15M_SYNC_DCM,
			(reg_read(MP2_CA15M_SYNC_DCM) &
			~MP2_CA15M_CONFIG_SYNC_DCM_CFG_REG0_MASK) |
			MP2_CA15M_CONFIG_SYNC_DCM_CFG_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mp2_ca15m_config_sync_dcm_cfg'" */
		reg_write(MP2_CA15M_SYNC_DCM,
			(reg_read(MP2_CA15M_SYNC_DCM) &
			~MP2_CA15M_CONFIG_SYNC_DCM_CFG_REG0_MASK) |
			MP2_CA15M_CONFIG_SYNC_DCM_CFG_REG0_OFF);
	}
}

