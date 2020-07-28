#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10
int next[N];

void getNext(char s[], int len) {
    int j = -1;
    next[0] = -1;
    for (int i = 0; i < len; ++i) {
        while (j != -1 && s[i] != s[j+1]) {
            j = next[j];
        }
        if (s[i] == s[j+1]) ++j;
        next[i] = j;
    }
}

int KMP(char text[], char pattern[]) {
    int n = strlen(text), m = strlen(pattern);
    getNext(pattern, m);
    int j = -1;
    for (int i = 0; i < n; ++i) {
        while (j != -1 && text[i] != pattern[j+1]) {
            j = next[j];
        }
        if (text[i] == pattern[j+1]) {
            ++j;
        }
        if (j == m - 1) return 1;
    }
    return 0;
}