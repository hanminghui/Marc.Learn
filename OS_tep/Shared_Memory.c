#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	void * heap_1 = malloc(12);
	int stack_value = 100;

	int shm_id0, shm_id1;
	void *shm0, *shm1;
	printf("shared meomery address before attach: %p\n", (void*)shm0);
	shm_id0 = shmget(IPC_PRIVATE, 12, IPC_CREAT | 0666);
	shm0 = shmat(shm_id0, NULL, SHM_W);
	shm_id1 = shmget(IPC_PRIVATE, 12, IPC_CREAT | 0666);
	shm1 = shmat(shm_id1, heap_1, SHM_W);

	char* str = "hello world";
	memcpy(shm1, str, 12);

	int * heap_2 = (int*)malloc(sizeof(int) * 100);

	printf("shm_id0: %d\n", shm_id0);
	printf("shm_id1: %d\n", shm_id1);
	printf("stack_value address in   : %p\n", &stack_value);
	printf("shared meomery 0 address in: %p\n", (void*)shm0);
	printf("shared meomery 1 address in: %p\n", (void*)shm1);
	printf("heap_1 address in        : %p\n", heap_1);
	printf("heap_2 address in        : %p\n", heap_2);
	printf("shm value is %s\n", (char*)shm0);
	printf("heap_1 value is %s\n", (char*)heap_1);

	sleep(10000);
    return 0;
}
