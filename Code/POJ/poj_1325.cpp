#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100*2+5, MAXM = 1000+5;
const int INF = 0x3f3f3f3f;
int n, m, k;
int e, head[MAXN], next[MAXM], v[MAXM];
int xM[MAXN], yM[MAXN];
bool vis[MAXN];
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e++;
}
bool SearchPath(int u)
{
    for (int i = head[u]; i != -1; i = next[i])
        if (!vis[v[i]])
        {
            vis[v[i]] = 1;
            if (yM[v[i]] == -1 || SearchPath(yM[v[i]]))
            {
                yM[v[i]] = u;
                xM[u] = v[i];
                return 1;
            }
        }
    return 0;
}
int MaxMatch()
{
    int ret = 0;
    memset(xM, -1, sizeof(xM));
    memset(yM, -1, sizeof(yM));
    for (int u = 0; u < n; u++)
        if (xM[u] == -1)
        {
            memset(vis, 0, sizeof(vis));
            if (SearchPath(u)) ret++;
        }
    return ret;
}
int main()
{
    freopen("input.txt", "r", stdin);
    while (scanf("%d", &n) && n)
    {
        e = 0;
        memset(head, -1, sizeof(head));
        scanf("%d%d", &m, &k);
        for (int j = 1; j <= k; j++)
        {
            int i, x, y;
            scanf("%d%d%d", &i, &x, &y);
            if (x && y)
                addedge(x, n+y);
        }
        printf("%d\n", MaxMatch());
    }
    return 0;
}
