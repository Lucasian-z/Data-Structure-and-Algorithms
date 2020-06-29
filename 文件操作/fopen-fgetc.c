#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    FILE *fp = fopen(argv[1], "r+");
    if (fp == NULL) {
        perror("fopen");
    }
    char c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
    fclose(fp);
    return 0;
}