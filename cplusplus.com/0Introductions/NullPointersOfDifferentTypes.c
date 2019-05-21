#include <stdio.h>

int main ()
{
	int * p_int = NULL;
	double * p_double = NULL;
	printf("p_int: %d\n", (int)p_int);
	printf("p_double: %d\n", (int)p_double);
	printf("size of p_int: %d\n", sizeof(p_int));
	printf("size of p_double: %d\n", sizeof(p_double));
	p_int ++;
	p_double ++;
	printf("p_int: %d\n", (int)p_int);
	printf("p_double: %d\n", (int)p_double);
	return 0;
}
