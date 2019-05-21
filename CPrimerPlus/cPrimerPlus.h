// functions constructed when learning C Primer Plus
// Marc Han
// 20160521

#include <ctype.h>

void showSizeofTypes(void);

// Tools for making menu
void showStar(int);
void showBlank(int);
void showUnderScore(int);

int getFirst(void);
// Math
unsigned long Fibonacci(int);

// Functions Definition

void showSizeofTypes(void)
{
	printf("\nIn This system,\n");
	printf("The size of        char is %4d bytes.\n", sizeof(char));
	printf("The size of       short is %4d bytes.\n", sizeof(short));
	printf("The size of         int is %4d bytes.\n", sizeof(int));
	printf("The size of        long is %4d bytes.\n", sizeof(long));
	printf("The size of   long long is %4d bytes.\n", sizeof(long long));
	printf("The size of       float is %4d bytes.\n", sizeof(float));
	printf("The size of      double is %4d bytes.\n", sizeof(double));
	printf("The size of long double is %4d bytes.\n", sizeof(long double));
}

void showStar(int n)
{
	for (int i = 0; i < n; i++)
		putchar('*');
	putchar('\n');
}

void showBlank(int n)
{
	for (int i = 0; i < n; i++)
		putchar(' ');
}

void showUnderScore(int n)
{
	for (int i = 0; i < n; i++)
		putchar('_');
	putchar('\n');
}

int getFirst(void)
{
	int ch;
	ch = getchar();
	while (isspace(ch))			// need ctype.h
		ch = getchar();
	while (getchar() != '\n')
		continue;
	return ch;
}

unsigned long Fibonacci(int n)
{
	unsigned long first, second, next;
	int i;
	first = 0;
	second = 1;
	next = 1;
	for (i = 1; i < n; i++)
	{
		next = first + second;
		first = second;
		second = next;
	}
	return next;
}
