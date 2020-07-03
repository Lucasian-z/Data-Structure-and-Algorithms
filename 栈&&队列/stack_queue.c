#include "stack_queue.h"

void push(pStack sta, int x) {
    pNode newNode = (pNode)malloc(sizeof(Node));
    newNode->val = x;
    newNode->next = sta->head;
    sta->head = newNode;    
    ++sta->size;
}

void pop(pStack sta) {
    if (sta->size > 0) {
        pNode p = sta->head;
        sta->head = p->next;
        free(p);
        --sta->size;
    }
}

int getTop(pStack sta) {
    if (sta->size > 0) {
        return sta->head->val;
    }else {
        return -1;
    }
}

int getSize(pStack sta) {
    return sta->size;
}


//队列
void initQue(pQue que) {
    que->head = NULL;
    que->tail = NULL;
    que->size = 0;
}

int getSizeQue(pQue que) {
    return que->size;
}

int isEmptyQue(pQue que) {
    return que->size == 0;
}

void pushQue(pQue que, int x) {
    pNode newNode = (pNode)malloc(sizeof(Node));
    newNode->val = x;
    newNode->next = NULL;
    if (isEmptyQue(que)) {
        que->head = newNode;
        que->tail = newNode;
    }else {
        que->tail->next = newNode;        
        newNode->next = que->head;
        que->tail = newNode;
    }
    ++que->size;
}

void popQue(pQue que) {
    if (que->size > 0) {
        pNode p = que->head;
        que->head = que->head->next;
        if (que->head == NULL) {
            que->tail = NULL;
        }else if(que->head == que->tail) {
            que->tail->next = NULL;
        }else {
            que->tail->next = que->head;
        }
        free(p);
        --que->size;
    }
}

int getTopQue(pQue que) {
    if (que->size > 0) {
        return que->head->val;
    }
    return -1;
}