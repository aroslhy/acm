#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 50000+5, MAXM = 50000+5;
int value[MAXN], A[MAXM], B[MAXM], lca[MAXM];
int n, m, e, qe;
int v[2*MAXN], next[2*MAXN], head[MAXN];
int qv[2*MAXM], qnext[2*MAXM], qhead[MAXN], cnt[2*MAXM];
int fa[MAXN];
bool vis[MAXN], ff[2*MAXN];
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e;
    e++;
    v[e] = x;
    next[e] = head[y]; head[y] = e;
    e++;
}
void addquery(int x, int y, int z)
{
    qv[qe] = y;
    qnext[qe] = qhead[x]; qhead[x] = qe;
    cnt[qe] = z;
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
        if (!ff[i])
        {
            ff[i^1] = 1;
            tarjan(v[i]);
            fa[v[i]] = u;
        }
    vis[u] = 1;
    for (int i = qhead[u]; i != -1; i = qnext[i])
        if (vis[qv[i]])
            lca[cnt[i]] = find(qv[i]);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(vis, 0, sizeof(vis));
        memset(head, -1, sizeof(head));
        memset(ff, 0, sizeof(ff));
        memset(qhead, -1, sizeof(qhead));
        e = 0; qe = 0;
        for (int i = 1; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addedge(x, y);
        }
        for (int i = 1; i <= n; i++)
            scanf("%d", &value[i]);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &A[i], &B[i]);
            addquery(A[i], B[i], i);
            addquery(B[i], A[i], i);
            lca[i] = 0;
        }
        tarjan(1);
        for (int i = 1; i <= m; i++)
        {
            int r = lca[i];
            int sum = value[r];
            int x = A[i];
            while (x != r)
            {
                for (int j = head[x]; j != -1; j = next[j])
                    if (ff[j])
                    {
                        sum += value[x];
                        x = v[j];
                        break;
                    }
            }
            int y = B[i];
            while (y != r)
            {
                for (int j = head[y]; j != -1; j = next[j])
                    if (ff[j])
                    {
                        sum += value[y];
                        y = v[j];
                        break;
                    }
            }
//            printf("%d\n", r);
            printf("%d\n", sum);
        }
    }
    return 0;
}
