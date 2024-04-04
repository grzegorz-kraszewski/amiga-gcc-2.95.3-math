/*-----------*/
/* libmfloat */
/*-----------*/

extern struct Library *MathIeeeSingBasBase;

__stdargs float __negsf2(float x)
{
	register float r asm("d0");

	asm("move.l %1,d0; movea.l %2,a6; jsr -60(a6);" :
		"=r"(r) : "m"(x), "m"(MathIeeeSingBasBase) :
		"d1", "a0", "a1", "a6", "fp0", "fp1", "cc", "memory");
	return r;
}
