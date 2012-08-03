#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1000+5;
const int INF = 0x3f3f3f3f;
int s, t, n;
int p[MAXN];
int cap[MAXN][MAXN], flow[MAXN][MAXN], a[MAXN], f;
queue<int> Q;
void addedge(int u_, int v_, int c_)
{
    cap[u_][v_] = c_;
}
void maxflow()
{
    f = 0;
    memset(flow, 0, sizeof(flow));
    for(;;)
    {
        memset(a, 0, sizeof(a));
        a[s] = INF;
        Q.push(s);
        while(!Q.empty())
        {
            int u = Q.front(); Q.pop();
            for(int v = 1; v <= n; v++)
                if(!a[v] && cap[u][v] > flow[u][v])
                {
                    p[v] = u; Q.push(v);
                    a[v] = min(a[u], cap[u][v]-flow[u][v]);
                }
        }
        if(a[t] == 0) break;
        for(int v = t; v != s; v = p[v])
        {
            flow[p[v]][v] += a[t];
            flow[v][p[v]] -= a[t];
        }
        f += a[t];
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    memset(cap, 0, sizeof(cap));

    return 0;
}
