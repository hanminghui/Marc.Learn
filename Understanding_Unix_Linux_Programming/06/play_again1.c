/* play_again1.c
 *
 *  purpose: ask if user wants another transaction
 *   method: ask a question, wait for yes/no answer
 *  returns: 0=>yes, 1=>no
 *   better: do no echo inappropriate input
 *
 * version 0.1
 *   immediate response
 *
 */
#include <stdio.h>
#include <termios.h>

#define QUESTION     "Do you want another transaction?"

int get_response(const char *);
int tty_mode(int how);
void set_crmode();

int main(int argc, char *argv[])
{
	int response;

	tty_mode(0);                         /* save tty mode */
	set_crmode();                        /* set char-by-char mode */
	response = get_response(QUESTION);   /* get response */
	tty_mode(1);                         /* restore tty mode */

	return response;
}

int get_response(const char * question)
{
	int input;
	printf("%s (y/n)?", question);
	while(1)
	{
		switch(input = getchar())
		{
			case 'y': 
			case 'Y': printf("\n"); return 0;
			case 'n': 
			case 'N': 
			case EOF: printf("\n"); return 1;
			default : 
					  printf("\ncannot understand %c, ", input);
					  printf("Please type y or n\n");
		}
	}
}

void set_crmode()
{
	struct termios ttystate;

	tcgetattr(0, &ttystate);
	ttystate.c_lflag       &= ~ICANON;       /* no buffering */
	ttystate.c_cc[VMIN]    =  1;             /* get 1 char at a time */
	tcsetattr(0, TCSANOW, &ttystate);
}

int tty_mode(int how)
/* how=0  =>  save current mode,
 * how=1  =>  restore current mode
 */
{
    static struct termios original_mode;
	if(how == 0)
	{
	    return tcgetattr(0, &original_mode);
	}
	else
	{
	    return tcsetattr(0, TCSANOW, &original_mode);
	}
}
