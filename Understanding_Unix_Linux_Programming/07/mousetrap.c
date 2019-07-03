/* mousetrap.c
 *    to show the unreliable of original signal model
 *    a mouse would get by
 *    signal - mouse
 *    handler - mousetrap
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>



void handler(int s);

int main(int argc, char *argv[])
{
    signal(SIGINT, handler);
	pause();
    return 0;
}

void handler(int s)
{
	printf("mouse catched!\n");

	/* once catched, the mousetrap is ineffective */
    /* process is vulnerable here */
	while(1)
	{
	}
	/* need to reset the mousetrap(signal handler) */
}
