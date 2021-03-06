//DSPASIZE
//PIPEA_FRMCOUNT_GM45

/*
* This file is part of the coreboot project.
*
* Copyright 2013 Google Inc.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; version 2 of the License.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/
/* generated code; do not edit*/
/* except we cleaned it up a bit for a friend.
 * this code was created by watching IOs from a VBIOS.
 * It aligns well in what it does with a startup code
 * we wrote for IVB. It just does not work.
 * We are hard coding for a panel on the eDP on haswell.
 */
#include <stdint.h>
#include <console/console.h>
#include <delay.h>
#include "i915io.h"

	int index;	u32 auxout[16];
	u8 auxin[20];
void runio(u32 aux_ctl, u32 aux_data, int verbose)
{
	int i;
	WRITE32(0x80000000,0x45400);
	WRITE32(0x00000000,_CURACNTR);
	WRITE32( DISPPLANE_GAMMA_ENABLE |( DISPPLANE_32BPP_NO_ALPHA &0x18000000)|(/* DISPPLANE_SEL_PIPE(0=A,1=B) */0x0<<24)| DISPPLANE_TRICKLE_FEED_DISABLE /* Ironlake */ |0xd8004000,_DSPACNTR);
	WRITE32(0x00000000,_DSPBCNTR);
	WRITE32(0x80000000,CPU_VGACNTRL);
	WRITE32(0x74000&0/*0x00000000*/,_DSPASIZE+0xc);
	WRITE32(0x00000000,_DSPBSURF);
	WRITE32(0x00000000,0x4f050);
	WRITE32( DP_LINK_TRAIN_PAT_1 | DP_LINK_TRAIN_PAT_1_CPT | DP_VOLTAGE_0_4 | DP_PRE_EMPHASIS_0 | DP_PORT_WIDTH_1 | DP_PLL_FREQ_270MHZ | DP_SCRAMBLING_DISABLE_IRONLAKE | DP_SYNC_VS_HIGH |0x00000091,DP_A);
	WRITE32(0x00200090,_FDI_RXA_MISC);
	WRITE32(0x0a000000,_FDI_RXA_MISC);
	WRITE32(0x00000070,0x46408);
	WRITE32(0x04000000,0x42090);
	WRITE32(0x40000000,0x4f050);
	WRITE32(0x00000000,0x9840);
	WRITE32(0xa4000000,0x42090);
	WRITE32(0x00004000,0x42080);
	WRITE32(0x00ffffff,0x64f80);
	WRITE32(0x0007000e,0x64f84);
	WRITE32(0x00d75fff,0x64f88);
	WRITE32(0x000f000a,0x64f8c);
	WRITE32(0x00c30fff,0x64f90);
	WRITE32(0x00060006,0x64f94);
	WRITE32(0x00aaafff,0x64f98);
	WRITE32(0x001e0000,0x64f9c);
	WRITE32(0x00ffffff,0x64fa0);
	WRITE32(0x000f000a,0x64fa4);
	WRITE32(0x00d75fff,0x64fa8);
	WRITE32(0x00160004,0x64fac);
	WRITE32(0x00c30fff,0x64fb0);
	WRITE32(0x001e0000,0x64fb4);
	WRITE32(0x00ffffff,0x64fb8);
	WRITE32(0x00060006,0x64fbc);
	WRITE32(0x00d75fff,0x64fc0);
	WRITE32(0x001e0000,0x64fc4);
	WRITE32(0x00ffffff,0x64e00);
	WRITE32(0x0006000e,0x64e04);
	WRITE32(0x00d75fff,0x64e08);
	WRITE32(0x0005000a,0x64e0c);
	WRITE32(0x00c30fff,0x64e10);
	WRITE32(0x00040006,0x64e14);
	WRITE32(0x80aaafff,0x64e18);
	WRITE32(0x000b0000,0x64e1c);
	WRITE32(0x00ffffff,0x64e20);
	WRITE32(0x0005000a,0x64e24);
	WRITE32(0x00d75fff,0x64e28);
	WRITE32(0x000c0004,0x64e2c);
	WRITE32(0x80c30fff,0x64e30);
	WRITE32(0x000b0000,0x64e34);
	WRITE32(0x00ffffff,0x64e38);
	WRITE32(0x00040006,0x64e3c);
	WRITE32(0x80d75fff,0x64e40);
	WRITE32(0x000b0000,0x64e44);
	WRITE32( DIGITAL_PORTA_HOTPLUG_ENABLE |0x00000010,DIGITAL_PORT_HOTPLUG_CNTRL);
	WRITE32(0x10000000,SDEISR+0x30);

	/* END RESET. START AUX CHANNEL IO */
	/* this seems to be the one mandatory empty IO you do to
	 * block until the aux channel is up and running.
	 */
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 0, auxin, 0);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_DPCD_REV<<8|0x0|0x90000000;
printk(BIOS_SPEW, "DP_DPCD_REV");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	/* this is EDID. For this simple code, the panel
	 * is hard coded. We do it anyway but don't use it yet
	 * on this hardware.
	 */
	auxout[0] = 0<<31 /* i2c */|1<<30|0x0<<28/*W*/|0x50<<8|0x0|0x40005000;
	auxout[1] = 0x00000000;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 5, auxin, 0);
	auxout[0] = 0<<31 /* i2c */|0<<30|0x1<<28/*R*/|0x50<<8|0x3|0x10005003;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 3);
	auxout[0] = 0<<31 /* i2c */|1<<30|0x0<<28/*W*/|0x50<<8|0x0|0x40005000;
	auxout[1] = 0x04000000;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 5, auxin, 0);
	auxout[0] = 0<<31 /* i2c */|0<<30|0x1<<28/*R*/|0x50<<8|0x3|0x10005003;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 3);
	auxout[0] = 0<<31 /* i2c */|1<<30|0x0<<28/*W*/|0x50<<8|0x0|0x40005000;
	auxout[1] = 0x00000000;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 5, auxin, 0);
	auxout[0] = 0<<31 /* i2c */|1<<30|0x1<<28/*R*/|0x50<<8|0xf|0x5000500f;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 15);
	auxout[0] = 0<<31 /* i2c */|1<<30|0x1<<28/*R*/|0x50<<8|0xf|0x5000500f;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 15);
	auxout[0] = 0<<31 /* i2c */|1<<30|0x1<<28/*R*/|0x50<<8|0xf|0x5000500f;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 15);
	auxout[0] = 0<<31 /* i2c */|1<<30|0x1<<28/*R*/|0x50<<8|0xf|0x5000500f;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 15);
	auxout[0] = 0<<31 /* i2c */|1<<30|0x1<<28/*R*/|0x50<<8|0xf|0x5000500f;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 15);
	auxout[0] = 0<<31 /* i2c */|1<<30|0x1<<28/*R*/|0x50<<8|0xf|0x5000500f;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 15);
	auxout[0] = 0<<31 /* i2c */|1<<30|0x1<<28/*R*/|0x50<<8|0xf|0x5000500f;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 15);
	auxout[0] = 0<<31 /* i2c */|1<<30|0x1<<28/*R*/|0x50<<8|0xf|0x5000500f;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 15);
	auxout[0] = 0<<31 /* i2c */|0<<30|0x1<<28/*R*/|0x50<<8|0x0|0x10005000;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	/* end EDID */
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_MAX_LINK_RATE<<8|0x0|0x90000100;
printk(BIOS_SPEW, "DP_MAX_LINK_RATE");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_MAX_LANE_COUNT<<8|0x0|0x90000200;
printk(BIOS_SPEW, "DP_MAX_LANE_COUNT");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	if (verbose & vio) READ32(BLC_PWM_CPU_CTL);
	WRITE32(0x03a903a9,BLC_PWM_CPU_CTL);
	if (verbose & vio) READ32(BLC_PWM_PCH_CTL2);
	WRITE32(0x03a903a9,BLC_PWM_PCH_CTL2);
	if (verbose & vio) READ32(BLC_PWM_PCH_CTL1);
	WRITE32(0x00000000,BLC_PWM_PCH_CTL1);
	if (verbose & vio) READ32(0x4f050);
	if (verbose & vio) READ32(0x64f68);
	WRITE32(0x00ffffff,0x64f68);
	if (verbose & vio) READ32(0x64f6c);
	WRITE32(0x00040006,0x64f6c);
	if (verbose & vio) READ32(_FDI_RXB_CHICKEN+0x4);
	if (verbose & vio) READ32(SDEISR+0x30);
	WRITE32( PORTB_HOTPLUG_ENABLE |0x10000010,SDEISR+0x30);
	if (verbose & vio) READ32(SDEISR);
	if (verbose & vio) READ32(0x64f08);
	WRITE32(0x00ffffff,0x64f08);
	if (verbose & vio) READ32(0x64f0c);
	WRITE32(0x00040006,0x64f0c);
	if (verbose & vio) READ32(_FDI_RXB_CHICKEN+0x4);
	if (verbose & vio) READ32(SDEISR+0x30);
	WRITE32( PORTC_HOTPLUG_ENABLE | PORTB_HOTPLUG_ENABLE |0x10001010,SDEISR+0x30);
	if (verbose & vio) READ32(SDEISR);
	if (verbose & vio) READ32(0x4f05c);
	WRITE32(0x00000008,0x4f05c);
	if (verbose & vio) READ32(0x4f060);
	WRITE32(0x00000008,0x4f060);
	if (verbose & vio) READ32(0x45400);
	WRITE32(0x80000000,0x45400);
	if (verbose & vio) READ32(0x45400);
	if (verbose & vio) READ32(0x4f05c);
	if (verbose & vio) READ32(CPU_VGACNTRL);
	if (verbose & vio) READ32(CPU_VGACNTRL);
	WRITE32(0x80000000,CPU_VGACNTRL);
	if (verbose & vio) READ32(_CURACNTR);
	WRITE32(0x00000000,_CURACNTR);
	if (verbose & vio) READ32(_CURABASE);
	WRITE32(0x00000000,_CURABASE);
	if (verbose & vio) READ32(_DSPACNTR);
	WRITE32( DISPPLANE_GAMMA_ENABLE |( DISPPLANE_32BPP_NO_ALPHA &0x18000000)|(/* DISPPLANE_SEL_PIPE(0=A,1=B) */0x0<<24)| DISPPLANE_TRICKLE_FEED_DISABLE /* Ironlake */ |0xd8004000,_DSPACNTR);
	if (verbose & vio) READ32(_DSPASIZE+0xc);
	WRITE32(0x74000&0/*0x00000000*/,_DSPASIZE+0xc);
	if (verbose & vio) READ32(_CURBCNTR_IVB);
	WRITE32(0x00000000,_CURBCNTR_IVB);
	if (verbose & vio) READ32(_CURBBASE_IVB);
	WRITE32(0x00000000,_CURBBASE_IVB);
	if (verbose & vio) READ32(_DSPBCNTR);
	WRITE32(0x00000000,_DSPBCNTR);
	if (verbose & vio) READ32(_DSPBSURF);
	WRITE32(0x00000000,_DSPBSURF);
	if (verbose & vio) READ32(0x72080);
	WRITE32(0x00000000,0x72080);
	if (verbose & vio) READ32(0x72084);
	WRITE32(0x00000000,0x72084);
	if (verbose & vio) READ32(_DVSACNTR);
	WRITE32(0x00000000,_DVSACNTR);
	if (verbose & vio) READ32(_DVSASURF);
	WRITE32(0x00000000,_DVSASURF);
	if (verbose & vio) READ32(0x6f400);
	if (verbose & vio) READ32(0x4f05c);
	if (verbose & vio) READ32(0x7f008);
	if (verbose & vio) READ32(0x61400);
	if (verbose & vio) READ32(0x4f05c);
	if (verbose & vio) READ32(_PIPEBCONF);
	if (verbose & vio) READ32(0x62400);
	if (verbose & vio) READ32(0x4f05c);
	if (verbose & vio) READ32(0x72008);
	if (verbose & vio) READ32(0x4f05c);
	if (verbose & vio) READ32(0x4f05c);
	WRITE32(0x00000008,0x4f05c);
	if (verbose & vio) READ32(0x4f060);
	WRITE32(0x00000008,0x4f060);
	if (verbose & vio) READ32(CPU_VGACNTRL);
	WRITE32(0x80000000,CPU_VGACNTRL);
	if (verbose & vio) READ32(_DSPASTRIDE);
	WRITE32(0x00000640,_DSPASTRIDE);
	if (verbose & vio) READ32(_DSPAADDR);
	WRITE32(0x00000000,_DSPAADDR);
	if (verbose & vio) READ32(_DSPASIZE+0xc);
	WRITE32(0x74000&0/*0x00000000*/,_DSPASIZE+0xc);
	if (verbose & vio) READ32(_DSPASTRIDE);
	if (verbose & vio) READ32(0x7f008);
	auxout[0] = 1<<31 /* dp */|0x0<<28/*W*/|DP_SET_POWER<<8|0x0|0x80060000;
