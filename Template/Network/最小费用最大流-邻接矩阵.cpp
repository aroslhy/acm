#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1000+5;
const int INF = 0x3f3f3f3f;
int s, t, n;
int cost[MAXN][MAXN], d[MAXN], c;
int cap[MAXN][MAXN], flow[MAXN][MAXN], f;
int p[MAXN];
bool inq[MAXN];
queue<int> Q;
void addedge(int u_, int v_, int c_, int w_)
{
    cap[u_][v_] = c_;
    cost[u_][v_] = w_; cost[v_][u_] = -w_;
}
void mincostflow()
{
    f = 0, c = 0;
    memset(flow, 0, sizeof(flow));
    for(;;)
    {
		for(int i = 1; i <= n; i++)
			d[i] = (i == s ? 0 : INF);
        memset(inq, 0, sizeof(inq));
        Q.push(s); inq[s] = 1;
        while(!Q.empty())
        {
            int u = Q.front(); Q.pop();
            inq[u] = 0;
            for(int v = 1; v <= n; v++)
                if(cap[u][v] > flow[u][v] && d[v] > d[u]+cost[u][v])
                {
                    d[v] = d[u]+cost[u][v];
                    if(!inq[v])
                        Q.push(v), inq[v] = 1;
                    p[v] = u;
                }
        }
        if (d[t] == INF) break;
        int a = INF;
        for(int v = t; v != s; v = p[v])
            a = min(a, cap[p[v]][v]-flow[p[v]][v]);
        for(int v = t; v != s; v = p[v])
        {
            flow[p[v]][v] += a;
            flow[v][p[v]] -= a;
        }
        c += d[t]*a;
        f += a;
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    memset(cap, 0, sizeof(cap));
    memset(cost, 0, sizeof(cost));

    return 0;
}
