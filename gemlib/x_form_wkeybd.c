
#include "gemx.h"


int
form_wkeybd (OBJECT * fo_ktree, int fo_kobject, int fo_kobnext, int fo_kchar,
	     int *fo_knxtobject, int *fo_knxtchar, int whandle)
{
	aes_intin[0] = fo_kobject;
	aes_intin[1] = fo_kchar;
	aes_intin[2] = fo_kobnext;
	aes_intin[3] = whandle;
	aes_addrin[0] = (long) fo_ktree;
	aes_control[0] = 64;
	aes_control[1] = 4;
	aes_control[2] = 3;
	aes_control[3] = 1;
	aes_control[4] = 0;
	aes (&aes_params);
	*fo_knxtobject = aes_intout[1];
	*fo_knxtchar = aes_intout[2];
	return aes_intout[0];
}