printk(BIOS_SPEW, "DP_SET_POWER");
	auxout[1] = 0x01000000;
	/* DP_SET_POWER_D0 | DP_PSR_SINK_INACTIVE |0x00000001*/
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 0, auxin, 0);
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 5, auxin, 0);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_DPCD_REV<<8|0x0|0x90000000;
printk(BIOS_SPEW, "DP_DPCD_REV");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	if (verbose & vio) READ32(0x4f014);
	WRITE32(0x00000018,0x4f014);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_MAX_DOWNSPREAD<<8|0x0|0x90000300;
printk(BIOS_SPEW, "DP_MAX_DOWNSPREAD");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	if (verbose & vio) READ32(0x4f014);
	if (verbose & vio) READ32(0x6f030);
	WRITE32(0x7e62b020,0x6f030);
	if (verbose & vio) READ32(0x6f034);
	WRITE32(0x00800000,0x6f034);
	if (verbose & vio) READ32(0x6f040);
	WRITE32(0x00041cac,0x6f040);
	if (verbose & vio) READ32(0x6f044);
	WRITE32(0x00080000,0x6f044);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_MAX_DOWNSPREAD<<8|0x0|0x90000300;
printk(BIOS_SPEW, "DP_MAX_DOWNSPREAD");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_MAX_DOWNSPREAD<<8|0x0|0x90000300;
printk(BIOS_SPEW, "DP_MAX_DOWNSPREAD");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	if (verbose & vio) READ32(FORCEWAKE_MT_ACK);
	WRITE32(0x40000006,FORCEWAKE_MT_ACK);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_MAX_DOWNSPREAD<<8|0x0|0x90000300;
