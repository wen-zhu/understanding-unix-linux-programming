#include <stdio.h>
#define BUFFERSIZE 4096
#define COMPYMODE 0644
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    int in_fd, out_fd, n_chars;
    if (argc != 3)
    {
        fprintf(stderr, "usage: %s source destination\n", *argv);
        exit(1); 
    }

    if ((in_fd = open(argv[1], O_RDONLY))== -1)
    {
        fprintf(stderr, "Cannot open %s\n",argv[1] );
        exit(1);
    }

    if ((out_fd=creat(argv[2], COMPYMODE)) ==-1 )
    {
        fprintf(stderr, "Cannot open %s\n", argv[2]);
        exit(1);
    }
    char buf[BUFFERSIZE];
    while ((n_chars = read(in_fd, buf, BUFFERSIZE)) != 0)
    {
        write(out_fd, buf, n_chars);wd 
    	printf("%s", buf);
    }
    return 0;
}
