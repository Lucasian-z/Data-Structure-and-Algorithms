/*分数四则运算
author: zhanghao
email: zhangh2548@outlook.com
date:2020/07/04/ 09:40:20
*/

#include <stdio.h>
#include <math.h>

typedef struct Fraction {
    int up;
    int down;
}Frac;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

Frac reduction(Frac a) {
    if (a.down < 0) {
        a.up = -a.up;
        a.down = -a.down;
    }
    if (a.up == 0) {//分子为0，规定分母为1
        a.down = 1;
    }else {
        int tmp = gcd(a.up, a.down);//分子分母的最大公约数
        a.up /= tmp;
        a.down /= tmp;
    }
    return a;
}

Frac add(Frac a, Frac b) {
    Frac res;
    res.up = a.up * b.down + a.down * b.up;
    res.down = a.down * b.down;
    return reduction(res);
}

Frac sub(Frac a, Frac b) {
    Frac res;
    res.up = a.up * b.down - a.down * b.up;
    res.down = a.down * b.down;
    return reduction(res);
}

Frac multi(Frac a, Frac b) {
    Frac res;
    res.up = a.up * b.up;
    res.down = a.down * b.down;
    return reduction(res);
}

Frac divide(Frac a, Frac b) {
    Frac res;
    res.up = a.up * b.down;
    res.down = a.down * b.up;
    return reduction(res);
}

void printFrac(Frac a) {
    a = reduction(a);
    if (a.down == 1) {//整数
        printf("%d\n", a.up);
    }else if (a.up > a.down) {//假分数
        printf("%d %d/%d\n", a.up/a.down, abs(a.up)%a.down, a.down);
    }else {
        printf("%d/%d\n", a.up, a.down);
    }
}

int main()
{
    Frac a,b;
    scanf("%d%d%d%d", &a.up, &a.down, &b.up, &b.down);
    printFrac(add(a, b));
    printFrac(sub(a, b));
    printFrac(multi(a, b));
    printFrac(divide(a, b));
    return 0;
}