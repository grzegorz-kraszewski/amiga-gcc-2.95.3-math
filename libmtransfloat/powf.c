/*----------------*/
/* libmtransfloat */
/*----------------*/

#include <exec/libraries.h>

extern struct Library *MathIeeeSingTransBase;

__stdargs float powf(float x, float y)
{
	register float r asm("d0");

	asm("move.l %1,d0; move.l %2,d1; movea.l %3,a6; jsr -90(a6);" :
		"=r"(r) : "m"(x), "m"(y), "m"(MathIeeeSingTransBase) :
		"d1", "a0", "a1", "a6", "fp0", "fp1", "cc", "memory");
	return r;
}
