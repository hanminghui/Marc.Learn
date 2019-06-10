#include "utmplib.h"

int openutmp(char * filename)
{
	utmp_fd = open(filename, O_RDONLY);
	cur_rec = num_recs = 0;
    return utmp_fd;
}

/* read next bunch of records into buffer */
int readutmps()
{
	int amt_read;
    amt_read = read(utmp_fd, utmpsbuffer, UTMPS_BUFFER_SIZE * UTSIZE);

	num_recs = amt_read / UTSIZE;
	cur_rec = 0;
	return num_recs;
}

struct utmp * getutmp()
{
    struct utmp *recp;
	if(utmp_fd == -1)
		return NULLUT;
	if(cur_rec == num_recs && readutmps() == 0)
	{
	    return NULLUT;
	}
	recp = (struct utmp *) &utmpsbuffer[cur_rec * UTSIZE];
	cur_rec++;
	return recp;
}

void closeutmp()
{
    if(utmp_fd != -1)
    {
        close(utmp_fd);
    }
}
