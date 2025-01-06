#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    char ch;
    fp = fopen("src.txt", "w");

    if (fp == NULL) {
        printf("file doesn't exist");
        exit(1);
    }

    while (1) {
        scanf("%c", &ch);
        if (ch == '\\') {
            break;
        }
        fputc(ch, fp);
    }
    printf("\n");
    fclose(fp);
    return 0;
}