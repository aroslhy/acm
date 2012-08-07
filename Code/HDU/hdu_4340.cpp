//2012-08-07 21:31:18	Accepted	4340	0MS	228K	1476 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5, MAXM = 200+5;
const int INF = 0x3f3f3f3f;
int N, a[2][MAXN], x, y;
int d[MAXN][2][2];
int e, head[MAXN], next[MAXM], v[MAXM];
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e++;
}
void Init()
{
    e = 0;
    memset(head, -1, sizeof(head));
}
void dfs(int u, int fa)
{
    for (int i = head[u]; i != -1; i = next[i]) if (v[i] != fa)
        dfs(v[i], u);
    for (int j = 0; j < 2; j++)
    {
        int sum = 0, det = INF;
        for (int i = head[u]; i != -1; i = next[i]) if (v[i] != fa)
        {
            sum += min(d[v[i]][j][0], d[v[i]][j^1][1]);
            det = min(det, d[v[i]][j][1]-min(d[v[i]][j][0], d[v[i]][j^1][1]));
        }
        d[u][j][0] = a[j][u]/2+sum;
        d[u][j][1] = min(a[j][u]+sum, a[j][u]/2+sum+det);
    }
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    while (scanf("%d", &N) != EOF)
    {
        Init();
        for (int j = 0; j < 2; j++)
            for (int i = 1; i <= N; i++)
                scanf("%d", &a[j][i]);
        for (int i = 1; i < N; i++)
        {
            scanf("%d%d", &x, &y);
            addedge(x, y);
            addedge(y, x);
        }
        dfs(1, 0);
        int ans = min(d[1][0][1], d[1][1][1]);
        printf("%d\n", ans);
    }
    return 0;
}
