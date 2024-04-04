/*---------------*/
/* libmathsingle */
/* fbaserel      */
/*---------------*/

#include <exec/types.h>
#include <exec/libraries.h>

extern struct Library *MathIeeeSingBasBase;

__stdargs FLOAT __addsf3(FLOAT x, FLOAT y)
{
	register FLOAT r asm("d0");

	asm("move.l %1,d0; move.l %2,d1; movea.l %3,a6; jsr -66(a6);" :
		"=r"(r) : "m"(x), "m"(y), "m"(MathIeeeSingBasBase) :
		"d1", "a0", "a1", "a6", "fp0", "fp1", "cc", "memory");
	return r;
}