#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>

#define oops(s,x) { perror(s); exit(x); }

int main(int argc, char *argv[])
{
	/* the strcut to save terminal attributes */
	struct termios info;
	int rv;

	/* fd 0 is the standard input, attached to the keyboard */
	rv = tcgetattr(0, &info);    /* read value from driver */
	if(rv == -1)
		oops("tcgetattr", 1)
	if(info.c_lflag & ECHO)
	{
// 	    printf("echo is on, since its bit is 1\n");
		info.c_lflag &= ~ECHO;
		tcsetattr(0, TCSANOW, &info);
		if(tcsetattr(0, TCSANOW, &info) == -1)
			oops("tcsetattr", 2)
	}
	else
	{
// 	    printf("echo is off, since its bit is 0\n");
	}
	sleep(5);
    return 0;
}
