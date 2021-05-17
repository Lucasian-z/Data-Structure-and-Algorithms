#include <stdio.h>
#include <string.h>
#define N 100005

/* 整数 M，表示操作次数。
L x，表示在链表的最左端插入数 x
R x，表示在链表的最右端插入数 x
D k，表示将第 k 个插入的数删除
IL k x，表示在第 k 个插入的数左侧插入一个数
IR k x，表示在第 k 个插入的数右侧插入一个数 */

int e[N], ne[N], pre[N], idx;

void init() {
    ne[0] = 1;
    pre[1] = 0;
    idx = 2;
}

void insert(int k, int x) {
    e[idx] = x;
    pre[idx] = k;
    ne[idx] = ne[k];
    pre[ne[k]] = idx;
    ne[k] = idx++;
}

void removeK(int k) {
    pre[ne[k]] = pre[k];
    ne[pre[k]] = ne[k];
}


int main()
{
    int M;
    scanf("%d", &M);
    char ch[3];
    int k, x;
    init();
    while (M--) {
        scanf("%s", ch);
        if (strcmp(ch, "L") == 0) {
            scanf("%d", &x);
            insert(0, x);
        } else if (strcmp(ch, "R") == 0) {
            scanf("%d", &x);
            insert(pre[1], x);
        } else if (strcmp(ch, "D") == 0) {
            scanf("%d", &k);
            removeK(k + 1);
        } else if (strcmp(ch, "IL") == 0) {
            scanf("%d%d", &k, &x);
            insert(pre[k + 1], x);
        } else {
            scanf("%d%d", &k, &x);
            insert(k + 1, x);
        }
    }
    for (int i = ne[0]; i != 1; i = ne[i]) {
        printf("%d ", e[i]);
    }
    return 0;
}