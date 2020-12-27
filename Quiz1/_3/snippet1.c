#include <stdio.h>


void main()
{
	char x[64];
	int *ptr = (int *)x;
	for (int i = 0; i < 16; ++i)
	{
		/* code */
		*(ptr+i) = *(x+4);
	}
	return;
}