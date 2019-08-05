/* hello.c
 *    purpose: show the minimal calls needed to use curses
 *    outline: initialize, draw stuff, wait for input, quit
 */

#include <stdio.h>
#include <curses.h>

int main(int argc, char *argv[])
{
	initscr();                        /* turn on curses */

	clear();                          /* clear screen */
	move(10,20);                      /* row10, col20 */
	standout();                       /* reverse mode */
	addstr("Hello, world");           /* add a string */
	move(LINES-1, 0);                 /* move to LL   */

	refresh();                        /* update the screen */
	getch();                          /* wait for user input */

	endwin();                         /* turn off curses */

    return 0;
}