printk(BIOS_SPEW, "DP_MAX_DOWNSPREAD");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	if (verbose & vio) READ32(0x6f000);
	WRITE32(0x081f077f,0x6f000);
	if (verbose & vio) READ32(0x6f004);
	WRITE32(0x081f077f,0x6f004);
	if (verbose & vio) READ32(0x6f008);
	WRITE32(0x07cb07ad,0x6f008);
	if (verbose & vio) READ32(0x6f00c);
	WRITE32(0x04570437,0x6f00c);
	if (verbose & vio) READ32(0x6f010);
	WRITE32(0x04570437,0x6f010);
	if (verbose & vio) READ32(0x6f014);
	WRITE32(0x043d0439,0x6f014);
	if (verbose & vio) READ32(_PIPEASRC);
	WRITE32(0x077f0437,_PIPEASRC);
	if (verbose & vio) READ32(0x7f008);
	WRITE32(0x00000000,0x7f008);
	if (verbose & vio) READ32(_TRANSACONF);
	WRITE32(0x00000000,_TRANSACONF);
	if (verbose & vio) READ32(0x6f000);
	if (verbose & vio) READ32(_HTOTAL_A);
	WRITE32(0x081f077f,_HTOTAL_A);
	if (verbose & vio) READ32(0x6f004);
	if (verbose & vio) READ32(_HBLANK_A);
	WRITE32(0x081f077f,_HBLANK_A);
	if (verbose & vio) READ32(0x6f008);
	if (verbose & vio) READ32(_HSYNC_A);
	WRITE32(0x07cb07ad,_HSYNC_A);
	if (verbose & vio) READ32(0x6f00c);
	if (verbose & vio) READ32(_VTOTAL_A);
	WRITE32(0x04570437,_VTOTAL_A);
	if (verbose & vio) READ32(0x6f010);
	if (verbose & vio) READ32(_VBLANK_A);
	WRITE32(0x04570437,_VBLANK_A);
	if (verbose & vio) READ32(0x6f014);
	if (verbose & vio) READ32(_VSYNC_A);
	WRITE32(0x043d0439,_VSYNC_A);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_MAX_DOWNSPREAD<<8|0x0|0x90000300;
