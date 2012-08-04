#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
using namespace std;
const int MAXN = 900+5;
int T, a, b;
int e, n;
int v[MAXN], next[MAXN], head[MAXN];
int nrt[MAXN], fa[MAXN];
bool vis[MAXN];
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e;
    e++;
}
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void tarjan(int u)
{
    fa[u] = u;
    for (int i = head[u]; i != -1; i = next[i])
    {
        tarjan(v[i]);
        fa[v[i]] = u;
    }
    vis[u] = 1;
    if (vis[a] && u == b)
        printf("%d\n", find(a));
    else if (vis[b] && u == a)
        printf("%d\n", find(b));
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        memset(nrt, 1, sizeof(nrt));
        memset(head, -1, sizeof(head));
        e = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int x, y, m;
            scanf("%d", &x);
            scanf(":(%d)", &m);
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &y);
                addedge(x, y);
            }
        }
        scanf("%d%d", &a, &b);
        for (int i = 1; i <= n; i++)
            if (nrt[i])
            {
                tarjan(i);
                break;
            }
    }
    return 0;
}
