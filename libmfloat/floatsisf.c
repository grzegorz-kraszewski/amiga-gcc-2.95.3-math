/*-----------*/
/* libmfloat */
/*-----------*/

extern struct Library *MathIeeeSingBasBase;

__stdargs float __floatsisf(long i)
{
	register float r asm("d0");

	asm("move.l %1,d0; movea.l %2,a6; jsr -36(a6);" :
		"=r"(r) : "m"(i), "m"(MathIeeeSingBasBase) :
		"d1", "a0", "a1", "a6", "fp0", "fp1", "cc", "memory");
	return r;
}