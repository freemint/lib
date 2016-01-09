/*
 *  $Id$
 */

#include "gem_vdiP.h"
#include "mt_gemx.h"
#include "vdi_userdef.h"


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
 *  @note Use it for work with userdef, not reentrant function!
 */

void
udef_v_ftext (short handle, short x, short y, const char *str)
{
	short n = vdi_str2array_n (str, _VDIParBlk.vdi_intin, VDI_INTINMAX);

	VDI_PARAMS(_VDIParBlk.vdi_control, _VDIParBlk.vdi_intin, _VDIParBlk.vdi_ptsin, vdi_dummy, vdi_dummy);
	
	_VDIParBlk.vdi_ptsin[0] = x;
	_VDIParBlk.vdi_ptsin[1] = y;

	VDI_TRAP (vdi_params, handle, 241, 1,n);
}
