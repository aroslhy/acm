#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 200+5, MAXM = 40000+5;
const int INF = 0x3f3f3f3f;
int T, n, x[MAXN], y[MAXN], r[MAXN];
int e, head[MAXN], next[MAXM], v[MAXM];
int d[3][MAXN], inq[MAXN];
queue<int> Q;
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e++;
}
void spfa(int s)
{
    for (int i = 0; i < n; i++)
        d[s][i] = (i == s ? 0 : INF);
    memset(inq, 0, sizeof(inq));
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        inq[u] = 0;
        for(int e = head[u]; e != -1; e = next[e])
            if(d[s][v[e]] > d[s][u]+1)
            {
                d[s][v[e]] = d[s][u]+1;
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
    scanf("%d", &T);
    while (T--)
    {
        e = 0;
        memset(head, -1, sizeof(head));
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &x[i], &y[i], &r[i]);
            for (int j = 0; j < i; j++)
                if ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) <= (r[i]+r[j])*(r[i]+r[j]))
                {
                    addedge(i, j);
                    addedge(j, i);
                }
        }
        for (int i = 0; i < 3; i++)
            spfa(i);
        int mind = INF;
        for (int i = 0; i < n; i++)
            if (d[0][i] < INF && d[1][i] < INF && d[2][i] < INF)
                mind = min(mind, d[0][i]+d[1][i]+d[2][i]);
        if (mind < INF)
            printf("%d\n", n-(mind+1));
        else
            printf("-1\n");
    }
    return 0;
}
