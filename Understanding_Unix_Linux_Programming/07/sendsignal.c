/* sendsignal.c
 *
 * use kill to send signal to another process
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
	    printf("Usage: sendsignal [pid]\n");
		exit(1);
	}
	int input = atoi(argv[1]);
	printf("send SIGINT to process %d\n", input);

	pid_t pid = input;
    kill(pid,SIGINT);
    return 0;
}
