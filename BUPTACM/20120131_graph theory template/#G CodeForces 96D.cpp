#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1000+5, MAXM = 1000+5;
const int INF = 0x3f3f3f3f;
int n, e, v[MAXM], next[MAXM];
int inq[MAXN], head[MAXN], pv[MAXN], pe[MAXN];
int f, cap[MAXM];
int c, cost[MAXM], d[MAXN];
int s, t;
queue<int> Q;
void addedge(int x, int y, int z, int w)
{
    v[e] = y; cap[e] = z;
    cost[e] = +w; next[e] = head[x]; head[x] = e++;
    v[e] = x; cap[e] = 0;
    cost[e] = -w; next[e] = head[y]; head[y] = e++;
}
int mincost()
{
    for (f = 0, c = 0; ; )
    {
        memset(inq, 0, sizeof(inq));
        for (int i = 1; i <= n; i++)
            d[i] = (i == s ? 0 : INF);
        Q.push(s); inq[s] = 1;
        while (!Q.empty())
        {
            int u = Q.front(); Q.pop();
            inq[u] = 0;
            for (int e = head[u]; e != -1; e = next[e])
                if(cap[e] && d[v[e]] > d[u]+cost[e])
                {
                    d[v[e]] = d[u]+cost[e];
                    if (!inq[v[e]])
                    {
                        Q.push(v[e]);
                        inq[v[e]] = 1;
                    }
                    pv[v[e]] = u; pe[v[e]] = e;
                }
        }
        if (d[t] == INF) break;
        int a = INF;
        for (int v = t; v != s; v = pv[v])
            a = min(a, cap[pe[v]]);
        for (int v = t; v != s; v = pv[v])
        {
            cap[pe[v]] -= a;
            cap[pe[v]^1] += a;
        }
        f += a;
        c += d[t]*a;
    }
    return c;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    memset(cap, 0, sizeof(cap));
    memset(cost, 0, sizeof(cost));
    memset(head, -1, sizeof(head));
    e = 0;
    int x = 0;
    for (int k = 1; k <= 1000; k++)
        for (int i = 1; i <= 1000; i++)
            for (int j = 1; j <= 1000; j++)
                x++;
    return 0;
}
