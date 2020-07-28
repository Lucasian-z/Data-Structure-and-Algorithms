#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
author: zhanghao
email: zhangh2548@outlook.com
date:2020/07/28/ 23:30:56
*/

//字符串hash进阶
//H[i] = H[i-1] * 26 + index(H[i]),将字符串当作26进制数
//将进制数设置为一个10^7级别的素数p(如10000019),同时将mod设置为一个10^9级别的素数
//(如1000000007),那么基本不会产生冲突
//H[i] = (H[i-1] * p + index(H[i])) / mod

//Qes: 给出N个只有小写字母的字符串，求其中不同字符串的数目
const int p = 10000019;
const int MOD = 1000000007;
vector<int> res;
int Hash(string str) {
    long long H = 0;
    for (int i = 0; i < str.length(); ++i) {
        H = (H * p + (str[i] - 'a')) % MOD;
    }
    return (int)H;
}

int main()
{
    string str;
    while (getline(cin, str), str != "#") {
        res.push_back(Hash(str));
    }
    sort(res.begin(), res.end());
    int cnt = 0;
    for (int i = 0; i < res.size(); ++i) {
        if (i == 0 || res[i] != res[i-1]) {
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}