#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fs, *fd;
    char ch;

    fs = fopen("src.txt", "r");
    if (fs == NULL) {
        printf("source file doesn't exist");
        exit(1);
    }

    fd = fopen("dest.txt", "w");
    if (fd == NULL) {
        printf("destination file doesn't exist");
        exit(1);
    }

    while (1) {
        ch = getc(fs);
        if (ch == EOF) {
            break;
        }
        putc(ch, fd);
    }
    fclose(fs);
    fclose(fd);
    return 0;
}