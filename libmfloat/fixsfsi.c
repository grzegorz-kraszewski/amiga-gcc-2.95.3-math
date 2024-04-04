/*-----------*/
/* libmfloat */
/*-----------*/

extern struct Library *MathIeeeSingBasBase;

__stdargs long __fixsfsi(float x)
{
	register long r asm("d0");

	asm("move.l %1,d0; movea.l %2,a6; jsr -30(a6);" :
		"=r"(r) : "m"(x), "m"(MathIeeeSingBasBase) :
		"d1", "a0", "a1", "a6", "fp0", "fp1", "cc", "memory");
	return r;
}
