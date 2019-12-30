#include<stdio.h>
#include<unistd.h>

// for open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <utmp.h>

void show_info( struct utmp * utbufp );
int main()
{	
	struct utmp current_record; //read info into here
	int reclen = sizeof(current_record);
	
	int utmpfd;
	
	if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1)
	{
		perror( UTMP_FILE);
		return -1;
	}
	
	while (read(utmpfd, &current_record, reclen) == reclen)
		show_info(&current_record);

	close(utmpfd);
	return 0;
 } 
 
 void show_info( struct utmp * utbufp ){
 	
 	printf("%-8.8s", utbufp->ut_name);
 	printf(" ");
 	printf("%-8.8s", utbufp->ut_line);
 	printf(" ");
 	printf("%10ld", utbufp->ut_time);
 	printf(" ");
 	printf("(%s)", utbufp->ut_host);
 	printf("\n");
}
 
//struct utmp {
//   short   ut_type;              /* Type of record */
//   pid_t   ut_pid;               /* PID of login process */
//   char    ut_line[UT_LINESIZE]; /* Device name of tty - "/dev/" */
//   char    ut_id[4];             /* Terminal name suffix,
//                                    or inittab(5) ID */
//   char    ut_user[UT_NAMESIZE]; /* Username */
//   char    ut_host[UT_HOSTSIZE]; /* Hostname for remote login, or
//                                    kernel version for run-level
//                                    messages */
//   struct  exit_status ut_exit;  /* Exit status of a process
//                                    marked as DEAD_PROCESS; not
//                                    used by Linux init (1 */
//   /* The ut_session and ut_tv fields must be the same size when
//      compiled 32- and 64-bit.  This allows data files and shared
//      memory to be shared between 32- and 64-bit applications. */
//#if __WORDSIZE == 64 && defined __WORDSIZE_COMPAT32
//   int32_t ut_session;           /* Session ID (getsid(2)),
//                                    used for windowing */
//   struct {
//       int32_t tv_sec;           /* Seconds */
//       int32_t tv_usec;          /* Microseconds */
//   } ut_tv;                      /* Time entry was made */
//#else
//    long   ut_session;           /* Session ID */
//    struct timeval ut_tv;        /* Time entry was made */
//#endif
//
//   int32_t ut_addr_v6[4];        /* Internet address of remote
//                                    host; IPv4 address uses
//                                    just ut_addr_v6[0] */
//   char __unused[20];            /* Reserved for future use */
//};
//
///* Backward compatibility hacks */
//#define ut_name ut_user
//#ifndef _NO_UT_TIME
//#define ut_time ut_tv.tv_sec
//#endif
//#define ut_xtime ut_tv.tv_sec
//#define ut_addr ut_addr_v6[0]

