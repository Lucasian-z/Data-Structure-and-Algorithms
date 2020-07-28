#include <stdio.h>
#include <stdlib.h>
#define lowbit(x) ((x) & (-x))
#define N 100010

/*树状数组
author: zhanghao
email: zhangh2548@outlook.com
date:2020/07/29/ 00:53:35
*/

int C[N];
int getSum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += C[i];
    }
    return sum;
}
void update(int x, int v) {
    for (int i = x; i < N; i += lowbit(i)) {
        C[i] += v;
    }
}

//二维
int C1[N][N];
int getSum2(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        for (int j = y; j > 0; j -= lowbit(j)) {
            sum += C1[i][j];
        }
    }
    return sum;
}
void update1(int x, int y, int v) {
    for (int i = x; i < N; i += lowbit(i)) {
        for (int j = y; j < N; j += lowbit(j)) {
            C1[i][j] += v;
        }
    }
}
