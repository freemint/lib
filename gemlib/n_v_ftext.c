/*
 *  $Id$
 */

#include "gem_vdiP.h"
#include "mt_gemx.h"

/** This text function uses track and pair kerning and works with an internal 
 *  resolution of 1/65536 pixels to maintain accurate character placement.
 *
 *  @param handle Device handle
 *  @param x 
 *  @param y 
 *  @param str 
 *
 *  @since  NVDI 3.00
 *
 *  @note There is another variant of v_ftext() which allows your application to specifiy 
 *  the offset of each character relative to the previous one: v_ftext_offset()
 */

void
v_ftext (short handle, short x, short y, const char *str)
{
#if USE_LOCAL_VDIPB
	short vdi_control[VDI_CNTRLMAX]; 
	short vdi_intin[VDI_INTINMAX];   
	short vdi_ptsin[2];   
	VDIPB vdi_params =               
	{                                
		&vdi_control[0],             /* vdi_control */
		&vdi_intin[0],               /* vdi_intin   */
		&vdi_ptsin[0],               /* vdi_ptsin   */
		0L,                          /* vdi_intout  */
		0L                           /* vdi_ptsout  */
	};
#endif
	register short n = vdi_str2array (str, vdi_intin);
	
	vdi_ptsin[0] = x;
	vdi_ptsin[1] = y;

	VDI_TRAP (vdi_params, handle, 241, 1,n);
}
