/* mem.c
 *
 * print the address of the pointer by malloc
 *
 * you need first run 'sudo sysctl -w kernel.randomize_va_space=0'
 * to turn disable address space randomization
 *
 * then './mem &; ./mem &' to run two of mem.c
 *
 * remember set kernel.randomize_va_space to 2
 */

/* ASLR -- address space layout randomization
 * to check:
 *     cat /proc/sys/kernel/randomize_va_space
 *     sysctl -a --pattern randomize
 * to set:
 *     sudo sysctl -w kernel.randomize_va_space=?
 * settings:
 *     0 = Disabled
 *     1 = Conservative Randomization
 *     2 = Full Randomization
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    int * p = malloc(sizeof(int));
	assert(p != NULL);
	printf("(%d) address of p: %08x\n", getpid(), (unsigned)p);
	*p = 0;
	while(1)
	{
		sleep(1);
		*p = *p + 1;
		printf("(%d) p: %d\n", getpid(), *p);
	}
    return 0;
}
