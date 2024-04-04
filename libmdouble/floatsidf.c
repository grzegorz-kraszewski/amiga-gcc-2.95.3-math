/*----------------*/
/* libmathdoubbas */
/*----------------*/

#include <exec/types.h>
#include <exec/libraries.h>

extern struct Library *MathIeeeDoubBasBase;

__stdargs DOUBLE __floatsidf(LONG i)
{
	register DOUBLE r asm("d0");

	asm("move.l %1,d0; movea.l %2,a6; jsr -36(a6);" :
		"=r"(r) : "m"(i), "m"(MathIeeeDoubBasBase) :
		"d1", "a0", "a1", "a6", "fp0", "fp1", "cc", "memory");
	return r;
}