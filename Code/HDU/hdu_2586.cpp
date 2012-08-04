#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 40000+5, MAXM = 200+5;
int T, a[MAXM], b[MAXM], lca[MAXM];
int n, m, e, qe;
int v[2*MAXN], next[2*MAXN], head[MAXN], w[2*MAXN];
int qv[2*MAXM], qnext[2*MAXM], qhead[MAXN], ord[2*MAXM];
int fa[MAXN];
bool vis[MAXN], rvs[2*MAXN];
void addedge(int x, int y, int z)
{
    v[e] = y; w[e] = z;
    next[e] = head[x]; head[x] = e;
    e++;
}
void addquery(int x, int y, int z)
{
    qv[qe] = y; ord[qe] = z;
    qnext[qe] = qhead[x]; qhead[x] = qe;
    qe++;
}
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void tarjan(int u)
{
    fa[u] = u;
    for (int i = head[u]; i != -1; i = next[i])
        if (!rvs[i])
        {
            rvs[i^1] = 1;
            tarjan(v[i]);
            fa[v[i]] = u;
        }
    vis[u] = 1;
    for (int i = qhead[u]; i != -1; i = qnext[i])
        if (vis[qv[i]])
            lca[ord[i]] = find(qv[i]);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        memset(head, -1, sizeof(head));
        memset(rvs, 0, sizeof(rvs));
        memset(qhead, -1, sizeof(qhead));
        e = 0; qe = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i < n; i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            addedge(x, y, z);
            addedge(y, x, z);
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &a[i], &b[i]);
            addquery(a[i], b[i], i);
            addquery(b[i], a[i], i);
        }
        tarjan(1);
        for (int i = 1; i <= m; i++)
        {
            int r = lca[i], x = a[i], y = b[i], ans = 0;
            while (x != r)
            {
                for (int j = head[x]; j != -1; j = next[j])
                    if (rvs[j])
                    {
                        ans += w[j]; x = v[j];
                        break;
                    }
            }
            while (y != r)
            {
                for (int j = head[y]; j != -1; j = next[j])
                    if (rvs[j])
                    {
                        ans += w[j]; y = v[j];
                        break;
                    }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
