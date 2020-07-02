#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct BigN {
    int arr[100];
    int len;
}bigNum;

bigNum add(bigNum a, bigNum b) {
    bigNum res;
    res.len = 0;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; ++i) {
        int s = carry;
        if (i < a.len) {
            s += a.arr[i];
        }
        if (i < b.len) {
            s += b.arr[i];
        }
        res.arr[res.len++] = s % 10;
        carry = s / 10;
    }
    if (carry) {
        res.arr[res.len++] = carry;
    }
    return res;
}

int cmp(bigNum a, bigNum b) {
    if (a.len < b.len) {
        return -1;
    }else if(a.len > b.len) {
        return 1;
    }else {
        for (int i = a.len - 1; i >= 0; --i) {
            if (a.arr[i] > b.arr[i]) {
                return 1;
            }else if (a.arr[i] < b.arr[i]) {
                return -1;
            }
        }
        return 0;
    }
}

bigNum sub(bigNum a, bigNum b) {
    if (a.len < b.len) {
        return sub(b, a);
    }
    bigNum res;
    res.len = 0;
    int i = 0;
    for (; i < a.len && i < b.len; ++i) {
        if (a.arr[i] >= b.arr[i]) {
            res.arr[res.len++] = a.arr[i] - b.arr[i];
        }else {
            res.arr[res.len++] = 10 + a.arr[i] - b.arr[i];
            a.arr[i + 1] -= 1;
        }
    }
    while (i < a.len) {
        res.arr[res.len++] = a.arr[i++];
    }
    return res;
}

//低精度乘法
bigNum multi1(bigNum a, int b) {
    bigNum res;
    res.len = 0;
    int carry = 0;
    for (int i = 0; i < a.len; ++i) {
        int s = carry;
        s += a.arr[i] * b;
        res.arr[res.len++] = s % 10;
        carry = s / 10;
    }
    while (carry) {
        res.arr[res.len++] = carry % 10;
        carry /= 10;
    }
    return res;
}

//高精度乘法
bigNum multi2(bigNum a, bigNum b) {
    bigNum res;
    res.len = 0;
    memset(res.arr, 0, sizeof(res.arr));
    for (int i = 0; i < a.len; ++i) {
        for (int j = 0; j < b.len; ++j) {
            res.arr[i+j] += a.arr[i] * b.arr[j];
            if (res.arr[i+j] > 9) {
                res.arr[i+j+1] += res.arr[i+j] / 10;
                res.arr[i+j] %= 10;
            }
        }
    }
    res.len = a.len + b.len;
    return res;
}

//低精度除法
bigNum divide1(bigNum a, int b) {
    bigNum res;
    res.len = 0;
    int re = 0;
    for (int i = a.len - 1; i >= 0; --i) {
        re = re * 10 + a.arr[i];
        res.arr[res.len++] = re / b;
        re %= b;
    }   
    int i = 0;
    while (i < res.len - 1 && res.arr[i] == 0) {
        ++i;
    }
    for (; i < res.len; ++i) {
        printf("%d", res.arr[i]);
    }
    printf("\nThe reminder is %d\n", re);
}

int main()
{
    bigNum a, b;
    a.len = b.len = 0;
    char str[N];
    gets(str);
    for (int i = strlen(str) - 1; i >= 0; --i) {
        a.arr[a.len++] = str[i] - '0';
    }
    gets(str);
    for (int i = strlen(str) - 1; i >= 0; --i) {
        b.arr[b.len++] = str[i] - '0';
    }
    //bigNum res = add(a, b);
    //bigNum res = sub(a, b);
    // if (cmp(a, b) == -1) {
    //     printf("-");
    // }
    int m;
    scanf("%d", &m);
    // bigNum res = multi1(a, m);
    // bigNum res = multi2(a, b);
    // while (res.arr[res.len-1] == 0 && res.len > 1) {
    //     --res.len;
    // }    
    // for (int i = res.len - 1; i >= 0; --i) {
    //     printf("%d", res.arr[i]);
    // }
    bigNum res = divide1(a, m);
    return 0;
}       