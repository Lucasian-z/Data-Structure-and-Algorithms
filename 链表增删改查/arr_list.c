#include <stdio.h>
#include <string.h>

#define N 100005
int e[N], ne[N], idx = 0, head = 0;

// 链表初始化
void init() {
    idx = 0;
    head = -1;
}

// 头插
void insertHead(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

// 在第k个插入的数后面插入一个数
void insertK(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

// 表示删除第k个插入的数后面的数，当k为0时，表示删除头结点
void removeK(int k) {
    ne[k] = ne[ne[k]];
}

int main()
{
    int M;
    scanf("%d", &M);
    char ch[2];
    int k, x;
    init();
    while (M--) {
        scanf("%s", ch);
        // printf("%s\n", ch);
        if (strcmp(ch, "H") == 0) {
            scanf("%d", &x);
            insertHead(x);
        } else if (strcmp(ch, "I") == 0) {
            scanf("%d%d", &k, &x);
            insertK(k - 1, x);
        } else {
            scanf("%d", &k);
            if (!k) head = ne[head];
            removeK(k - 1);
        }
    }
    while (head != -1) {
        printf("%d ", e[head]);
        head = ne[head];
    }
    return 0;
}