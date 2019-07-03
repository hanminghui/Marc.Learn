/* hello4.c
 *    purpose: show how to use erase, time, and draw for animation
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
		move(i, i+i);                    /* move back */
		addstr("               ");       /* erase line */
	}

	endwin();                         /* turn off curses */

    return 0;
}
