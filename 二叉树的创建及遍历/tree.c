#include "tree.h"

//递归版本
void preOrder(pTreeNode root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(pTreeNode root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}

void postOrder(pTreeNode root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);
}

//实现栈
void initStack(pStack *sta) {
    *sta = (pStack)malloc(sizeof(Stack));
    (*sta)->size = 0;
}
int isEmpty(pStack sta) {
    return sta->size == 0;
}
void pushSta(pStack sta, pTreeNode node) {
    sta->elements[sta->size++] = node;
}
void popSta(pStack sta) {
    if (isEmpty(sta)) return;
    --sta->size;
}
pTreeNode getTopEle(pStack sta) {
    return sta->elements[sta->size-1];
}

//非递归前序遍历
void preOrder1(pTreeNode root) {
    if (root == NULL) return;
    pStack sta = NULL;
    initStack(&sta);
    while (!isEmpty(sta) || root) {
        while (root) {//左子树全部入栈
            printf("%d ", root->val);
            pushSta(sta, root);
            root = root->left;
        }
        if (!isEmpty(sta)) {
            root = getTopEle(sta);
            popSta(sta);
            root = root->right;//弹出节点
        }
    }
}

//非递归中序遍历
void inOrder1(pTreeNode root) {
    if (root == NULL) return;
    pStack sta = NULL;
    initStack(&sta);
    while (!isEmpty(sta) || root) {
        while (root) {
            pushSta(sta, root);
            root = root->left;
        }
        if (!isEmpty(sta)) {
            pTreeNode tmp = getTopEle(sta);
            popSta(sta);
            printf("%d ", tmp->val);
            root = tmp->right;
        }
    }
}

//非递归后序遍历
void postOrder1(pTreeNode root) {
    if (root == NULL) return;
    pStack s1 = NULL, s2 = NULL;
    initStack(&s1);
    initStack(&s2);
    pushSta(s1, root);
    while (!isEmpty(s1)) {//根右左---->左右根
        pTreeNode top = getTopEle(s1);
        popSta(s1);
        pushSta(s2, top);
        if (top->left) {
            pushSta(s1, top->left);
        }
        if (top->right) {
            pushSta(s1, top->right);
        }
    }
    while (!isEmpty(s2)) {
        printf("%d ", getTopEle(s2)->val);
        popSta(s2);
    }
}

//层序遍历
void levelOrder(pTreeNode root) {
    if (root == NULL) return;
    pQueNode queHead = (pQueNode)malloc(sizeof(QueNode)), queTail = NULL;
    queHead->insertPos = root;
    queHead->next = NULL;
    queTail = queHead;
    pQueNode tmp;
    while (queHead != NULL) {
        printf("%d ", queHead->insertPos->val);
        tmp = queHead;
        if (tmp->insertPos->left) {
            pQueNode queNew = (pQueNode)malloc(sizeof(QueNode));
            queNew->next = NULL;
            queNew->insertPos = tmp->insertPos->left;
            queTail->next = queNew;
            queTail = queTail->next;
        }
        if (tmp->insertPos->right) {
            pQueNode queNew = (pQueNode)malloc(sizeof(QueNode));
            queNew->next = NULL;
            queNew->insertPos = tmp->insertPos->right;
            queTail->next = queNew;
            queTail = queTail->next;
        }
        queHead = queHead->next;
        free(tmp);
        tmp = NULL;        
    }    
}

//层序建立二叉树
void levelCreateTree(pTreeNode *root, pQueNode *queHead, pQueNode *queTail, int val) {
    pTreeNode treeNew = (pTreeNode)calloc(1, sizeof(TreeNode));
    treeNew->val = val;
    pQueNode queNew = (pQueNode)calloc(1, sizeof(QueNode));
    queNew->insertPos = treeNew;
    pQueNode qCur = *queHead;
    if (*root == NULL) {
        *root = treeNew;
        *queHead = queNew;
        *queTail = queNew;
    }else {
        (*queTail)->next = queNew;//入队
        *queTail = queNew;
        if (qCur->insertPos->left == NULL) {
            qCur->insertPos->left = treeNew;
        }else if (qCur->insertPos->right == NULL) {
            qCur->insertPos->right = treeNew;
            *queHead = qCur->next;
            free(qCur);
            qCur = NULL;
        }
    }
}