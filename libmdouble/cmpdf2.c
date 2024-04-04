/*------------*/
/* libmdouble */
/*------------*/

extern struct Library *MathIeeeDoubBasBase;

__stdargs long __cmpdf2(double x, double y)
{
	register long r asm("d0");

	asm("move.l 16(sp),d0; move.l 20(sp),d1; move.l 24(sp),d2; move.l 28(sp),d3; movea.l %1,a6; jsr -42(a6);" :
		"=r"(r) : "m"(MathIeeeDoubBasBase) :
		"d1", "a0", "a1", "d2", "d3", "a6", "fp0", "fp1", "cc", "memory");
	return r;
}
