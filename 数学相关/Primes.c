#include <stdio.h>
#include <string.h>

#define N 10001

//埃氏筛法
void Erato(int a[]) {
    for (int i = 0; i < N; ++i) {
        a[i] = 1;
    }
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