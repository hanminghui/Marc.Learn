/* incprint.c - one thread increments, the other prints
 *
 * compile: gcc -lpthread -o incprint incprint.c
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM 5

void* print_count(void*);

int counter;

int main(int argc, char *argv[])
{
	pthread_t t1;       /* one thread */

	pthread_create(&t1, NULL, print_count, NULL);
	for(int i = 0; i < NUM; i++)
	{
	    counter++;
		sleep(1);
	}
	pthread_join(t1, NULL);

    return 0;
}

void* print_count(void* m)
{
	for(int i = 0; i < NUM; i++)
	{
	    printf("count = %d\n", counter);
		sleep(1);
	}
	return NULL;
}
