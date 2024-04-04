/*-------------*/
/* libminteger */
/*-------------*/

#include <exec/libraries.h>

extern struct Library *UtilityBase;

/* According to documentation UDivMod32() preserves A0 and A1. */

__stdargs long __umodsi3(long x, long y)
{
	register long r asm("d1");

	asm("move.l %1,d0; move.l %2,d1; movea.l %3,a6; jsr -156(a6);" :
		"=r"(r) : "m"(x), "m"(y), "m"(UtilityBase) :
		"d1", "a6", "fp0", "fp1", "cc", "memory");
	return r;
}
