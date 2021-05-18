#include <stdio.h>
#include <string.h>

#define P 131
#define N 100005

unsigned long long  h[N], p[N];
char ch[N];

// 获取子串hash
// 注意，左边为高位
// hash [1]=s[1];
// hash [2]=s[1]*p+s[2]
// hash [3]=s[1]*p2+s[2]*p+s[3]
// hash [4]=s[1]*p3+s[2]*p2+s[3]*p+s[4]
// 现在要求s2s3的哈希值，根据定义就是s[2]*p+s[3],现在观察一下上面四条式子，很容易看出hash[3]- hash[1]*p2就等于hash[s2s3]了。
// 可以推广出公式：在字符串s中，第l到r位子串的哈希值为：hash[r]-hash[l-1]*pr-l+1  所以，只要得到了一个字符串的哈希值，就可以在o(1)的时间内得到它的子串的哈希值。

// 1 2 3 4 5
// h[5] = 1 * p^4 + 2 * p^3 + 3 * p^2 + 4 * p^1 + 5 * p^0
// h[2] = 1 * p^1 + 2 * p^0
// h[3~5] = 3 * p^2 + 4 * p^1 + 5 * p^0 = h[5] - h[2] * p^(5 - 2 + 1)

int getHash(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    
    scanf("%s", ch);
    p[0] = 1;
    for (int i = 0; i < strlen(ch); ++i) {
        p[i + 1] = p[i] * P;
        h[i + 1] = h[i] * P + (ch[i] - 'a');
    }
    
    int l1, r1, l2, r2;
    while (m--) {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        int h1 = getHash(l1, r1);
        int h2 = getHash(l2, r2);
        if (h1 != h2) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}