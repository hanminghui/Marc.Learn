/* utmplib.h
 * - functions to buffer reads from utmp file
 */
#include <utmp.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define UTMPS_BUFFER_SIZE 16
#define UTSIZE (sizeof(struct utmp))
#define NULLUT ((struct utmp *)NULL)

static char utmpsbuffer[UTMPS_BUFFER_SIZE * UTSIZE];
static int utmp_fd = -1;
static int num_recs;
static int cur_rec;

int openutmp(char * filename);
int readutmps();
struct utmp * getutmp();
void closeutmp();

