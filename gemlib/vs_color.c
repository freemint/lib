
#include "gem.h"


void
vs_color (int handle, int index, int rgb[])
{
	vdi_intin[0] = index;
	vdi_intin[1] = rgb[0];
	vdi_intin[2] = rgb[1];
	vdi_intin[3] = rgb[2];

	vdi_control[0] = 14;
	vdi_control[1] = 0;
	vdi_control[3] = 4;
	vdi_control[6] = handle;
	vdi (&vdi_params);
}

/*
 * * general attribute
 */