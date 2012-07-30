#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 30+5, MAXM = 500000+5;
const int INF = 0x3f3f3f3f;
int K, N, M, g[MAXN][MAXN], st, CNT, ans;
bool vis[MAXN];
bool dfs2(int u)
{
    vis[u] = 1;
    if (u == 1)
        return 1;
    for (int v = 0; v < N; v++)
        if (g[u][v]&st && !vis[v])
            if (dfs2(v))
                return 1;
    return 0;
}
void dfs1(int x)
{
    if (x == K)
    {
        memset(vis, 0, sizeof(vis));
        if (dfs2(0))
        {
            int cnt = 0;
            for (int i = 0; i < K; i++)
                if ((1<<i)&st)
                    cnt++;
            if (cnt < CNT)
            {
                CNT = cnt;
                ans = st;
            }
        }
        return;
    }
    for (int b = 0; b <= 1; b++)
    {
        if (b)
            st |= (1<<x);
        else
            st &= (~(1<<x));
        dfs1(x+1);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &K, &N, &M);
    for (int i = 1; i <= M; i++)
    {
        int V1, V2, C;
        scanf("%d%d%d", &V1, &V2, &C);
        g[V1][V2] |= (1<<C);
        g[V2][V1] |= (1<<C);
    }
    st = 0; CNT = INF;
    dfs1(0);
    printf("%d\n", CNT);
    for (int i = 0; i < K; i++) if ((1<<i)&ans)
    {
        printf("%d", i);
        printf(i < CNT ? " " : "\n");
    }
    return 0;
}