printk(BIOS_SPEW, "DP_MAX_DOWNSPREAD");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	if (verbose & vio) READ32(0x46100);
	WRITE32(0x20000000,0x46100);
	if (verbose & vio) READ32(_DSPACNTR);
	WRITE32( DISPPLANE_GAMMA_ENABLE |( DISPPLANE_32BPP_NO_ALPHA &0x18000000)|(/* DISPPLANE_SEL_PIPE(0=A,1=B) */0x0<<24)| DISPPLANE_TRICKLE_FEED_DISABLE /* Ironlake */ |0xd8004000,_DSPACNTR);
	if (verbose & vio) READ32(_DSPASTRIDE);
	WRITE32(0x00000640,_DSPASTRIDE);
	if (verbose & vio) READ32(_DSPAADDR);
	WRITE32(0x00000000,_DSPAADDR);
	if (verbose & vio) READ32(_DSPASIZE+0xc);
	WRITE32(0x74000&0/*0x00000000*/,_DSPASIZE+0xc);
	if (verbose & vio) READ32(_DSPACNTR);
	WRITE32( DISPPLANE_GAMMA_ENABLE |( DISPPLANE_32BPP_NO_ALPHA &0x18000000)|(/* DISPPLANE_SEL_PIPE(0=A,1=B) */0x0<<24)| DISPPLANE_TRICKLE_FEED_DISABLE /* Ironlake */ |0xd8004000,_DSPACNTR);
	if (verbose & vio) READ32(_DSPACNTR);
	if (verbose & vio) READ32(_DSPACNTR);
	WRITE32( DISPPLANE_GAMMA_ENABLE |( DISPPLANE_32BPP_NO_ALPHA &0x18000000)|(/* DISPPLANE_SEL_PIPE(0=A,1=B) */0x0<<24)| DISPPLANE_TRICKLE_FEED_DISABLE /* Ironlake */ |0xd8004000,_DSPACNTR);
	if (verbose & vio) READ32(_DSPASIZE+0xc);
	WRITE32(0x74000&0/*0x00000000*/,_DSPASIZE+0xc);
	if (verbose & vio) READ32(_PFA_WIN_POS);
	WRITE32(0x00000000,_PFA_WIN_POS);
	if (verbose & vio) READ32(0x4f050);
	if (verbose & vio) READ32(_PIPEASRC);
	WRITE32(0x077f0437,_PIPEASRC);
	if (verbose & vio) READ32(_PFA_WIN_POS);
	WRITE32(0x00000000,_PFA_WIN_POS);
	if (verbose & vio) READ32(_PFA_CTL_1);
	WRITE32(0x80800000,_PFA_CTL_1);
	if (verbose & vio) READ32(_PFA_WIN_POS);
	if (verbose & vio) READ32(0x6f00c);
	if (verbose & vio) READ32(0x6f000);
	if (verbose & vio) READ32(_PFA_WIN_SZ);
	WRITE32(0x00000000,_PFA_WIN_SZ);
	if (verbose & vio) READ32(0x4f014);
	if (verbose & vio) READ32(0x6f400);
	WRITE32(0x00030000,0x6f400);
	if (verbose & vio) READ32(0x4f014);
	if (verbose & vio) READ32(0x7f008);
	WRITE32(0x00000000,0x7f008);
	if (verbose & vio) READ32(0x4f014);
	if (verbose & vio) READ32(0x6f400);
	WRITE32(0x82034002,0x6f400);
	if (verbose & vio) READ32(0x7f008);
	WRITE32(0x80000000,0x7f008);
	auxout[0] = 0<<31 /* i2c */|1<<30|0x0<<28/*W*/|0x50<<8|0x0|0x40005000;
	auxout[1] = 0x00000000;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 5, auxin, 0);
	auxout[0] = 0<<31 /* i2c */|0<<30|0x1<<28/*R*/|0x50<<8|0x3|0x10005003;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 3);
	auxout[0] = 0<<31 /* i2c */|1<<30|0x0<<28/*W*/|0x50<<8|0x0|0x40005000;
	auxout[1] = 0x04000000;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 5, auxin, 0);
	auxout[0] = 0<<31 /* i2c */|0<<30|0x1<<28/*R*/|0x50<<8|0x3|0x10005003;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 3);
	auxout[0] = 0<<31 /* i2c */|1<<30|0x0<<28/*W*/|0x50<<8|0x0|0x40005000;
	auxout[1] = 0x7e000000;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 5, auxin, 0);
	auxout[0] = 0<<31 /* i2c */|0<<30|0x1<<28/*R*/|0x50<<8|0x0|0x10005000;
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	if (verbose & vio) READ32(DP_A);
	WRITE32( DP_LINK_TRAIN_PAT_1 | DP_LINK_TRAIN_PAT_1_CPT | DP_VOLTAGE_0_4 | DP_PRE_EMPHASIS_0 | DP_PORT_WIDTH_1 | DP_PLL_FREQ_270MHZ | DP_SCRAMBLING_DISABLE_IRONLAKE | DP_SYNC_VS_HIGH |0x00000091,DP_A);
	if (verbose & vio) READ32(DP_A);
	if (verbose & vio) READ32(0x4f014);
	if (verbose & vio) READ32(0x6f410);
	WRITE32(0x00000021,0x6f410);
	if (verbose & vio) READ32(DP_A+0x40);
	WRITE32(0x80000011,DP_A+0x40);
	if (verbose & vio) READ32(DP_A);
	WRITE32( DP_PORT_EN | DP_LINK_TRAIN_PAT_1 | DP_LINK_TRAIN_PAT_1_CPT | DP_VOLTAGE_0_4 | DP_PRE_EMPHASIS_0 | DP_PORT_WIDTH_1 | DP_PLL_FREQ_270MHZ | DP_SCRAMBLING_DISABLE_IRONLAKE | DP_SYNC_VS_HIGH |0x80000093,DP_A);
	if (verbose & vio) READ32(PCH_PP_ON_DELAYS);
	if (verbose & vio) READ32(PCH_PP_ON_DELAYS);
	WRITE32( PANEL_PORT_SELECT_LVDS |(/* PANEL_POWER_UP_DELAY_MASK */0x1<<16)|(/* PANEL_LIGHT_ON_DELAY_MASK */0xa<<0)|0x0001000a,PCH_PP_ON_DELAYS);
	if (verbose & vio) READ32(PCH_PP_STATUS);
	if (verbose & vio) READ32(PCH_PP_ON_DELAYS);
	WRITE32( PANEL_PORT_SELECT_LVDS |(/* PANEL_POWER_UP_DELAY_MASK */0x7d0<<16)|(/* PANEL_LIGHT_ON_DELAY_MASK */0xa<<0)|0x07d0000a,PCH_PP_ON_DELAYS);
	auxout[0] = 1<<31 /* dp */|0x0<<28/*W*/|DP_LINK_BW_SET<<8|0x0|0x80010000;
