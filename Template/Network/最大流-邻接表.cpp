#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1000+5, MAXM = 1000+5;
const int INF = 0x3f3f3f3f;
int e, s, t, n;
int v[MAXM], next[MAXM], head[MAXN];
int cap[MAXM], a[MAXN], f;
int pv[MAXN], pe[MAXN];
queue<int> Q;
void addedge(int u_, int v_, int c_)
{
    v[e] = v_; cap[e] = c_;
    next[e] = head[u_]; head[u_] = e;
    e++;
    v[e] = u_; cap[e] = 0;
    next[e] = head[v_]; head[v_] = e;
    e++;
}
void maxflow()
{
    f = 0;
    for (;;)
    {
        memset(a, 0, sizeof(a));
        a[s] = INF;
        Q.push(s);
        while (!Q.empty())
        {
            int u = Q.front(); Q.pop();
            for (int e = head[u]; e != -1; e = next[e])
                if(!a[v[e]] && cap[e])
                {
                    Q.push(v[e]);
                    a[v[e]] = min(a[u], cap[e]);
                    pv[v[e]] = u; pe[v[e]] = e;
                }
        }
        if (!a[t]) break;
        for (int v = t; v != s; v = pv[v])
        {
            cap[pe[v]] -= a[t];
            cap[pe[v]^1] += a[t];
        }
        f += a[t];
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    memset(cap, 0, sizeof(cap));
    memset(head, -1, sizeof(head));
    e = 0;

    return 0;
}
