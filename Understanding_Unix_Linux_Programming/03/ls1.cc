/* ls
 * version 1
 * list directory entries
 * sort, cpp version, use set to order
 * add -a
 */
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <iostream>
#include <set>
#include <string>

void names_add(const char * dirname);
void names_print_all();
void names_print();
std::set<std::string> names;

int main(int argc, char *argv[])
{
	if(argc == 1) /* no arguments */
	{
		names_add(".");
		names_print();
	}
	else if(strcmp(argv[1], "-a") == 0)
	{
		if(argc == 2)
		{
			names_add(".");
			names_print_all();
		}
		else
		{
			argc--;
			argv++;
			while(--argc)
			{
				names_add(*++argv);
				std::cout << *argv << ":" << std::endl;
				names_print_all();
				std::cout << std::endl;
			}
		}
	}
	else
	{
		while(--argc)
		{
			names_add(*++argv);
			std::cout << *argv << ":" << std::endl;
			names_print();
			std::cout << std::endl;
		}
	}
    return 0;
}

/* list files in directory called dirname
 */
void names_add(const char * dirname)
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
			std::string name = dirent_p->d_name;
			names.insert(name);
		}
	}
}

void names_print_all()
{
	for(auto name : names)
	{
		std::cout << name << std::endl;
	}
	names.clear();
}

void names_print()
{
	for(auto name : names)
	{
		if(name[0] != '.')
		{
			std::cout << name << std::endl;
		}
	}
	names.clear();
}
