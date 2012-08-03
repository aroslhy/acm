#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 2000+5, MAXM = 2000000+5, MAXP = 80000+5;
int T, N, indgr[MAXN];
char g[MAXN][MAXN];
bool vis[MAXN];
void Init()
{
    memset(indgr, 0, sizeof(indgr));
    memset(vis, 0, sizeof(vis));
}
int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        Init();
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%s", g[i]);
            for (int j = 0; j < N; j++)
                if (g[i][j] == '1')
                    indgr[j]++;
        }
        int cnt = 0;
        bool flag = 1;
        while (flag)
        {
            flag = 0;
            for (int u = 0; u < N; u++)
                if (!indgr[u] && !vis[u])
                {
                    vis[u] = 1;
                    for (int v = 0; v < N; v++)
                        if (g[u][v] == '1')
                            indgr[v]--;
                    flag = 1;
                    cnt++;
                }
        }
        printf("Case #%d: %s\n", cas, cnt != N ? "Yes" : "No");
    }
    return 0;
}
