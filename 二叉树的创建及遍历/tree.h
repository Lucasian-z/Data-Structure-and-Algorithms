#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int val;
    struct treenode *left, *right;    
}TreeNode, *pTreeNode;

typedef struct queNode {
    pTreeNode insertPos;
    struct quenode *next;
}QueNode, *pQueNode;

//栈
typedef struct sta {
    pTreeNode elements[1000];
    int size;
}Stack, *pStack;

void initStack(pStack*);
int isEmpty(pStack);
void getTop(pStack);
void pushSta(pStack, pTreeNode);
void popSta(pStack);

//递归遍历
void preOrder(pTreeNode);
void inOrder(pTreeNode);
void postOrder(pTreeNode);
void levelOrder(pTreeNode);

//非递归遍历
void preOrder1(pTreeNode);
void inOrder1(pTreeNode);
void postOrder1(pTreeNode);

//建树
void levelCreateTree(pTreeNode*, pQueNode *queHead, pQueNode *queTail, int val);