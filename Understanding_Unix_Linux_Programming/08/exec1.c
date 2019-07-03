/* exec1.c
 *   run a program as a child process
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    char *arglist[2];
	arglist[0] = "./getpid";
	arglist[1] = 0;
	pid_t Pid = getpid();
	printf("I'm process number %d\n", Pid);
	printf("* * * About to exec child process \n");
	pid_t childPid;
	int status;
	switch(childPid = fork())
	{
		case -1: "fork error"; break;
		case 0: execvp("./getpid", arglist); break;
		default : wait(&status);
	}
	printf("* * * child process is done. bye\n");
    return 0;
}
