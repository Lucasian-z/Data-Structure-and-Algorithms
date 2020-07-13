#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define N 1000
using namespace std;

//邻接矩阵
int G[N][N], n;
const int INF = 0x3fffffff;
int vis[N] = {0}, dis[N];
void dijkstra(int s) {
    fill(dis, dis + N, INF);
    dis[s] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++j) {
            if (vis[j] == 0 && dis[j] < MIN) {
                MIN = dis[j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = 1;
        for (int v = 0; v < n; ++v) {
            if (vis[v] == 0 && G[u][v] != INF && dis[u] + G[u][v] < dis[v]) {
                dis[v] = dis[u] + G[u][v];
            }
        }
    }
}

//邻接表
struct node {
    int v;
    int dis;
};
vector<node> Adj[N];
void dijkstra1(int s) {
    fill(dis, dis + N, INF);
    dis[s] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++j) {
            if (vis[j] == 0 && dis[j] < MIN) {
                u = j;
                MIN = dis[j];
            }
        }
        if (u == -1) return;
        vis[u] = 1;
        for (int j = 0; j < Adj[u].size(); ++j) {
            int v = Adj[u][j].v;
            if (vis[v] == 0 && dis[u] + Adj[u][j].dis < dis[v]) {
                dis[v] = dis[u] + Adj[u][j].dis;
            }
        }
    }
}

//dijkstra + DFS
vector<int> pre[N];//前驱结点
void dijkstra2(int s) {
    fill(dis, dis + N, INF);
    for (int i = 0; i < n; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++j) {
            if (vis[j] == 0 && dis[j] < MIN) {
                u = j;
                MIN = dis[j];
            }
        }
        if (u == -1) return;
        vis[u] = 1;
        for (int v = 0; v < n; ++v) {
            if (vis[v] == 0 && G[u][v] != INF) {
                if (dis[u] + G[u][v] < dis[v]) {
                    dis[v] = dis[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if (dis[u] + G[u][v] == dis[v]) {
                    pre[v].push_back(u);
                }
                
            }
        }
    }
}
vector<int> res, tmp;
int optValue, s;
void DFS(int v) {
    if (v == s) {
        tmp.push_back(v);
        int value = 0;
        //计算tmp中的value值
        if (value > optValue) {//如果value由于optValue
            optValue = value;
            res = tmp;
        }
        tmp.pop_back();
        return;
    }
    tmp.push_back(v);
    for (int i = 0; i < pre[v].size(); ++i) {
        DFS(pre[v][i]);
    }
    tmp.pop_back();
}

//如果存在负环，则不适用dijkstra算法，采用Bellman-Ford
bool Bellman_Ford(int s) {
    fill(dis, dis + N, INF);
    dis[s] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u) {
            for (int j = 0; j < Adj[u].size(); ++j) {
                int v = Adj[u][j].v;
                int d = Adj[u][j].dis;
                if (dis[u] + d < dis[v]) {
                    dis[v] = dis[u] + d;
                }
            }
        }
        for (int u = 0; u < n; ++u) {
            for (int j = 0; j < Adj[u].size(); ++j) {
                int v = Adj[u][j].v;
                int d = Adj[u][j].dis;
                if (dis[u] + d < dis[v]) {
                    return false;
                }
            }
        }
    }
    return true;
}

//SPFA: shortest path faster algorithm
int nums[N];//记录结点入队次数
queue<int> que;
bool inq[N] = {false};//判断是否在队列中
bool SPFA(int s) {
    dis[s] = 0;
    que.push(s);
    inq[s] = true;
    ++nums[s];
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        inq[u] = false;
        for (int i = 0; i < Adj[u].size(); ++i) {
            int v = Adj[u][i].v;
            int d = Adj[u][i].dis;
            if (dis[u] + d < dis[v]) {
                dis[v] = dis[u] + d;
                if (!inq[v]) {
                    que.push(v);
                    ++nums[v];
                    inq[v] = true;
                    if (nums[v] >= n) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

//弗洛伊德Floyd
int dist[N][N];
void floyd() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}