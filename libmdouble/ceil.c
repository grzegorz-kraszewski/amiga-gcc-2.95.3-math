/*------------*/
/* libmdouble */
/*------------*/

extern struct Library *MathIeeeDoubBasBase;

__stdargs double ceil(double x)
{
	register double u asm("d0");

	asm("move.l 8(sp),d0; move.l 12(sp),d1; movea.l %1,a6; jsr -96(a6);" :
		"=r"(u) : "m"(MathIeeeDoubBasBase) :
		"d1", "a0", "a1", "a6", "fp0", "fp1", "cc", "memory");
	return u;
}
