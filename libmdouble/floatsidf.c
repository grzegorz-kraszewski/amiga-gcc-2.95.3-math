/*------------*/
/* libmdouble */
/*------------*/

extern struct Library *MathIeeeDoubBasBase;

__stdargs double __floatsidf(long i)
{
	register double r asm("d0");

	asm("move.l %1,d0; movea.l %2,a6; jsr -36(a6);" :
		"=r"(r) : "m"(i), "m"(MathIeeeDoubBasBase) :
		"d1", "a0", "a1", "a6", "fp0", "fp1", "cc", "memory");
	return r;
}