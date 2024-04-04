/*----------------*/
/* libmathdoubbas */
/*----------------*/

#include <exec/types.h>
#include <exec/libraries.h>

extern struct Library *MathIeeeDoubBasBase;

__stdargs LONG __fixdfsi(DOUBLE x)
{
	register LONG r asm("d0");

	asm("move.l 8(sp),d0; move.l 12(sp),d1; movea.l %1,a6; jsr -30(a6);" :
		"=r"(r) : "m"(MathIeeeDoubBasBase) :
		"d1", "a0", "a1", "a6", "fp0", "fp1", "cc", "memory");
	return r;
}
