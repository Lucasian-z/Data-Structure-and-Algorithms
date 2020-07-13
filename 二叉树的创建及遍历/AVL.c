#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/*平衡二叉树的建立
author: zhanghao
email: zhangh2548@outlook.com
date:2020/07/10/ 14:31:01
*/

typedef struct node {
    int val;
    int height;
    struct node *left, *right;
}TreeNode, *pTreeNode;

pTreeNode newNode(int val) {
    pTreeNode Node = (pTreeNode)malloc(sizeof(TreeNode));
    Node->val = val;
    Node->height = 1;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

int getHeight(pTreeNode root) {
    if (root == NULL) return 0;
    return root->height;
}
int getBalance(pTreeNode root) {
    return getHeight(root->left) - getHeight(root->right);
}
void updateHeight(pTreeNode root) {
    root->height = MAX(getHeight(root->left), getHeight(root->right)) + 1;
}

void search(pTreeNode root, int x) {
    if (root == NULL) return;
    if (root->val == x) {
        printf("%d\n", x);
    }else if (root->val > x) {
        search(root->left, x);
    }else {
        search(root->right, x);
    }
}

void leftRotate(pTreeNode *root) {//左旋
    pTreeNode tmp = (*root)->right;
    (*root)->right = tmp->left;
    tmp->left = *root;
    updateHeight(*root);
    updateHeight(tmp);
    *root = tmp;
}

void rightRotate(pTreeNode *root) {//右旋
    pTreeNode tmp = (*root)->left;
    (*root)->left = tmp->right;
    tmp->right = (*root);
    updateHeight(*root);
    updateHeight(tmp);
    *root = tmp;
}

void insert(pTreeNode *root, int x) {//插入
    if (*root == NULL) {
        *root = newNode(x);
        return;
    }
    if (x < (*root)->val) {
        insert(&(*root)->left, x);
        updateHeight(*root);
        if (getBalance(*root) == 2) {
            if (getBalance((*root)->left) == 1) {//LL型
                rightRotate(root);
            }else if(getBalance((*root)->left) == -1) {//LR型
                leftRotate(&(*root)->left);
                rightRotate(root);
            }
        }
    }else {
        insert(&(*root)->right, x);
        updateHeight((*root));
        if (getBalance(*root) == -2) {
            if (getBalance((*root)->right) == -1)  {//RR型
                leftRotate(root);
            }else if (getBalance((*root)->right) == 1) {//RL型
                rightRotate(&(*root)->right);
                leftRotate(root);
            }
        }
    }
}

pTreeNode createAVL(int arr[], int n) {
    pTreeNode root = NULL;
    for (int i = 0; i < n; ++i) {
        insert(&root, arr[i]);
    }
    
    return root;
}

int main()
{
    int arr[10] = {1,3,4,5,76,5565,564,74,748,48};
    pTreeNode root = createAVL(arr, 10);
    printf("%d\n", root->val);
    return 0;
}