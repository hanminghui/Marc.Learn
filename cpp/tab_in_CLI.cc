#include <cstdio>
#include <cstring>

int main(int argc, char *argv[])
{
	for(int i = 0; i < argc; i++)
	{
		printf("parameter %d :\n", i);
        printf("%d %s\n", strlen(argv[i]), argv[i]);
		if(strcmp(argv[i], "\\t") == 0)
		{
			printf("a\tb\n");
		}
		if(strcmp(argv[i], "\t") == 0)
		{
			printf("%sliteral tab", argv[i]);
		}
	}
    return 0;
}
