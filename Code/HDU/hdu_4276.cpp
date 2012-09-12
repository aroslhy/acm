//2012-09-12 21:12:38	Accepted	4276	390MS	424K	2093 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5, MAXM = 500+5;
int N, T, a, b, t, A[MAXN];
int e, head[MAXN], next[MAXM], v[MAXM], w[MAXM];
int fa[MAXN], d[MAXN][MAXM];
void addedge(int x, int y, int z)
{
    v[e] = y; w[e] = z;
    next[e] = head[x]; head[x] = e++;
}
void mark(int u)
{
    for (int i = head[u]; i != -1; i = next[i])
        if (v[i] != fa[u])
        {
            fa[v[i]] = u;
            mark(v[i]);
        }
}
void dfs(int u)
{
    fill(d[u], d[u]+T+1, A[u]);
    for (int i = head[u]; i != -1; i = next[i])
        if (v[i] != fa[u])
        {
            dfs(v[i]);
            for (int j = T; j >= 0; j--)
                for (int k = 0; k <= j; k++)
                    if (j >= k+w[i]*2)
                        d[u][j] = max(d[u][j], d[u][j-k-w[i]*2]+d[v[i]][k]);
        }
}
int main()
{
    while (scanf("%d%d", &N, &T) != EOF)
    {
        e = 0;
        memset(head, -1, sizeof(head));
        for (int i = 1; i < N; i++)
        {
            scanf("%d%d%d", &a, &b, &t);
            addedge(a, b, t);
            addedge(b, a, t);
        }
        for (int i = 1; i <= N; i++)
            scanf("%d", &A[i]);
        int ans = 0;
        mark(1);
        int u = N;
        for (;;)
        {
            ans += A[u]; A[u] = 0;
            if (u == 1)
                break;
            for (int i = head[u]; i != -1; i = next[i])
                if (v[i] == fa[u])
                {
                    u = v[i];
                    T -= w[i]; w[i] = 0; w[i^1] = 0;
                    break;
                }
        }
        if (T < 0)
            printf("Human beings die in pursuit of wealth, and birds die in pursuit of food!\n");
        else
        {
            dfs(1);
//            for (int u = 1; u <= N; u++)
//                for (int i = 0; i <= T; i++)
//                    printf("%d,%d:%d\n", u, i, d[u][i]);
            ans += d[1][T];
            printf("%d\n", ans);
        }
    }
    return 0;
}
