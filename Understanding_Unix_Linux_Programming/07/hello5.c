/* hello5.c
 *    purpose: bounce a message back and forth across the screen
 */

#define LEFTEDGE       10
#define RIGHTEDGE      30
#define ROW            10

#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char message[] = "Hello";
	char blank[] = "     ";
	int dir = +1;
	int pos = LEFTEDGE;

	initscr();                        /* turn on curses */

	clear();                          /* clear screen */

	while(1)
	{
	    move(ROW, pos);
		addstr(message);                   /* draw string */
		move(LINES-1, COLS-1);             /* park the cursor */
		refresh();                         /* show string     */
		sleep(1);
		move(ROW, pos);                    /* move back */
		addstr(blank);                     /* erase string */
		pos += dir;                        /* advance position */
		if(pos >= RIGHTEDGE)               /* check for bounce */
		{
			dir = -1;
		}
		if(pos <= LEFTEDGE)
		{
		    dir = +1;
		}
	}

	endwin();                         /* turn off curses */

    return 0;
}
