#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <string>

using namespace std;

struct node {
    double num;//操作数
    char op;//操作符
    bool flag;//true表示操作数，false表示操作符
};

stack<node> sta;//操作符栈
queue<node> que;//后缀表达式
map<char, int> ops;//操作符优先级

void midToPost(string &str) {
    node tmp;
    for (int i = 0; i < str.length();) {
        if (str[i] >= '0' && str[i] <= '9') {
            tmp.flag = true;
            tmp.num = str[i++] - '0';
            while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
                tmp.num = tmp.num * 10 + (str[i] - '0');
                ++i;
            }
            que.push(tmp);
        }else {
            tmp.flag = false;
            while (!sta.empty() && ops[str[i]] <= ops[sta.top().op]) {
                que.push(sta.top());
                sta.pop();
            }
            tmp.op = str[i];
            sta.push(tmp);
            ++i;
        }
    }
    while (!sta.empty()) {
        que.push(sta.top());
        sta.pop();
    }
}

double calc() {
    double tmp1, tmp2;
    node top, tmp;
    while (!que.empty()) {
        top = que.front();
        que.pop();
        if (top.flag) {
            sta.push(top);
        }else {
            tmp1 = sta.top().num;
            sta.pop();
            tmp2 = sta.top().num;
            sta.pop();
            if (top.op == '+') {
                tmp.num = tmp1 + tmp2;
            }else if (top.op == '-') {
                tmp.num = tmp2 - tmp1;
            }else if (top.op == '*') {
                tmp.num = tmp1 * tmp2;
            }else {
                tmp.num = tmp2 / tmp1;
            }
            tmp.flag = true;
            sta.push(tmp);
        }
    }
    return sta.top().num;
}

int main()
{
    string str;
    cin >> str;
    ops['+'] = ops['-'] = 0;
    ops['*'] = ops['/'] = 1;

    midToPost(str);
    cout << calc() << endl;
    return 0;
}