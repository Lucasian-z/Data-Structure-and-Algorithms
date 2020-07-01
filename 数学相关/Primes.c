#include <stdio.h>
#include <string.h>

#define N 10001

//埃氏筛法
void Erato(int a[]) {
    memset(a, 1, N);
    for (int i = 2; i < N; ++i) {
        if (a[i]) {
            for (int j = i; i * j < N; ++j) {
                a[i*j] = 0;
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        if (a[i]) {
            printf("%d ", i);
        }
    }
}

int main()
{
    int a[N];
    Erato(a);
    return 0;
}