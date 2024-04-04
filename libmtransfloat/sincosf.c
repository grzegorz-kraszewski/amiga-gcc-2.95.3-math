/*----------------*/
/* libmtransfloat */
/*----------------*/

#include <exec/libraries.h>

extern struct Library *MathIeeeSingTransBase;

__stdargs float sincosf(float *z, float x)
{
	register float r asm("d0");

	asm("move.l %2,d0; movea.l %1,a0; movea.l %3,a6; jsr -54(a6);" :
		"=r"(r) : "m"(z), "m"(x), "m"(MathIeeeSingTransBase) :
		"d1", "a0", "a1", "a6", "fp0", "fp1", "cc", "memory");
	return r;
}
