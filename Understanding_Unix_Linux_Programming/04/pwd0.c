/* pwd0.c
 *
 * a simplified pwd
 * print the present working directory
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

void print_dirname();
void dir_ino_to_name(int current_ino, char * namebuf, int buflen);
int get_inode(const char* );

int main(int argc, char *argv[])
{
	print_dirname();
	printf("\n");
    return 0;
}

void print_dirname()
{
	char current_name[BUFSIZ];
	int current_ino = get_inode(".");
	int parent_ino = get_inode("..");
	if(current_ino == parent_ino)
	{
		return;
	}
	else
	{
		chdir("..");
		dir_ino_to_name(current_ino, current_name, BUFSIZ);
		print_dirname();
		printf("/%s", current_name);
	}
}

void dir_ino_to_name(int current_ino, char * namebuf, int buflen)
{
	DIR * parent_dir_p = opendir(".");
	struct dirent * dirent_p;
	while((dirent_p = readdir(parent_dir_p)) != NULL)
	{
	    if(dirent_p->d_ino == current_ino)
	    {
			strncpy(namebuf, dirent_p->d_name, buflen);
			closedir(parent_dir_p);
			return;
	    }
	}
}

int get_inode(const char* filename)
{
	struct stat filestat;
	if(stat(filename, &filestat) == -1)
	{
	    perror("Cannot get stat");
		exit(1);
	}
	return filestat.st_ino;
}
