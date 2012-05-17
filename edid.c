#include "video.h"

extern int verbose;
extern struct drm_device *i915;
int cangencode = 0;

int main(int argc, char *argv[])
{
	struct drm_i915_private *dp;

	init(&argc, &argv);
	devinit();
	intel_setup_bios(i915);
	if (i915->bios_bin)
		intel_parse_bios(i915);
	intel_panel_enable_backlight(i915);
	i915_driver_load(i915, (unsigned long)i915->dev_private->info);

	/* now walk the connector list, dumping connector type 
	 * and EDID
	 */
	dp = i915->dev_private;

	if (dp->int_lvds_connector) {
		if (verbose){
			fprintf(stderr, "We have an lvds: \n");
		}
		dumpeld("LVDS Raw: ", 
			dp->int_lvds_connector->display_info.raw_edid);
		//dumpeld("LVDS:", dp->int_lvds_connector->eld);
	}
	
	if (dp->int_edp_connector) {
		if (verbose)
			fprintf(stderr, "We have an edp: \n");
		if (dp->int_lvds_connector) {
			dumpeld("EDP Raw: ", 
				dp->int_lvds_connector->display_info.raw_edid);
		} else printf("NO EDP connector\n");
		//dumpeld("EDP:", dp->int_lvds_connector->eld);
	}

	
}