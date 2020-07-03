#include <stdio.h>

//欧几里得算法
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

//扩展欧几里得算法
int exGcd(int a, int b, int *x, int *y) {
    int r = a;
    if (b != 0) {
        // r = exGcd(b, a % b, x, y);
        // int tmp = *y;
        // *y = *x - (a / b) * (*y);
        // *x = tmp;
        r = exGcd(b, a % b, y, x);
        *y -= (a / b) * (*x);
    }else {
        *x = 1;
        *y = 0;
    }
    return r;
}

int main()
{
    int a, b, x, y;
    scanf("%d%d", &a, &b);
    //printf("res = %d\n", gcd(a, b));
    int r = exGcd(a, b, &x, &y);
    printf("x = %d, y = %d\nres = %d\n", x, y, r);
    return 0;
}