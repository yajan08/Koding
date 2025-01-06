#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    char ch[1];
    fp = fopen("dest.txt", "r");

    if (fp == NULL) {
        printf("file doesn't exist");
        exit(1);
    }

    while (1) {
        fgets(ch, 1, fp);       // how does it work?
        if (ch == EOF) {
            break;
        }
        printf("%s", ch);
    }
    printf("\n");
    fclose(fp);
    return 0;
}