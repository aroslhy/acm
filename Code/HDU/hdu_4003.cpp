//2012-08-13 18:05:48	Accepted	4003	484MS	1080K	1323 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5, MAXM = 20000+5, MAXP = 10+5;
int N, S, K, X, Y, W;
int e, head[MAXN], next[MAXM], v[MAXM];
int w[MAXM], d[MAXN][MAXP];
void addedge(int x, int y, int z)
{
    v[e] = y; w[e] = z;
    next[e] = head[x]; head[x] = e++;
}
void dfs(int u, int fa = 0)
{
    for (int i = head[u]; i != -1; i = next[i])
        if (v[i] != fa)
            dfs(v[i], u);
    for (int i = head[u]; i != -1; i = next[i])
        if (v[i] != fa)
        {
            for (int j = K; j >= 0; j--)
            {
                d[u][j] += d[v[i]][0]+w[i]*2;
                for (int k = 1; k <= j; k++)
                    d[u][j] = min(d[u][j], d[u][j-k]+d[v[i]][k]+k*w[i]);
            }
        }
}
void init()
{
    e = 0;
    memset(head, -1, sizeof(head));
    memset(d, 0, sizeof(d));
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    while (scanf("%d%d%d", &N, &S, &K) != EOF)
    {
        init();
        for (int i = 1; i < N; i++)
        {
            scanf("%d%d%d", &X, &Y, &W);
            addedge(X, Y, W);
            addedge(Y, X, W);
        }
        dfs(S);
        printf("%d\n", d[S][K]);
    }
    return 0;
}
