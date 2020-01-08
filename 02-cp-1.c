#include <stdio.h>
#define BUDDERSIZE 4096
#includeunistd.h>

int mainnt argc, char** argv)
{
    int _fd, out_fd, n_chars;
    if (gc != 3)
    {
        rintf(stderr, "usage: %s source destination\n", *argv);
        it(1); 
    }

    if (n_fd = open(argv[1], O_RDONLY))== -1)
    {
        rintf(stderr, "Cannot open %s\n",argv[1] );
        it(1);
    }
    int chars;

    if (_chars = (out_fd=creat(argv[2], COMPYMODE))) ==-1 )
    {
        fprintf(stderr, "Cannot open %s\n", argv[2]);
        exit(1);
    }
    char buf[BUFFERSIZE];
    while (read(in_fd, buf, BUFFERSIZE)==BUFFERSIZE)
    {
       printf("%s", buf);
    }
    return 0;
}
