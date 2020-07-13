#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

const int MAXN = 10000;
vector<int> Adj[MAXN];
int n, indegree[MAXN];
bool topSort() {
    int num = 0;
    queue<int> que;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int top = que.front();
        que.pop();
        for (int i = 0; i < Adj[top].size(); ++i) {
            int v = Adj[top][i];
            --indegree[v];
            if (indegree[v] == 0) {
                que.push(v);
            }
        }
        ++num;
    }
    return num == n;
}

//关键路径
struct node {
    int v;
    int dis;
};
vector<node> G[MAXN];
int ve[MAXN], vl[MAXN];
stack<int> topOrder;

bool topSort() {
    queue<int> que;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int top = que.front();
        que.pop();
        topOrder.push(top);
        for (int i = 0; i < G[top].size(); ++i) {
            int v = Adj[top][i];
            --indegree[v];
            if (indegree[v] == 0) {
                que.push(v);
            }
            if (ve[top] + G[top][i].dis > ve[v]) {
                ve[v] = ve[top] + G[top][i].dis;
            }
        }
    }
    return topOrder.size() == n;
}

int criticalPath() {
    memset(ve, 0, sizeof(ve));
    if (topSort() == false) {
        return -1;
    }
    fill(vl, vl + n, ve[n-1]);
    while (!topOrder.empty()) {
        int u = topOrder.top();
        topOrder.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i].v;
            if (vl[v] - G[u][i].dis < vl[u]) {
                vl[u] = vl[v] - G[u][i].dis;
            }
        }
    }
    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i].v, d = G[u][i].dis;
            int e = ve[u], l = vl[v] - d;
            if (e == l) {
                printf("%d->%d\n", u, v);//关键活动
            }
        }
    }
    return ve[n-1];//关键路径长度
}