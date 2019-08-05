/* bounce2d_v1.c version1.0
 *
 *    compile: cc bounce2d.c set_ticker.c -lcurses -o bounce2d
 */

#include <curses.h>
#include <signal.h>

#include "bounce.h"
#include "set_ticker.h"

struct ppball the_ball;

void set_up();
void wrap_up();
void ball_move(int signum);
void update_paddle();
int bounce_or_lose(struct ppball * bp);

/* the main loop */

int main(int argc, char *argv[])
{
	int c;

	set_up();

	while((c = getchar()) != 'q')
	{
		if(c == 'f') the_ball.x_ttm--;
		else if(c == 's') the_ball.x_ttm++;
		else if(c == 'F') the_ball.y_ttm--;
		else if(c == 'S') the_ball.y_ttm++;
		else if(c == 'h' && the_ball.paddle_left > LEFT_EDGE)
		{
			the_ball.paddle_left--;
			update_paddle();
		}
		else if(c == 'l' && the_ball.paddle_left < (RIGHT_EDGE - the_ball.paddle_length))
		{
			the_ball.paddle_left++;
			update_paddle();
		}
	}
	wrap_up();
    return 0;
}

/* 
 * init structure and other stuff
 */
void set_up()
{
	the_ball.y_pos = Y_INIT;
	the_ball.x_pos = X_INIT;
	the_ball.y_ttg = the_ball.y_ttm = Y_TTM;
	the_ball.x_ttg = the_ball.x_ttm = X_TTM;
	the_ball.y_dir = 1;
	the_ball.x_dir = 1;
	the_ball.symbol = DFL_SYMBOL;

	initscr();
	noecho();
	crmode();
	curs_set(0);

	signal(SIGINT, SIG_IGN);
	for(int i = LEFT_EDGE-1; i <= RIGHT_EDGE+1; i++)
	{
	    mvaddch(TOP_ROW-1, i, '*');
	}
	for(int i = TOP_ROW; i <= BOT_ROW+1; i++)
	{
	    mvaddch(i, LEFT_EDGE-1, '*');
	    mvaddch(i, RIGHT_EDGE+1, '*');
	}

	the_ball.paddle_length = PADDLE_LENGTH;
	the_ball.paddle_left = (LEFT_EDGE + RIGHT_EDGE - the_ball.paddle_length) / 2;
	for(int i = the_ball.paddle_left; 
			i <= the_ball.paddle_left + the_ball.paddle_length; i++)
	{
		mvaddch(BOT_ROW+1, i, '=');
	}
	
	mvaddch(the_ball.y_pos, the_ball.x_pos, the_ball.symbol);
	refresh();

	signal(SIGALRM, ball_move);
	set_ticker(1000 / TICKS_PER_SEC); /* send millisecs per tick */
}

void wrap_up()
{
	set_ticker(0);
	endwin();       /* put back to normal */
}

void ball_move(int signum)
{
    int y_cur, x_cur, moved;

	signal(SIGALRM, SIG_IGN);      /* dont get caught now */
	y_cur = the_ball.y_pos;
	x_cur = the_ball.x_pos;
	moved = 0;

	if(the_ball.y_ttm > 0 && the_ball.y_ttg-- == 1)
	{
	    the_ball.y_pos += the_ball.y_dir;   /* move */
		the_ball.y_ttg = the_ball.y_ttm;    /* reset */
		moved = 1;
	}
	if(the_ball.x_ttm > 0 && the_ball.x_ttg-- == 1)
	{
	    the_ball.x_pos += the_ball.x_dir;   /* move */
		the_ball.x_ttg = the_ball.x_ttm;    /* reset */
		moved = 1;
	}

	if(moved)
	{
	    mvaddch(y_cur, x_cur, BLANK);
		mvaddch(the_ball.y_pos, the_ball.x_pos, the_ball.symbol);
		bounce_or_lose(&the_ball);
		move(LINES-1, COLS-1);
		refresh();
	}
	signal(SIGALRM, ball_move);        /* for unreliable systems */
}

void update_paddle()
{
	for(int i = LEFT_EDGE; i <= RIGHT_EDGE; i++)
	{
	    mvaddch(BOT_ROW+1, i, ' ');
	}
	for(int i = the_ball.paddle_left; 
			i <= the_ball.paddle_left + the_ball.paddle_length; i++)
	{
		mvaddch(BOT_ROW+1, i, '=');
	}
	refresh();
}

int bounce_or_lose(struct ppball * bp)
{
	int return_val = 0;
	if(bp->y_pos == TOP_ROW)
	{
	    bp->y_dir = 1;
		return_val = 1;
	}
	else if(bp->y_pos == BOT_ROW)
	{
	    bp->y_dir = -1;
		return_val = 1;
	}
	if(bp->x_pos == LEFT_EDGE)
	{
	    bp->x_dir = 1;
		return_val = 1;
	}
	else if(bp->x_pos == RIGHT_EDGE)
	{
	    bp->x_dir = -1;
		return_val = 1;
	}
	return return_val;
}
