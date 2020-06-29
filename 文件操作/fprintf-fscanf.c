#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    int num;
    float score;
    char name[20];
}Stu;

int main()
{
    Stu s = {1001, 77.5, "ÕÅÈý·á"};
    FILE *fp = fopen("test.txt", "r+");
    if (fp == NULL) {
        perror("fopen");
    }
    //fprintf(fp, "%d %5.2f %s\n", s.num, s.score, s.name);
    memset(&s, 0, sizeof(Stu));
    while (fscanf(fp, "%d %f %s", &s.num, &s.score, s.name) != EOF) {
        printf("%d %5.2f %s\n", s.num, s.score, s.name);
    }

    fclose(fp);
    return 0;
}
