/*
author: zhanghao
email: zhangh2548@outlook.com
date:2020/07/20/ 00:57:21
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int maxn = 100;
//int arr[maxn];

//最大连续子列和
int solve1(int arr[], int n) {
    int res = arr[0];
    int *dp = (int *)malloc(sizeof(int) * n);
    dp[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = (dp[i-1] + arr[i]) > arr[i] ? dp[i-1] + arr[i] : arr[i];
        if (dp[i] > res) res = dp[i];
    }
    return res;
}

//最长不下降子序列 Longest Increasing Subsequence
int LIS(int arr[], int n) {
    int *dp = (int *)malloc(sizeof(int) * n);
    int res = 1;
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (arr[i] >= arr[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > res) {
            res = dp[i];
        }
    }
    return res;
}

//最长公共子序列 Longest Common Subsequence
int LCS(char *str1, char *str2) {
    int len1 = strlen(str1), len2 = strlen(str2);
    int **dp = (int **)malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; ++i) {
        dp[i] = (int *)malloc(sizeof(int) * (len2 + 1));
    }
    
    for (int i = 0; i <= len1; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= len2; ++i) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }else {
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }
    return dp[len1][len2];
}

//最长回文子串
int solve2(char *str) {
    int n = strlen(str), res = 1;
    int **dp = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i) {
        dp[i] = (int *)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        if (i > 0 && dp[i] == dp[i-1]) {
            dp[i-1][i] = 1;
            res = 2;
        }
    }
    for (int len = 2; len < n; ++len) {
        for (int i = 0; i + len < n; ++i) {
            int j = i + len;
            if (str[i] == str[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                res = res > len ? res : len + 1;
            }
        }
    }
    return res;
}

int main()
{
    // int arr[] = {-2,11,-4,13,-5,-2};
    // printf("%d\n", solve1(arr, 6));
    // char str1[100], str2[100];
    // scanf("%s", str1);
    // scanf("%s", str2);
    // printf("%d\n", LCS(str1, str2));
    char str[100];
    scanf("%s", str);
    printf("%d\n", solve2(str));
    return 0;
}