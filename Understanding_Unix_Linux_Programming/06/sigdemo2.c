/* sigdemo2.c
 *  shows how to ignore a signal
 *  run this and press Ctrl-C a few times
 *  press Ctrl-\ to kill this one
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void f(int);

int main(int argc, char *argv[])
{
	signal(SIGINT, SIG_IGN);
	printf("you can't stop me!\n");
	while(1)
	{
	    printf("haha\n");
		sleep(1);
	}
    return 0;
}
