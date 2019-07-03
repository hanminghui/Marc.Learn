#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void print_stat(const char * );

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printf("Usage: file_stat [filename]\n");
	}
	else
	{
	    print_stat(argv[1]);
	}
    return 0;
}

void print_stat(const char * filename)
{
	struct stat statbuf;
	if(stat(filename, &statbuf) != -1)
	{
		printf("   mode: %o\n", statbuf.st_mode);
		printf("  links: %d\n", statbuf.st_nlink);
		printf("   user: %d\n", statbuf.st_uid);
		printf("  group: %d\n", statbuf.st_gid);
		printf("   size: %d\n", statbuf.st_size);
		printf("modtime: %d\n", statbuf.st_mtim);
		printf("   name: %s\n", filename);
		printf("\n");
		printf(" blocks: %d\n", statbuf.st_blocks);
		printf("blksize: %d\n", statbuf.st_blksize);
	}
}
