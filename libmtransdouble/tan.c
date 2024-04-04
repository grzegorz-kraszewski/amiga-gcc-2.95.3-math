/*------------------*/
/* libmathdoubtrans */
/*------------------*/

#include <exec/libraries.h>

extern struct Library *MathIeeeDoubTransBase;

__stdargs double tan(double x)
{
	register double u asm("d0");

	asm("move.l 8(sp),d0; move.l 12(sp),d1; movea.l %1,a6; jsr -48(a6);" :
		"=r"(u) : "m"(MathIeeeDoubTransBase) :
		"d1", "a0", "a1", "a6", "fp0", "fp1", "cc", "memory");
	return u;
}
