#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 4


//全排列
void permutation(int arr[], int vis[], int res[], int idx, int n) {
    if (idx == n) {
        for (int i = 0; i < n; ++i) {
            printf("%d", res[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (vis[i] == 0) {
            res[idx] = arr[i];
            vis[i] = 1;
            permutation(arr, vis, res, idx + 1, n);
            vis[i] = 0;
        }
    }
}

//组合，cnt代表res中的元素个数，idx代表arr下标，从n个元素选m个
void combination(int arr[], int res[], int cnt, int idx, int n, int m) {
    if (cnt == m) {
        for (int i = 0; i < m; ++i) {
            printf("%d", res[i]);
        }
        printf("\n");
        return;
    }
    for (int i = idx; i < n; ++i) {
        res[cnt] = arr[i];
        combination(arr, res, cnt + 1, i + 1, n, m);
    }
}

void test1() {
    int a[N] = {1,2,3,4}, vis[N] = {0}, res[N];
    permutation(a, vis, res, 0, N);
}

void test2() {
    int a[N] = {1,2,3,4}, res[2];
    combination(a, res, 0, 0, N, 3);
}

// n皇后问题,从n*n的棋盘中放置n个皇后,要求任意两个皇后不在同一行、同一列、同一条对角线上,求出总方案数
//idx表示列,isExistQueen代表某行是否已经存在皇后,row表示某列皇后所在行,cnt表示总方案数
void queen(int n, int idx, int isExistQueen[], int row[], int *cnt) {
    if (idx == n) {
        ++(*cnt);
        return;
    }
    for (int i = 0; i < n; ++i) {//遍历每一行
        if (isExistQueen[i] == 0) {//第i行还没有皇后
            int flag = 1;
            for (int j = 0; j < idx; ++j) {//遍历之前的列
                if (abs(idx-j) == abs(i-row[j])) {//如果会和以前列的皇后处于同一对角线
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {//可以将皇后放在第i行
                row[idx] = i;
                isExistQueen[i] = 1;
                queen(n, idx + 1, isExistQueen, row, cnt);
                isExistQueen[i] = 0;
            }
        }        
    }
}

void test3() {
    int n, cnt = 0;
    scanf("%d", &n);
    int *isExistQueen = (int *)malloc(sizeof(int) * n);
    memset(isExistQueen, 0, sizeof(int) * n);
    int *row = (int *)malloc(sizeof(int) * n);
    memset(row, 0, sizeof(int) * n);
    queen(n, 0, isExistQueen, row, &cnt);
    printf("%d皇后问题有%d种方案\n", n, cnt);
}

//计算组合数
//递归
long long res[67][67] = {0};
long long C(long long m, long long n) {
    if (n == 0 || m == n) return 1;
    if (res[m][n]) return res[m][n];
    return res[m][n] = C(m-1, n) + C(m-1, n-1);
}

long long C2(long long m, long long n) {
    long long res = 1;
    for (long long i = 1; i <= n; ++i) {
        res = res * (m - n + i) / i;
    }
    return res;
}

void test4() {
    long long m, n;
    scanf("%lld%lld", &m, &n);
    printf("从%d中选%d有%d种方案\n", m, n, C2(m, n));
}

//计算组合数%p
//法1:递归
int res1[1010][1010] = {0};
int C3(int m, int n, int p) {
    if (n == 0 || m == n) return 1;
    if (res1[m][n]) return res1[m][n];
    return res1[m][n] = (C3(m-1, n, p) + C3(m-1, n-1, p)) % p;
}
//法2: Lucas定理,要求p为素数
int Lucas(int m, int n, int p) {
    if (n == 0) return 1;
    return C3(m % p, n % p, p) * Lucas(m / p, n / p, p) % p;
}

void test5() {
    int m, n, p;
    scanf("%d%d%d", &m, &n, &p);
    printf("%d\n", C3(m, n, p));
}

void test6() {
    int m, n, p;
    scanf("%d%d%d", &m, &n, &p);
    printf("%d\n", Lucas(m, n, p));
}

int main()
{
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    test6();
    return 0;
}