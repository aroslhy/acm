//2012-09-13 22:21:22	Accepted	4081	93MS	8028K	2154 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5, MAXM = 2000+5;
const int INF = 0x3f3f3f3f;
int T, N, X[MAXN], Y[MAXN], P[MAXN];
int e, head[MAXN], next[MAXM], u[MAXM], v[MAXM];
int fa[MAXN];
double cost[MAXN][MAXN], w[MAXM];
pair<double, int> lowc[MAXN];
bool vis[MAXN];
void addedge(int x, int y, double z)
{
    u[e] = x; v[e] = y; w[e] = z;
    next[e] = head[x]; head[x] = e++;
}
double prim()
{
    double res = 0;
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    for (int i = 2; i <= N; i++)
        lowc[i] = make_pair(cost[1][i], 1);
    for (int i = 2; i <= N; i++)
    {
        double minc = INF;
        int p = -1;
        for (int j = 1; j <= N; j++)
            if (!vis[j] && lowc[j].first < minc)
            {
                minc = lowc[j].first;
                p = j;
            }
        addedge(lowc[p].second, p, lowc[p].first);
        addedge(p, lowc[p].second, lowc[p].first);
        res += minc;
        vis[p] = 1;
        for (int j = 1; j <= N; j++)
            if (!vis[j] && cost[p][j] < lowc[j].first)
                lowc[j] = make_pair(cost[p][j], p);
    }
    return res;
}
int dfs(int u)
{
    int res = P[u];
    for (int i = head[u]; i != -1; i = next[i])
        if (v[i] != fa[u])
        {
            fa[v[i]] = u;
            res = max(res, dfs(v[i]));
        }
    return res;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        e = 0;
        memset(head, -1, sizeof(head));
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
        {
            scanf("%d%d%d", &X[i], &Y[i], &P[i]);
            for (int j = 1; j < i; j++)
                cost[i][j] = cost[j][i] = sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
        }
        double mst = prim(), ans = 0;
        for (int i = 0; i < N-1; i++)
        {
            fa[u[i<<1]] = v[i<<1];
            fa[v[i<<1]] = u[i<<1];
            ans = max(ans, (dfs(u[i<<1])+dfs(v[i<<1]))/(mst-w[i<<1]));
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
