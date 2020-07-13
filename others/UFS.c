#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

int father[N];

void init() {
    memset(father, -1, sizeof(father));
}

//路径压缩 非递归
int findFather(int x) {
    int tmp = x;
    while (father[x] != -1) {
        x = father[x];
    }
    while (father[tmp] != - 1) {
        int z = tmp;
        tmp = father[tmp];
        father[z] = x;
    }
    return x;
}
//递归
int findFather2(int x) {
    if (father[x] == -1) {
        return x;
    }else {
        int F = findFather(father[x]);
        father[x] = F;
        return F;
    }
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) {
        father[faA] = faB;
    }
}