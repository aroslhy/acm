#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1000+5, MAXM = 1000+5;
const int INF = 0x3f3f3f3f;
int e, s, t, n;
int v[MAXM], next[MAXM], head[MAXN];
int cap[MAXM], f;
int cost[MAXM], d[MAXN], c;
int pv[MAXN], pe[MAXN];
bool inq[MAXN];
queue<int> Q;
void addedge(int u_, int v_, int c_, int w_)
{
    v[e] = v_; cap[e] = c_; cost[e] = w_;
    next[e] = head[u_]; head[u_] = e;
    e++;
    v[e] = u_; cap[e] = 0; cost[e] = -w_;
    next[e] = head[v_]; head[v_] = e;
    e++;
}
void mincostflow()
{
    f = 0; c = 0;
    for (;;)
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
                        Q.push(v[e]), inq[v[e]] = 1;
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
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    memset(cap, 0, sizeof(cap));
    memset(cost, 0, sizeof(cost));
    memset(head, -1, sizeof(head));
    e = 0;

    return 0;
}
