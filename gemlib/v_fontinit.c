/*
 *  $Id$
 */

#include "gem_vdiP.h"

/** this escape install the given font as font system.
 *
 *  @param handle Device handle
 *  @param font_header
 *
 *  @since ???
 *
 *  @note this function is not descibed in any doc. Usage at your
 *  own risk! BTW, it seems that characters must be 8 pixels width (constant),
 *  and the format used must be the motorola format.
 *
 */

void
v_fontinit (short handle, const void * font_header)
{
#if USE_LOCAL_VDIPB
	short vdi_control[VDI_CNTRLMAX]; 
	VDI_PARAMS(vdi_control, &font_header, 0L, 0L, 0L );
#else
	*(void**)vdi_intin = font_header;
#endif
		
	VDI_TRAP_ESC (vdi_params, handle, 5,102, 0,2);
}