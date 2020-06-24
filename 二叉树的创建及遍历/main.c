#include "tree.h"

int main()
{
    pTreeNode root = NULL;
    pQueNode queHead = NULL, queTail = NULL;
    int x;
    while ((scanf("%d", &x)) != EOF) {
        if (x == -1) break;
        levelCreateTree(&root, &queHead, &queTail, x);
    }
    //preOrder(root);
    preOrder1(root);
    printf("\n---------------\n");
    //inOrder(root);
    inOrder1(root);
    printf("\n---------------\n");
    //postOrder(root);
    postOrder1(root);
    printf("\n---------------\n");
    levelOrder(root);
    return 0;
}