/* who3.cc
 * a first version of the who programs
 * open, read UTMP file, and show results
 *
 * users only
 * print time correctly
 *
 * use utmplib to manage the buffer
 */
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "utmplib.h"

#define SHOWHOST

void show_info(struct utmp *);

int main(int argc, char *argv[])
{
	struct utmp * utbufp;

	if(openutmp(UTMP_FILE) == -1)
	{
	    perror(UTMP_FILE);
		exit(1);
	}
	while((utbufp = getutmp()) != ((struct utmp *)NULL))
	{
	    show_info(utbufp);
	}
	closeutmp();
	return 0;
}

void show_info(struct utmp *utbufp)
{
	if(utbufp->ut_type != USER_PROCESS)		/* users only */
	{
	    return;
	}
    printf("%-8.8s", utbufp->ut_user);
	printf(" ");
    printf("%-8.8s", utbufp->ut_line);
	printf(" ");
	time_t login_time = utbufp->ut_tv.tv_sec;
	char timebuf [80];
	strftime(timebuf, 80, "%F %R", localtime(&login_time));
    printf("%s", timebuf);
	printf(" ");
#ifdef SHOWHOST
    printf("(%s)", utbufp->ut_host);
#endif
	printf("\n");
}
