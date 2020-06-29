#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen("test.txt", "r+");
    if (fp == NULL) {
        perror("fopen");
    }
    char buf[1024];
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        buf[0] -= 32;
        if (buf[strlen(buf)-1] == '\n') {
            fseek(fp, -strlen(buf) - 1, SEEK_CUR);
        }else {
            fseek(fp, -strlen(buf), SEEK_CUR);
        }

        fputs(buf, fp);
        fseek(fp, 0, SEEK_CUR);
    }
    return 0;
}
