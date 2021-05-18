#include <stdio.h>
#include <string.h>
#define N 100003 // 素数

// 拉链法 用e[N], ne[N]表示链表
int h[N], e[N], ne[N], idx;

void insert(int x) {
    int  k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

int find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    char op[3];
    int x;
    memset(h, -1, sizeof h);
    while (n--) {
        scanf("%s %d", op, &x);
        if (!strcmp(op, "I")) {
            insert(x);
        } else {
            if (find(x)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}