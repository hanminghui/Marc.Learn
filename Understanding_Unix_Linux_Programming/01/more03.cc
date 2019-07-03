/* more03.cc
 * version 0.3 of more
 * read and print some lines then pause for a few special commands
 *
 * read from /dev/tty
 *
 * turn off echo and icanon
 *
 * get terminal size
 */
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

void options(std::fstream& myfile);
void readmore(std::fstream& myfile);

int linesperpage;

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		std::cout << "Usage: more [filepath]" << std::endl;
		return 1;
	}

	struct termios tp;
	if(tcgetattr(STDIN_FILENO, &tp) == -1)     /* get terminal attributes */
	{
	    perror("tcgetattr");
		exit(1);
	}
	tp.c_lflag &= ~ECHO; /* turn echo off */
	tp.c_lflag &= ~ICANON; /* turn CANON off */
	if(tcsetattr(STDIN_FILENO, TCSANOW, &tp) == -1) /* set attributes */
	{
	    perror("tcsetattr");
		exit(1);
	}

	struct winsize wbuf;
	if(ioctl(STDIN_FILENO, TIOCGWINSZ, &wbuf) == -1)
	{
	    perror("getwinsize");
		exit(1);
	}
	linesperpage = wbuf.ws_row - 1;

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
	for(int i = 0; i < linesperpage; ++i)
	{
		std::getline(myfile, line);
		std::cout << line << std::endl;
	}
	std::cout << "\033[7m PRESS n to next page, q to quit: \033[m";
	fflush(stdout);
}
