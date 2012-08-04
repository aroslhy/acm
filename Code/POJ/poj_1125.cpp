#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int MAXN = 100+5, MAXM = 100*100+5;
const int INF = 0x3f3f3f3f;
int n, m, e, s;
int v[MAXM], next[MAXM], head[MAXN];
int w[MAXM], d[MAXN];
bool inq[MAXN];
queue<int> Q;
void addedge(int x, int y, int z)
{
    v[e] = y; w[e] = z;
    next[e] = head[x]; head[x] = e;
    e++;
}
void spfa()
{
    for (int i = 1; i <= n; i++)
        d[i] = (i == s ? 0 : INF);
    memset(inq, 0, sizeof(inq));
    Q.push(s);
    inq[s] = 1;
    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        inq[u] = 0;
        for(int e = head[u]; e != -1; e = next[e])
            if(d[v[e]] > d[u]+w[e])
            {
                d[v[e]] = d[u]+w[e];
                if(!inq[v[e]])
                {
                    Q.push(v[e]);
                    inq[v[e]] = 1;
                }
            }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &n))
    {
        if (!n) break;
        memset(head, -1, sizeof(head));
        e = 0;
        for (int i = 1; i <= n; i++)
        {
            int c;
            scanf("%d", &c);
            while (c--)
            {
                int x, y;
                scanf("%d%d", &x, &y);
                addedge(i, x, y);
            }
        }
        int idx = 0, ans = INF;
        for (s = 1; s <= n; s++)
        {
            spfa();
            int ans_ = 0;
            for (int i = 1; i <= n; i++)
                if (i != s)
                    ans_ = max(ans_, d[i]);
            if (ans_ < ans)
            {
                ans = ans_;
                idx = s;
            }
        }
        if (idx)
            printf("%d %d\n", idx, ans);
        else
            printf("disjoint\n");
    }
    return 0;
}
