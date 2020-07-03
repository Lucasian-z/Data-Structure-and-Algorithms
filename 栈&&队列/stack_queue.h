#include <stdio.h>
#include <stdlib.h>

//链表实现栈
typedef struct node {
    int val;
    struct node *next;
}Node, *pNode;

typedef struct sta {
    pNode head;
    int size;
}Stack, *pStack;

void push(pStack, int);
void pop(pStack);
int getTop(pStack);
int getSize(pStack);


typedef struct que
{
    pNode head, tail;
    int size;
}Que, *pQue;

void pushQue(pQue, int);
void popQue(pQue);
int isEmptyQue(pQue);
void initQue(pQue);
int getSizeQue(pQue);
int getTopQue(pQue);



