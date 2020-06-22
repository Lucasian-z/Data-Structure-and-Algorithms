#include "list.h"

void listPrint(plist list) {
    plist p = list;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
}

void listTailInsert(plist *head, plist *tail, int x) {
    plist newNode = (plist)malloc(sizeof(list));
    newNode->next = NULL;
    newNode->val = x;
    if (NULL == *head) {
        *head = newNode;
        *tail = newNode;
    }else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void listHeadInsert(plist *head, plist *tail, int x) {
    plist newNode = (plist)malloc(sizeof(list));
    newNode->val = x;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    }else {
        newNode->next = *head;
        *head = newNode;
    }
}

void listSortInsert(plist *head, plist *tail, int x) {
    plist newNode = (plist)malloc(sizeof(list));
    newNode->val = x;
    newNode->next = NULL;
    plist p = *head, q = p;
    if (NULL == *head) {
        *head = newNode;
        *tail = newNode;
    }else if (x <= p->val) {
        newNode->next = p;
        *head = newNode;
    }else {
        while (p && p->val < x) {
            q = p;
            p = p->next;
        }
        newNode->next = p;
        q->next = newNode;
        if (p == NULL) {
            
            // (*tail)->next = newNode;
            *tail = newNode;
        }
    }
}

void listDelete(plist *head, plist *tail, int x) {
    if (head == NULL) return;
    plist p = *head, q = *head;
    if (x == p->val) {
        *head = p->next;
        if (head == NULL) {
            *tail = NULL;
        }
    }else {
        while (p && p->val < x) {
            q = p;
            p = p->next;
        }
        if (p && p->val == x) {
            q->next = p->next;
            if (p->next == NULL) {
                *tail = q;
            }
            p->next = NULL;
            free(p);
        }
    }
}

void listModify(plist *head, plist *tail, int oldValue, int newValue) {
    plist p = *head;
    while (p && p->val != oldValue) {
        p = p->next;
    }
    if (p == NULL) {
        return;
    }else {
        p->val = newValue;
    }
    
}