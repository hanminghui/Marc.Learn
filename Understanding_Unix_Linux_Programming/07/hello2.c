/* hello2.c
 *    purpose: show how to use curses functions with a loop
 *    outline: initialize, draw stuff, wrap up
 */

#include <stdio.h>
#include <curses.h>

int main(int argc, char *argv[])
{
	initscr();                        /* turn on curses */

	clear();                          /* clear screen */

	for(int i = 0; i < LINES; i++)
	{
	    move(i, i+i);
		if(i % 2 == 1)
		{
		    standout();
		}
		char buf[15];
		snprintf(buf, 15, "Hello, world%d", i);
		addstr(buf);
		if(i % 2 == 1)
		{
		    standend();
		}
	}

	refresh();                        /* update the screen */
	getch();                          /* wait for user input */

	endwin();                         /* turn off curses */

    return 0;
}
