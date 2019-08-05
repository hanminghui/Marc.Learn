/* hello3.c
 *    purpose: using refresh and sleep for animated affects
 *    outline: initialize, draw stuff, wrap up
 */

#include <stdio.h>
#include <curses.h>
#include <unistd.h>

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
		refresh();
		sleep(1);
	}

	endwin();                         /* turn off curses */

    return 0;
}
