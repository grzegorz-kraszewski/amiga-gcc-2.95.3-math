/*-----------------*/
/* libmtransdouble */
/*-----------------*/

extern struct Library *MathIeeeDoubTransBase;

__stdargs double sincos(double *z, double x)
{
	register double u asm("d0");

	asm("movea.l 8(sp),a0; move.l 12(sp),d0; move.l 16(sp),d1; movea.l %1,a6; jsr -54(a6);" :
		"=r"(u) : "m"(MathIeeeDoubTransBase) :
		"d1", "a0", "a1", "a6", "fp0", "fp1", "cc", "memory");
	return u;
}
