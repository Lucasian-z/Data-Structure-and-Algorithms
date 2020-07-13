#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

//prim
const int MAXN = 1000;
const int INF = 0x3fffffff;
int n, G[MAXN][MAXN];
int dis[MAXN] = {0}, vis[MAXN] = {0};

//邻接矩阵
int prim(int s) {
    fill(dis, dis + MAXN, INF);
    dis[s] = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++j) {
            if (vis[j] == 0 && dis[j] < MIN) {
                u = j;
                MIN = dis[j];
            }
        }
        if (u == -1) return -1;//不连通
        vis[u] = 1;
        res += dis[u];
        for (int v = 0; v < n; ++v) {
            if (vis[v] == 0 && G[u][v] < dis[v]) {
                dis[v] = G[u][v];
            }
        }
    }
    return res;
}
//邻接表
struct node {
    int v;
    int dis;
};
vector<node> Adj[MAXN];
int prim1(int s) {
    fill(dis, dis + MAXN, INF);
    dis[s] = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++i) {
            if (vis[j] == 0 && dis[j] < MIN) {
                u = j;
                MIN = dis[j];
            }
        }
        if (u == -1) return -1;
        vis[u] = 1;
        res += dis[u];
        for (int j = 0; j < Adj[u].size(); ++j) {
            int v = Adj[u][j].v;
            int d = Adj[u][j].dis;
            if (vis[v] == 0 && d < dis[v]) {
                dis[v] = d;
            }
        }
    }
    return res;
}

//克鲁斯卡尔算法kruskal
struct edge {
    int u, v;
    int dis;
}Edge[MAXN];
bool cmp(edge a, edge b) {
    return a.dis < b.dis;
}
//并查集
int father[MAXN];
int findFather(int x) {
    if (father[x] == -1) return father[x];
    int F = findFather(father[x]);
    father[x] = F;
    return F;
}
int m;//边数
int kruskal() {
    int res = 0;
    int numEdge = 0;
    memset(father, -1, sizeof(father));
    sort(Edge, Edge + m, cmp);
    for (int i = 0; i < m; ++i) {
        int u = Edge[i].u, v = Edge[i].v;
        int faA = findFather(u), faB = findFather(v);
        if (faA != faB) {
            father[faA] = faB;
            res += Edge[i].dis;
            ++numEdge;
            if (numEdge == n - 1) {
                break;
            }
        }
    }
    if (numEdge != n - 1) return -1;
    return res;
}