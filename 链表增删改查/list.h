#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    int val;
    struct listNode *next;
}list, *plist;

void listPrint(plist);
void listTailInsert(plist *, plist *, int);
void listHeadInsert(plist *, plist *, int);
void listSortInsert(plist *, plist *, int);
void listModify(plist *, plist *, int, int);
void listDelete(plist *, plist *, int);
