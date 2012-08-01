#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 9+5, MAXM = 200000+5, MAXP = 1000000+5;
int N, g[MAXN][MAXN], path[MAXN], cnt = 0;
bool vis[MAXN];
void dfs(int s, int u)
{
    if (u == s && cnt)
    {
        for (int i = 0; i < cnt; i++)
            printf("%d", path[i]);
        printf("\n");
        return;
    }
    path[cnt] = u;
    for (int v = 0; v < N; v++)
        if (g[u][v] && !vis[v] && v >= s)
        {
            vis[v] = 1;
            cnt++;
            dfs(s, v);
            cnt--;
            vis[v] = 0;
        }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &g[i][j]);
        for (int u = 0; u < N; u++)
            dfs(u, u);
        printf("\n");
    }
    return 0;
}
