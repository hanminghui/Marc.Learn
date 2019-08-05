/* two ways to get the calendar time */
#include <stdio.h>
#include <time.h>     /* for time()         */
#include <sys/time.h> /* for gettimeofday() */

int main(int argc, char *argv[])
{
	struct timeval tv;
    if(gettimeofday(&tv, NULL) == -1)
    {
        perror("gettimeofday");
    }
	else
	{
		printf("time: %d\n", time(NULL));
		printf("sec  :%d\n", tv.tv_sec);
		printf("usec :%d\n", tv.tv_usec);
		printf("%s\n", ctime(&tv.tv_sec));
	}
    return 0;
}
