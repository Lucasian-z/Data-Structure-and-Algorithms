#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

//分治法求最值
int getMax(int a[], int L, int R) {
    if (L == R) return a[L];
    int mid = (L + R) / 2;
    int leftMax = getMax(a, L, mid);
    int rightMax = getMax(a, mid + 1, R);
    return leftMax > rightMax ? leftMax : rightMax;
}

int main()
{
    srand((unsigned)time(NULL));
    int a[N];
    for (int i = 0; i < N; ++i) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    printf("\n");
    int maxElement = getMax(a, 0, N - 1);
    printf("The biggest num is %d.\n", maxElement);
    return 0;
}