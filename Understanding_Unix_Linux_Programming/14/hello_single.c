/* hello_single.c
 *
 * a single threaded hello world program
 */

#include <stdio.h>
#include <unistd.h>

#define NUM 5

void print_msg(char * m);

int main(int argc, char *argv[])
{
    print_msg("hello ");
	print_msg("world\n");
    return 0;
}

void print_msg(char * m)
{
	int i;
	for(i = 0; i < NUM; i++)
	{
	    printf("%s", m);
		fflush(stdout);
		sleep(1);
	}
}
