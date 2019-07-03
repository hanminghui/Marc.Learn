/* write0.c
 *
 *    purpose: send messages to another terminal
 *     method: open the other terminal for output then
 *             copy from stdin to that terminal
 *      shows: a terminal is just a file supporting regular i/o
 *      usage: write0 ttyname
 *
 *  remember:
 *  change the executive file's user and grp to root and tty
 *  and add set-user-id to the file
 *  to run it without sudo to get permission
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>		// for open
#include <unistd.h>     // for close
#include <string.h>

int main(int argc, char *argv[])
{
	/* check args */
	if(argc != 2)
	{
	    printf("Usage: write0 ttyname\n");
		exit(1);
	}
	/* open devices */
	int tty_fd = 0;
	if((tty_fd = open(argv[1], O_WRONLY)) == -1)
	{
	    perror("failed to open terminal");
		exit(1);
	}
	char buf[BUFSIZ];  // BUFSIZ is defined in stdio.h
// 	printf("the BUFSIZ is %d\n", BUFSIZ);

	/* loop until EOF on input */
	while(fgets(buf, BUFSIZ, stdin) != NULL)
	{
		if(write(tty_fd, buf, strlen(buf)) == -1)
		{
		    break;
		}
	}

	close(tty_fd);
    return 0;
}