printk(BIOS_SPEW, "DP_LINK_BW_SET");
	auxout[1] = 0x0a000080;
	/*( DP_LINK_BW_2_7 &0xa)|0xffffffff8000000a*/
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 5, auxin, 0);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_MAX_LANE_COUNT<<8|0x0|0x90000200;
printk(BIOS_SPEW, "DP_MAX_LANE_COUNT");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	if (verbose & vio) READ32(DP_A);
	auxout[0] = 1<<31 /* dp */|0x0<<28/*W*/|DP_LANE_COUNT_SET<<8|0x0|0x80010100;
printk(BIOS_SPEW, "DP_LANE_COUNT_SET");
	auxout[1] = 0x02000000;
	/*0x00000002*/
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 5, auxin, 0);
	if (verbose & vio) READ32(DP_A+0x40);
	WRITE32(0x80000000,DP_A+0x40);
	if (verbose & vio) READ32(DP_A);
	WRITE32( DP_PORT_EN | DP_LINK_TRAIN_PAT_1 | DP_LINK_TRAIN_PAT_1_CPT | DP_VOLTAGE_0_4 | DP_PRE_EMPHASIS_0 | DP_PORT_WIDTH_1 | DP_PLL_FREQ_270MHZ | DP_SYNC_VS_HIGH |0x80000013,DP_A);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_TRAINING_PATTERN_SET<<8|0x0|0x90010200;
