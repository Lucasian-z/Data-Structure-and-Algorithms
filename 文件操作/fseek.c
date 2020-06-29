#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen("test.txt", "r+");
    if (fp == NULL) {
        perror("fopen");
    }
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (c <= 'z' && c >= 'a') {
            c -= 32;
            fseek(fp, -1, SEEK_CUR);
            fputc(c, fp);
        }
        fseek(fp, 0, SEEK_CUR);
    }
    fclose(fp);
    return 0;
}
