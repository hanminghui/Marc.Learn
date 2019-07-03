/* ls
 * version 1
 * list directory entries
 * sort
 * add -a
 */
#include <stdio.h>
#include <dirent.h>

void list(const char * dirname);

int main(int argc, char *argv[])
{
	if(argc == 1) /* no arguments */
	{
		list(".");
	}
	else if(argc == 2)
	{
	    list(argv[1]);
	}
    return 0;
}

/* list files in directory called dirname
 */
void list(const char * dirname)
{
	DIR * dir_p;
	if((dir_p = opendir(dirname)) == NULL)
	{
		perror("cannot open directory");
	}
	else
	{
		while(struct dirent * dirent_p = readdir(dir_p))
		{
			printf("%s\n", dirent_p->d_name);
		}
	}
}