printk(BIOS_SPEW, "DP_TRAINING_PATTERN_SET");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	auxout[0] = 1<<31 /* dp */|0x0<<28/*W*/|DP_TRAINING_PATTERN_SET<<8|0x0|0x80010200;
printk(BIOS_SPEW, "DP_TRAINING_PATTERN_SET");
	auxout[1] = 0x01000000;
	/* DP_TRAINING_PATTERN_1 | DP_LINK_QUAL_PATTERN_DISABLE | DP_SYMBOL_ERROR_COUNT_BOTH |0x00000001*/
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 5, auxin, 0);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_LANE_COUNT_SET<<8|0x0|0x90010100;
#if 1
printk(BIOS_SPEW, "DP_LANE_COUNT_SET");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	auxout[0] = 1<<31 /* dp */|0x0<<28/*W*/|DP_TRAINING_LANE0_SET<<8|0x1|0x80010301;
printk(BIOS_SPEW, "DP_TRAINING_LANE0_SET");
	auxout[1] = 0x00000000;
	/* DP_TRAIN_VOLTAGE_SWING_400 | DP_TRAIN_PRE_EMPHASIS_0 |0x00000000*/
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 6, auxin, 0);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_LANE0_1_STATUS<<8|0x1|0x90020201;
printk(BIOS_SPEW, "DP_LANE0_1_STATUS");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 1);
	if (verbose & vio) READ32(DP_A+0x40);
	WRITE32(0x80000100,DP_A+0x40);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_TRAINING_PATTERN_SET<<8|0x0|0x90010200;
printk(BIOS_SPEW, "DP_TRAINING_PATTERN_SET");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	auxout[0] = 1<<31 /* dp */|0x0<<28/*W*/|DP_TRAINING_PATTERN_SET<<8|0x0|0x80010200;
printk(BIOS_SPEW, "DP_TRAINING_PATTERN_SET");
	auxout[1] = 0x02000000;
	/* DP_TRAINING_PATTERN_2 | DP_LINK_QUAL_PATTERN_DISABLE | DP_SYMBOL_ERROR_COUNT_BOTH |0x00000002*/
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 5, auxin, 0);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_LANE0_1_STATUS<<8|0x1|0x90020201;
printk(BIOS_SPEW, "DP_LANE0_1_STATUS");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 1);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_LANE_ALIGN_STATUS_UPDATED<<8|0x0|0x90020400;
printk(BIOS_SPEW, "DP_LANE_ALIGN_STATUS_UPDATED");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	auxout[0] = 1<<31 /* dp */|0x1<<28/*R*/|DP_TRAINING_PATTERN_SET<<8|0x0|0x90010200;
printk(BIOS_SPEW, "DP_TRAINING_PATTERN_SET");
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 4, auxin, 0);
	auxout[0] = 1<<31 /* dp */|0x0<<28/*W*/|DP_TRAINING_PATTERN_SET<<8|0x0|0x80010200;
