/*
 *  $Id$
 */

#include "gem_vdiP.h"

/** inquires the input mode of the specified device
 *
 *  @param handle Device handle
 *  @param dev input device (see vsin_mode())
 *  @param mode mode
 *
 *  @since all VDI versions
 *
 */

void
vqin_mode (short handle, short dev, short *mode)
{
#if USE_LOCAL_VDIPB
	short vdi_control[VDI_CNTRLMAX]; 
	VDI_PARAMS(vdi_control, &dev, 0L, mode, 0L );
#else
	vdi_intin[0] = dev;
#endif
		
	VDI_TRAP (vdi_params, handle, 115, 0,1);
	
#if !(USE_LOCAL_VDIPB)
	*mode = vdi_intout[0];
#endif
}
