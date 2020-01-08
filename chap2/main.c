#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    FILE *fp;
    if (argc == 1)
    {
        printf("Error pls enter filename: %s", *argv);
        exit(1);
    }

    if ((fp=fopen(argv[1],  "r")) == NULL)
    {
        printf("Error\n");
        exit(1);
    }


    fp



    return 0;
}
