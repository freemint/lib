

#include "gem_vdiP.h"

/** returns a string from the keyboard. "INPUT STRING, SAMPLE MODE"
 *  returns if the maximum string length is reached, if the user has pressed RETURN 
 *  or if the user has not pressed a key.
 *
 *  @param handle Device handle
 *  @param len is the maximum length of the string returned in intout. If max_length 
 *         is negative, the absolute value is considered to be the maximum length and scan 
 *         codes are returned instead of ASCII values.
 *  @param echo 0: no output 1: echo
 *  @param echoxy 
 *  @param str input buffer
 *
 *  @return 0 (no input) or the length of the string otherwise.

 *
 *  @since all VDI versions
 *
 */

short
udef_vsm_string (short handle, short len, short echo, short echoxy[], char *str)
{

	VDI_PARAMS(_VDIParBlk.vdi_control, _VDIParBlk.vdi_intin, _VDIParBlk.vdi_ptsin, _VDIParBlk.vdi_intout, vdi_dummy );
	
	_VDIParBlk.vdi_intin[0]      = len;
	_VDIParBlk.vdi_intin[1]      = echo;
	*(long*)_VDIParBlk.vdi_ptsin = *(long*)echoxy;
	
	VDI_TRAP (vdi_params, handle, 31, 1,2);
	
	vdi_array2str (_VDIParBlk.vdi_intout, str, _VDIParBlk.vdi_control[4]);
	
	return _VDIParBlk.vdi_control[4];
}