/*
 *  $Id$
 */

#include "gem_vdiP.h"
#include "mt_gemx.h"

/** 
 *
 *  @param handle Device handle
 *  @param hilite_color 
 *
 *  @return 
 *
 *  @since NVDI 5 ?
 *
 *
 *
 */

long
vq_min_color (short handle, COLOR_ENTRY * hilite_color)
{
#if USE_LOCAL_VDIPB
	short vdi_control[VDI_CNTRLMAX]; 
	short vdi_intout[6]; 
	VDIPB vdi_params =               
	{                                
		&vdi_control[0],             /* vdi_control */
		0L,                          /* vdi_intin   */
		0L,                          /* vdi_ptsin   */
		&vdi_intout[0],              /* vdi_intout  */
		0L                           /* vdi_ptsout  */
	};
#endif
	
	VDI_TRAP_ESC (vdi_params, handle, 209,1, 0,0);

	*hilite_color = *(COLOR_ENTRY*)&vdi_intout[2];
	
	return vdi_intout_long(0);
}
