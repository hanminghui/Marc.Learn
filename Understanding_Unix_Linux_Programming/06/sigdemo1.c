/* sigdemo1.c
 *  shows how a signal handler works
 *  run this and press Ctrl-C a few times
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void f(int);

int main(int argc, char *argv[])
{
	int i;
	signal(SIGINT, f);       /* install the handler */
	for(i = 0; i < 10; i++)   /* do something else   */
	{
	    printf("hello\n");
		sleep(1);
	}
    return 0;
}

/* this function is called */
void f(int signum)
{
	printf("OUCH!\n");
}
