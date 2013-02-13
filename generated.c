#include "video.h"
struct drm_framebuffer framebuffer = { 
	.pitches = {10240, 0, 0, 216},
	.offsets = {0, 0, 0, 1868810064},
	.width=2560, .height=1700, .depth=24,
	.bits_per_pixel=32, .flags=0,
	.pixel_format=0x34325258,
};
struct intel_crtc intelcrtc={

	.pipe = 0,
	.plane = 0,
	.dpms_mode = 0,
	.active = 1,
	.busy = 0,
	.lowfreq_avail = 0,
	.fdi_lanes = 4,
	.bpp = 18,
	.no_pll = 0,
	.use_pll_a = 0,
};
struct drm_crtc crtc = { 
  .mode = { .name = "2560x1700",
	    .status = 0,.type = 72,
	    .clock = 285250,
	    .hdisplay = 2560,
	    .hsync_start = 2608,
	    .hsync_end = 2640,
	    .htotal = 2720,
	    .hskew = 0,
	    .vdisplay = 1700,
	    .vsync_start = 1703,
	    .vsync_end = 1713,
	    .vtotal = 1749,
	    .vscan = 0,
	    .flags = 10,
	    .width_mm = 272,
	    .height_mm = 181,
	    .clock_index = 0,
	    .synth_clock = 0,
	    .crtc_hdisplay = 2560,
	    .crtc_hblank_start = 2560,
	    .crtc_hblank_end = 2720,
	    .crtc_hsync_start = 2608,
	    .crtc_hsync_end = 2640,
	    .crtc_htotal = 2720,
	    .crtc_hskew = 0,
	    .crtc_vdisplay = 1700,
	    .crtc_vblank_start = 1700,
	    .crtc_vblank_end = 1749,
	    .crtc_vsync_start = 1703,
	    .crtc_vsync_end = 1713,
	    .crtc_vtotal = 1749,
	    .crtc_hadjusted = 0,
	    .crtc_vadjusted = 0,
	    .vrefresh = 60,
	    .hsync = 0,
  },
  .hwmode = { .name = "2560x1700",
	      .status = 0,.type = 72,
	.clock = 270000,
	.hdisplay = 2560,
	.hsync_start = 2608,
	.hsync_end = 2640,
	.htotal = 2720,
	.hskew = 0,
	.vdisplay = 1700,
	.vsync_start = 1703,
	.vsync_end = 1713,
	.vtotal = 1749,
	.vscan = 0,
	.flags = 10,
	.width_mm = 272,
	.height_mm = 181,
	.clock_index = 0,
	.synth_clock = 0,
	.crtc_hdisplay = 2560,
	.crtc_hblank_start = 2560,
	.crtc_hblank_end = 2720,
	.crtc_hsync_start = 2608,
	.crtc_hsync_end = 2640,
	.crtc_htotal = 2720,
	.crtc_hskew = 0,
	.crtc_vdisplay = 1700,
	.crtc_vblank_start = 1700,
	.crtc_vblank_end = 1749,
	.crtc_vsync_start = 1703,
	.crtc_vsync_end = 1713,
	.crtc_vtotal = 1749,
	.crtc_hadjusted = 0,
	.crtc_vadjusted = 0,
	.vrefresh = 60,
	.hsync = 0,
},
	.x=0,.y=0
};
struct intel_encoder intelencoder = {.base = {.dev = NULL,
	.encoder_type = 2,
	.crtc = &crtc,
	.possible_crtcs=7, .possible_clones=1,
},
	.type=8,
	.needs_tv_clock=0,
	.crtc_mask=0,
	.clone_mask=0,
};