#include "list.h"
#include <time.h>
//逆置链表
plist reverse(plist *head) {
    plist p = *head, q, r = NULL;
    while (p) {
        q = p->next;
        p->next = r;
        r = p;
        p = q;
    }
    return r;
}

//递归求出链表的最大值
int getMax(plist head) {
    if (head->next == NULL) return head->val;
    int res = getMax(head->next);
    return res > head->val ? res : head->val;
}

int main()
{
    srand((unsigned)time(NULL));
    plist head = NULL, tail = NULL;
    for (int i = 0; i < 10; ++i) {
        listTailInsert(&head, &tail, rand() % 100);
    }
    listPrint(head);
    // printf("\n");
    // listPrint(reverse(&head));
    printf("\nThe biggest num is %d\n", getMax(head));
    return 0;
}