printk(BIOS_SPEW, "DP_TRAINING_PATTERN_SET");
	auxout[1] = 0x00000000;
	/* DP_TRAINING_PATTERN_DISABLE | DP_LINK_QUAL_PATTERN_DISABLE | DP_SYMBOL_ERROR_COUNT_BOTH |0x00000000*/
	intel_dp_aux_ch(aux_ctl, aux_data, auxout, 5, auxin, 0);
	/* from kernel */
	//WRITE32(0x000f3806,  WM0_PIPEA_ILK);
	/* end fro kernel */
	if (verbose & vio) READ32(DP_A+0x40);
	WRITE32(0x80000200,DP_A+0x40);
	if (verbose & vio) READ32(DP_A+0x40);
	WRITE32(0x80000300,DP_A+0x40);
	if (verbose & vio) READ32(BLC_PWM_CPU_CTL2);
	WRITE32( PWM_ENABLE |0x80000000,BLC_PWM_CPU_CTL2);
	if (verbose & vio) READ32(BLC_PWM_PCH_CTL1);
	WRITE32( PWM_PCH_ENABLE |0x80000000,BLC_PWM_PCH_CTL1);
	if (verbose & vio) READ32(BLC_PWM_CPU_CTL);
	WRITE32(0x03a903a9,BLC_PWM_CPU_CTL);
	if (verbose & vio) READ32(BLC_PWM_CPU_CTL);
	WRITE32(0x03a903a9,BLC_PWM_CPU_CTL);
	if (verbose & vio) READ32(BLC_PWM_PCH_CTL2);
	WRITE32(0x03a903a9,BLC_PWM_PCH_CTL2);
	if (verbose & vio) READ32(BLC_PWM_PCH_CTL1);
	WRITE32( PWM_PCH_ENABLE |0x80000000,BLC_PWM_PCH_CTL1);
	if (verbose & vio) READ32(SDEISR+0x30);
	WRITE32( PORTC_HOTPLUG_ENABLE | PORTB_HOTPLUG_ENABLE |0x10001010,SDEISR+0x30);
	if (verbose & vio) READ32(DIGITAL_PORT_HOTPLUG_CNTRL);
	WRITE32( DIGITAL_PORTA_HOTPLUG_ENABLE |0x00000010,DIGITAL_PORT_HOTPLUG_CNTRL);
	printk(BIOS_SPEW, "Sleep long and well\n");
	udelay(5000000);
	/* this runs (I kid you not) 210 times in the VBIOS. The values
	 * never change. So what's it do? Timing?
	 */
	for(i = 0; i < 210; i++){
		if (verbose & vio) READ32(0x45400);
		WRITE32(0x80000000,0x45400);
		if (verbose & vio) READ32(0x45400);
		if (verbose & vio) READ32(_DSPASTRIDE);
		if (verbose & vio) READ32(_DSPASTRIDE);
	}
	printk(BIOS_SPEW, "Wait a bit\n");
