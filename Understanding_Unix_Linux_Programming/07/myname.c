/* myname.c
 *
 * print process name and PID
 * info from /proc/self/stat
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    FILE * fp;
	fp = fopen("/proc/self/stat", "r");

	int pid = 0;
	char * name;

	fscanf(fp, "%d", &pid);
	fscanf(fp, "%s", name);

	printf("I'm process %d, my name is %s\n", pid, name);
	fflush(stdout);
	sleep(100);
    return 0;
}
