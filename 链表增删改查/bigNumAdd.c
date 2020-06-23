#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
    int val;
    struct node *next;
}list, *plist;

void headInsert(plist *head, int x) {
    plist newNode = (plist)malloc(sizeof(list));
    newNode->next = NULL;
    newNode->val = x;
    if (*head == NULL) {
        *head = newNode;
    }else {
        newNode->next = *head;
        *head = newNode;
    }
}

void listPrint(plist head) {
    plist p = head;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

plist add(plist num1, plist num2) {
    plist res = NULL;
    int carry = 0;
    plist p = num1, q = num2;
    while (p || q) {
        int s = 0;
        if (p) {
            s += p->val;
            p = p->next;
        }
        if (q) {
            s += q->val;
            q = q->next;
        }
        s += carry;
        headInsert(&res, s % 10);
        carry = s / 10;
    }
    if (carry) {
        headInsert(&res, carry);
    }
    printf("dsg\n");
    return res;
}

int main()
{
    plist num1 = NULL, num2 = NULL;
    char str[1000];
    gets(str);//读入数字
    for (int i = 0; i < strlen(str); ++i) {
        headInsert(&num1, (str[i] - '0'));
    }
    listPrint(num1);
    gets(str);//读入数字
    for (int i = 0; i < strlen(str); ++i) {
        headInsert(&num2, (str[i] - '0'));
    }
    listPrint(num2);
    plist res = add(num1, num2);
    listPrint(res);
    return 0;

}