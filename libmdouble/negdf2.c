/*----------------*/
/* libmathdoubbas */
/*----------------*/

#include <exec/types.h>
#include <exec/libraries.h>

union _dsi
{
	DOUBLE d;
	LONG i;
};

extern struct Library *MathIeeeDoubBasBase;

__stdargs DOUBLE __negdf2(DOUBLE x)
{
	register DOUBLE u asm("d0");

	asm("move.l 8(sp),d0; move.l 12(sp),d1; movea.l %2,a6; jsr -60(a6);" :
		"=r"(u) : "m"(x), "m"(MathIeeeDoubBasBase) :
		"d1", "a0", "a1", "a6", "fp0", "fp1", "cc", "memory");
	return u;
}
