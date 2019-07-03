#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("you input %d arguments:\n", argc-1);
	while(argc--)
	{
		printf("%s\n", *argv++);
	}
    return 0;
}

