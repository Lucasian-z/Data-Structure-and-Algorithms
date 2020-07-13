#include <iostream>
using namespace std;

typedef struct node {
    int val, height;
    struct node *left, *right;
}treenode, *pTreeNode;

pTreeNode newNode(int val) {
    pTreeNode Node = (pTreeNode)malloc(sizeof(treenode));
    Node->height = 1;
    Node->val = val;
    Node->left = Node->right = NULL;
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
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

void L(pTreeNode &root) {
    pTreeNode tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void R(pTreeNode &root) {
    pTreeNode tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void insert(pTreeNode &root, int x) {
    if (root == nullptr) {
        root = newNode(x);
        return;
    }
    if (x < root->val) {
        insert(root->left, x);
        updateHeight(root);
        if (getBalance(root) == 2) {
            if (getBalance(root->left) == 1) {
                R(root);
            }else if(getBalance(root->left) == -1) {
                L(root->left);
                R(root);
            }
        }
    }else {
        insert(root->right, x);
        updateHeight(root);
        if (getBalance(root) == -2) {
            if (getBalance(root->right) == -1) {
                L(root);
            }else if (getBalance(root->right) == 1) {
                R(root->right);
                L(root);
            }
        }
    }
}

pTreeNode createAVL(int arr[], int n) {
    pTreeNode root = nullptr;
    for (int i = 0; i < n; ++i) {
        insert(root, arr[i]);
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