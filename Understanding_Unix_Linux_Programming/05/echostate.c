#include <stdio.h>
#include <termios.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	/* the strcut to save terminal attributes */
	struct termios info;
	int rv;

	/* fd 0 is the standard input, attached to the keyboard */
	rv = tcgetattr(0, &info);    /* read value from driver */
	if(rv == -1)
	{
	    perror("tcgetattr");
		exit(1);
	}
	if(info.c_lflag & ECHO)
	{
	    printf("echo is on, since its bit is 1\n");
	}
	else
	{
	    printf("echo is off, since its bit is 0\n");
	}
    return 0;
}
