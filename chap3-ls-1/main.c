#include <stdio.h>
#include <dirent.h>

int main(int argc, char ** argv) {
//    char name = "";
    struct dirent *content;

    DIR * fd = opendir(argv[1]);

    content = readdir(fd);
    printf("%d ", content->d_ino);
    printf("%s", content->d_name);
    printf("%s\n", content->d_type);

    return 0;
}