#endif
	if (verbose & vio) READ32(0x4f05c);
	if (verbose & vio) READ32(CPU_VGACNTRL);
	if (verbose & vio) READ32(CPU_VGACNTRL);
	WRITE32(0x80000000,CPU_VGACNTRL);
	if (verbose & vio) READ32(_CURACNTR);
	WRITE32(0x00000000,_CURACNTR);
	if (verbose & vio) READ32(_CURABASE);
	WRITE32(0x00000000,_CURABASE);
	if (verbose & vio) READ32(_DSPACNTR);
	WRITE32( DISPPLANE_GAMMA_ENABLE |( DISPPLANE_32BPP_NO_ALPHA &0x18000000)|(/* DISPPLANE_SEL_PIPE(0=A,1=B) */0x0<<24)| DISPPLANE_TRICKLE_FEED_DISABLE /* Ironlake */ |0xd8004000,_DSPACNTR);
	if (verbose & vio) READ32(_DSPASIZE+0xc);
	WRITE32(0x74000&0/*0x00000000*/,_DSPASIZE+0xc);
	if (verbose & vio) READ32(_CURBCNTR_IVB);
	WRITE32(0x00000000,_CURBCNTR_IVB);
	if (verbose & vio) READ32(_CURBBASE_IVB);
	WRITE32(0x00000000,_CURBBASE_IVB);
	if (verbose & vio) READ32(_DSPBCNTR);
	WRITE32(0x00000000,_DSPBCNTR);
	if (verbose & vio) READ32(_DSPBSURF);
	WRITE32(0x00000000,_DSPBSURF);
	if (verbose & vio) READ32(0x72080);
	WRITE32(0x00000000,0x72080);
	if (verbose & vio) READ32(0x72084);
	WRITE32(0x00000000,0x72084);
	if (verbose & vio) READ32(_DVSACNTR);
	WRITE32(0x00000000,_DVSACNTR);
	if (verbose & vio) READ32(_DVSASURF);
	WRITE32(0x00000000,_DVSASURF);
	if (verbose & vio) READ32(0x6f400);
	if (verbose & vio) READ32(0x4f05c);
	if (verbose & vio) READ32(0x7f008);
	if (verbose & vio) READ32(0x61400);
	if (verbose & vio) READ32(0x4f05c);
	if (verbose & vio) READ32(_PIPEBCONF);
	if (verbose & vio) READ32(0x62400);
	if (verbose & vio) READ32(0x4f05c);
	if (verbose & vio) READ32(0x72008);
	if (verbose & vio) READ32(0x4f05c);
	if (verbose & vio) READ32(0x4f05c);
	WRITE32(0x00000008,0x4f05c);
	if (verbose & vio) READ32(0x4f060);
	WRITE32(0x00000008,0x4f060);
	if (verbose & vio) READ32(CPU_VGACNTRL);
	WRITE32(0x80000000,CPU_VGACNTRL);
	if (verbose & vio) READ32(_DSPASTRIDE);
	WRITE32(0x00000640,_DSPASTRIDE);
	if (verbose & vio) READ32(_DSPAADDR);
	WRITE32(0x00000000,_DSPAADDR);
	if (verbose & vio) READ32(_DSPASIZE+0xc);
	WRITE32(0x74000&0/*0x00000000*/,_DSPASIZE+0xc);
	if (verbose & vio) READ32(_DSPASTRIDE);
	if (verbose & vio) READ32(0x7f008);
	if (verbose & vio) READ32(_DSPACNTR);
	WRITE32( DISPPLANE_GAMMA_ENABLE |( DISPPLANE_32BPP_NO_ALPHA &0x18000000)|(/* DISPPLANE_SEL_PIPE(0=A,1=B) */0x0<<24)| DISPPLANE_TRICKLE_FEED_DISABLE /* Ironlake */ |0xd8004000,_DSPACNTR);
	if (verbose & vio) READ32(_DSPASIZE+0xc);
	WRITE32(0x74000&0/*0x00000000*/,_DSPASIZE+0xc);
	if (verbose & vio) READ32(_PFA_WIN_POS);
	WRITE32(0x00000000,_PFA_WIN_POS);
	if (verbose & vio) READ32(_PFA_WIN_SZ);
	WRITE32(0x00000000,_PFA_WIN_SZ);
	if (verbose & vio) READ32(_PIPEASRC);
	WRITE32(0x077f0437,_PIPEASRC);
	if (verbose & vio) READ32(_PFA_WIN_POS);
	WRITE32(0x00000000,_PFA_WIN_POS);
	if (verbose & vio) READ32(0x4f050);
	if (verbose & vio) READ32(_PIPEASRC);
	WRITE32(0x077f0437,_PIPEASRC);
	if (verbose & vio) READ32(_PFA_WIN_POS);
	WRITE32(0x00000000,_PFA_WIN_POS);
	if (verbose & vio) READ32(_PFA_CTL_1);
	WRITE32(0x80800000,_PFA_CTL_1);
	if (verbose & vio) READ32(_PFA_WIN_POS);
	if (verbose & vio) READ32(0x6f00c);
	if (verbose & vio) READ32(0x6f000);
	if (verbose & vio) READ32(_PFA_WIN_SZ);
	WRITE32(0x00000000,_PFA_WIN_SZ);
	if (verbose & vio) READ32(_DSPACNTR);
	WRITE32( DISPPLANE_GAMMA_ENABLE |( DISPPLANE_32BPP_NO_ALPHA &0x18000000)|(/* DISPPLANE_SEL_PIPE(0=A,1=B) */0x0<<24)| DISPPLANE_TRICKLE_FEED_DISABLE /* Ironlake */ |0xd8004000,_DSPACNTR);
	if (verbose & vio) READ32(_DSPASTRIDE);
	WRITE32(0x00000640,_DSPASTRIDE);
	if (verbose & vio) READ32(_DSPAADDR);
	WRITE32(0x00000000,_DSPAADDR);
	if (verbose & vio) READ32(_DSPASIZE+0xc);
	WRITE32(0x74000&0/*0x00000000*/,_DSPASIZE+0xc);
	if (verbose & vio) READ32(_DSPACNTR);
	WRITE32( DISPPLANE_GAMMA_ENABLE |( DISPPLANE_32BPP_NO_ALPHA &0x18000000)|(/* DISPPLANE_SEL_PIPE(0=A,1=B) */0x0<<24)| DISPPLANE_TRICKLE_FEED_DISABLE /* Ironlake */ |0xd8004000,_DSPACNTR);
	if (verbose & vio) READ32(_DSPACNTR);
	if (verbose & vio) READ32(_DSPACNTR);
	WRITE32( DISPPLANE_GAMMA_ENABLE |( DISPPLANE_32BPP_NO_ALPHA &0x18000000)|(/* DISPPLANE_SEL_PIPE(0=A,1=B) */0x0<<24)| DISPPLANE_TRICKLE_FEED_DISABLE /* Ironlake */ |0xd8004000,_DSPACNTR);
	if (verbose & vio) READ32(_DSPASIZE+0xc);
	WRITE32(0x74000&0/*0x00000000*/,_DSPASIZE+0xc);
	/* from kernel. */
	WRITE32(0x00074000&0,_DSPASIZE+0xc);
	if (verbose & vio) READ32(SDEISR+0x30);
	WRITE32( PORTC_HOTPLUG_ENABLE | PORTB_HOTPLUG_ENABLE |0x10001010,SDEISR+0x30);
	if (verbose & vio) READ32(DIGITAL_PORT_HOTPLUG_CNTRL);
	WRITE32( DIGITAL_PORTA_HOTPLUG_ENABLE |0x00000010,DIGITAL_PORT_HOTPLUG_CNTRL);
	printk(BIOS_SPEW, "pci dev(0x0,0x2,0x0,0x8)");
	printk(BIOS_SPEW, "pci dev(0x0,0x1f,0x0,0x10)");
	printk(BIOS_SPEW, "pci dev(0x0,0x2,0x0,0x0)");
	printk(BIOS_SPEW, "pci dev(0x0,0x2,0x0,0x2)");
}

