#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t process_id = getpid();
	printf("I'm process number %d\n", process_id);

	sleep(10);

    return 0;
}
