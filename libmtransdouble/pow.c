/*------------------*/
/* libmathdoubtrans */
/*------------------*/

#include <exec/libraries.h>

extern struct Library *MathIeeeDoubTransBase;

__stdargs double pow(double x, double y)
{
	register double u asm("d0");

	asm("movea.l 16(sp),a0; move.l 20(sp),d1; move.l 24(sp),d2; move.l 28(sp),d3; "
		"movea.l %1,a6; jsr -90(a6);" :
		"=r"(u) : "m"(MathIeeeDoubTransBase) :
		"d1", "a0", "a1", "d2", "d3", "a6", "fp0", "fp1", "cc", "memory");
	return u;
}
