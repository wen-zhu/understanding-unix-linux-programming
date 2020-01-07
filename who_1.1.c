#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
void show_time(long timeval);
int main()
{
    struct utmpi{
        short ut_type;
        pid_t ut_pid;
        char ut_line[UT_LINESIZE];
        char ut_id[4];
        char ut_user[UT_NAMESIZE];
        char ut_host[UT_HOSTSIZE];
    };
    //char[]pathname = "";
    int descriptor = open(UTMP_FILE, O_RDONLY);
//    printf("%d\n", descriptor);
    struct utmp current_record ;
    int reclen = sizeof(current_record);
   
    while (read(descriptor, &current_record, reclen)==reclen)
    {
        printf("%s ", current_record.ut_name);
        printf("%s ", current_record.ut_line);
        show_time(current_record.ut_time);
        //printf("%s\n",ctime(&current_record.ut_time));
    }
    return 0;
}
void show_time(long timeval)
{
    char *p = ctime(&timeval);
    printf("%s\n", p);
}
