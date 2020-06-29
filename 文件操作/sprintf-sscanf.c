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
    Stu s = {1001, 100, "ÕÅÈý·á"};
    char buf[100];
    sprintf(buf, "%d %5.2f %s", s.num, s.score, s.name);
    memset(&s, 0, sizeof(Stu));printf("%d %5.2f %s\n", s.num, s.score, s.name);
    sscanf(buf, "%d %f %s", &s.num, &s.score, s.name);
    printf("%d %5.2f %s", s.num, s.score, s.name);
    return 0;

}
