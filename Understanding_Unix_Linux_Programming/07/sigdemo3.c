/*   sigdemo3.c
 *
 *     purpose: show answers to signal questions
 *   question1: does the handler stay in effect after a signal arrives?
 *   question2: what if signalX arrives while handling signalX?
 *   question3: what if signalX arrives while handling signalY?
 *   question4: what happens to read() when a signal arrives?
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#define INPUTLEN 100

void quithandler(int s);
void inthandler(int s);

int main(int argc, char *argv[])
{
    char input[INPUTLEN];
	int nchars;

	signal(SIGINT, inthandler);            /* set handler */
	signal(SIGQUIT, quithandler);            /* set handler */
	do
	{
		printf("\nType a message (input quit to quit)\n");
		nchars = read(0, input, (INPUTLEN-1));
		if(nchars == -1)
			perror("read returned an error");
		else
		{
			input[nchars] = '\0';
			printf("You typed: %s", input);
		}
	}
	while(strncmp(input, "quit", 4) != 0);

    return 0;
}

void inthandler(int s)
{
    printf(" Received signal %d .. waiting\n", s);
	sleep(2);
	printf(" Leaving inthandler\n");
}

void quithandler(int s)
{
    printf(" Received signal %d .. waiting\n", s);
	sleep(3);
	printf(" Leaving quithandler\n");
}
