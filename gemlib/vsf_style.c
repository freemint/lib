/*
 *   fill attribute
 */

#include "gem_vdiP.h"


short
vsf_style (short handle, short style)
{
	vdi_intin[0] = style;

	VDI_TRAP (vdi_params, handle, 24, 0,1);

	return vdi_intout[0];
}
