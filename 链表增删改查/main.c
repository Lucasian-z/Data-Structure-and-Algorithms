#include "list.h"

int main()
{
    plist head = NULL, tail = NULL;
    int x;
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &x);
        //listTailInsert(&head, &tail, x);
        //listHeadInsert(&head, &tail, x);
        listSortInsert(&head, &tail, x);
        listDelete(&head, &tail, 3);
        listModify(&head, &tail, 6, 999);
    }
    listPrint(head);
    return 0;
}