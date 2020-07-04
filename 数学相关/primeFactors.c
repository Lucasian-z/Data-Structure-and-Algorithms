/*质因子分解 and n!存在质因子p的个数
author: zhanghao
email: zhangh2548@outlook.com
date:2020/07/04/ 09:56:02
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 100

struct PrimeFactors {
    int prime,cnt;
}factors[10];
int isPrimes[N], primes[N], cnt = 0;

void Erato() {
    memset(isPrimes, 0, sizeof(isPrimes));
    for (int i = 2; i < N; ++i) {
        if (isPrimes[i] == 0) {
            for (int j = i; i * j < N; ++j) {
                isPrimes[i * j] = 1;                
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        if (isPrimes[i] == 0) {
            primes[cnt++] = i;
        }
    }
}

void getFactors(int x) {
    int num = 0;//不同质因子个数
    if (x == 1) {
        printf("1 = 1\n");
    }else {
        printf("%d = ", x);
        for (int i = 0; i < cnt && primes[i] <= sqrt(x); ++i) {
            if (x % primes[i] == 0) {
                factors[num].prime = primes[i];
                factors[num].cnt = 0;
                while (x % primes[i] == 0) {
                    x /= primes[i];
                    ++factors[num].cnt;
                }
                ++num;
            }            
            if (x == 1) {
                break;
            }
        }
        if (x != 1) {
            factors[num].prime = x;
            factors[num++].cnt = 1;
        }
        for (int i = 0; i < num; ++i) {
            if (i > 0) printf("*");            
            printf("%d", factors[i].prime);
            if (factors[i].cnt > 1) {
                printf("^%d", factors[i].cnt);
            }
        }
    }
}

void test1() {
    Erato();
    int x;
    scanf("%d", &x);
    getFactors(x);
}

//计算n!种质因子p的个数
//非递归
int getPrimeCnt(int n, int p) {
    int cnt = 0;
    while (n) {
        cnt += n / p;
        n /= p;
    }
    return cnt;
}
//递归
int getPrimeCnt2(int n, int p) {
    if (n < p) return 0;
    return n / p + getPrimeCnt(n / p, p);
}

void test2() {
    int n, p;
    scanf("%d%d", &n, &p);
    printf("%d\n", getPrimeCnt2(n, p));
}

int main()
{
    //test1();
    test2();
    return 0;
}