#include <stdio.h>
#include <dirent.h>

int main() {
    char name = "";
    struct dirent *content;

    DIR * fd = opendir(name);

    content = readdir(fd);
    printf("%d ", content->d_ino);
    printf("%s", content->d_name);
    printf("%s\n", content->d_type);

    return 0;
}
