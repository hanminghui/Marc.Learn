/* play_again4.c
 *
 *  purpose: ask if user wants another transaction
 *   method: ask a question, wait for yes/no answer
 *  returns: 0=>yes, 1=>no
 *   better: reset terminal mode on Interrupt
 *
 * version 0.4
 *   immediate response
 *   no echo, and ignore the unacceptable input
 *   nonblocking mode for timeouts
 *   reset terminal modes on SIGINT, ignores SIGQUIT
 *
 */
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

#define QUESTION     "Do you want another transaction?"
#define TRIES        3             /* max tries */
#define SLEEPTIME    2             /* time per try */
#define BEEP         putchar('\a') /* alert user */

int get_ok_char();
int get_response(const char *, int);
void set_noecho_crmode();
void set_nodelay_mode();
void tty_mode(int);
void ctrl_c_handler(int);

int main(int argc, char *argv[])
{
	int response;

	tty_mode(0);                         /* save tty mode */
	set_noecho_crmode();                 /* set char-by-char mode */
	set_nodelay_mode();                  /* noinput => EOF */
	signal(SIGINT, ctrl_c_handler);      /* handle SIGNAL INT */
	signal(SIGQUIT, SIG_IGN);            /* ignore SIGNAL QUIT */
	response = get_response(QUESTION, TRIES);   /* get response */
	tty_mode(1);                         /* restore tty mode */

	return response;
}

int get_response(const char * question, int maxtries)
{
	int input;
	printf("%s (y/n)?", question);
	fflush(stdout);                         /* force output */
	while(1)
	{
		sleep(SLEEPTIME);
		input = tolower(get_ok_char());
		if(input == 'y')
		{
			printf("\n");
		    return 0;
		}
		if(input == 'n')
		{
			printf("\n");
		    return 1;
		}
		if(maxtries-- == 0)
		{
		    return 2;
		}
		BEEP;
	}
}

int get_ok_char()
{
    int c;
	while((c = getchar()) != EOF && strchr("yYnN", c) == NULL)
		;
	return c;
}

void set_noecho_crmode()
{
	struct termios ttystate;

	tcgetattr(0, &ttystate);
	ttystate.c_lflag       &= ~ICANON;       /* no buffering */
	ttystate.c_lflag       &= ~ECHO;         /* no echo */
	ttystate.c_cc[VMIN]    =  1;             /* get 1 char at a time */
	tcsetattr(0, TCSANOW, &ttystate);
}

void set_nodelay_mode()
{
    int termflags;
	termflags = fcntl(0, F_GETFL);
	termflags |= O_NDELAY;
	fcntl(0, F_SETFL, termflags);
}

void tty_mode(int how)
/* how=0  =>  save current mode,
 * how=1  =>  restore current mode
 *
 * this version handles termios and fcntl flags
 */
{
    static struct termios original_mode;
	static int original_flags;
	static int stored = 0;

	if(how == 0)
	{
	    tcgetattr(0, &original_mode);
		original_flags = fcntl(0, F_GETFL);
		stored = 1;
	}
	else if (stored)
	{
	    tcsetattr(0, TCSANOW, &original_mode);
		fcntl(0, F_SETFL, original_flags);
	}
}

void ctrl_c_handler(int signum)
{
    tty_mode(1);
	printf("\nkilled, tty settings restored.\n");
	exit(1);
}
