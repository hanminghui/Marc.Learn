/* more02.cc
 * version 0.2 of more
 * read and print some lines then pause for a few special commands
 *
 * read from /dev/tty
 */
#include <iostream>
#include <string>
#include <fstream>

#define LINESPERPAGE 24

void options(std::fstream& myfile);
void readmore(std::fstream& myfile);

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		std::cout << "Usage: more [filepath]" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::fstream myfile(filename);
	if(!myfile.is_open())
	{
		std::cout << "Failed to open the file or the file not exists." << std::endl;
	}
	else
	{
		options(myfile);
	}
    return 0;
}

void options(std::fstream& myfile)
{
	/* 2 method to clear the screen in unix */
// 	std::cout << "\x1B[2J\x1B[H";
	std::cout << "\033c";
	readmore(myfile);
	while(true)
	{
		std::fstream keypress("/dev/tty");
		char choice = 0;
		keypress.get(choice);
		if(choice == 'n')
		{
			std::cout << "\x1B[2J\x1B[H";
			readmore(myfile);
			continue;
		}
		else if(choice == 'q')
		{
			exit(0);
		}
		else
		{
			continue;
		}
	}
}

void readmore(std::fstream& myfile)
{
	std::string line;
	for(int i = 0; i < LINESPERPAGE; ++i)
	{
		std::getline(myfile, line);
		std::cout << line << std::endl;
	}
	std::cout << "\033[7m PRESS n to next page, q to quit: \033[m";
}
