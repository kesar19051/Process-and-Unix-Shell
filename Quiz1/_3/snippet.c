#include <stdio.h>


void main()
{
	char x[64];
	long int *ptr = (long int *)x;

	for (int i = 0; i < 8; ++i)
	{
		/* code */
		*(ptr+i) = *(x+8);
	}
	return;
}