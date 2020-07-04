#include <stdio.h>

typedef long long LL;

//快速幂非递归
LL binaryPower1(LL a, LL b, LL m) {
    LL res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

//快速幂递归
LL binaryPower2(LL a, LL b, LL m) {
    if (b == 0) {
        return 1;
    }
    if (b & 1) {
        return a * binaryPower2(a, b - 1, m) % m;
    }else {
        LL tmp = binaryPower2(a, b / 2, m) % m;
        return tmp * tmp % m;
    }
}

int main()
{
    printf("非递归 = %lld\n", binaryPower1(2, 20, 1000023));
    printf("非递归 = %lld\n", binaryPower2(2, 20, 1000023));
    return 0;
}