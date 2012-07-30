#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 10+5, MAXM = 10+5;
const int INF = 0x3f3f3f3f;
int T, a[MAXN], g[MAXN][MAXN], ans[MAXN], cnt;
bool vis[MAXN], ocp[MAXN];
void dfs(int x)
{
    if (x == 8)
    {
        bool flag = 1;
        for (int i = 0; i < 8 && flag; i++)
            for (int j = 0; j < 8 && flag; j++)
                if (g[i][j] && fabs(a[i]-a[j]) <= 1)
                    flag = 0;
        if (flag)
        {
            cnt++;
            if (cnt == 1)
                memcpy(ans, a, sizeof(a));
        }
        return;
    }
    if (ocp[x])
        dfs(x+1);
    else
    {
        for (int i = 1; i <= 8; i++) if (!vis[i])
        {
            int tmp = a[x];
            a[x] = i;
            vis[i] = 1;
            dfs(x+1);
            vis[i] = 0;
            a[x] = tmp;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    g[0][1] = 1; g[0][2] = 1; g[0][3] = 1;
    g[1][0] = 1; g[1][2] = 1; g[1][4] = 1; g[1][5] = 1;
    g[2][0] = 1; g[2][1] = 1; g[2][3] = 1; g[2][4] = 1; g[2][5] = 1; g[2][6] = 1;
    g[3][0] = 1; g[3][2] = 1; g[3][5] = 1; g[3][6] = 1;
    g[4][1] = 1; g[4][2] = 1; g[4][5] = 1; g[4][7] = 1;
    g[5][1] = 1; g[5][2] = 1; g[5][3] = 1; g[5][4] = 1; g[5][6] = 1; g[5][7] = 1;
    g[6][2] = 1; g[6][3] = 1; g[6][5] = 1; g[6][7] = 1;
    g[7][4] = 1; g[7][5] = 1; g[7][6] = 1;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        memset(vis, 0, sizeof(vis));
        memset(ocp, 0, sizeof(ocp));
        for (int i = 0; i < 8; i++)
        {
            scanf("%d", &a[i]);
            if (a[i])
            {
                vis[a[i]] = 1;
                ocp[i] = 1;
            }
        }
        cnt = 0;
        dfs(0);
        printf("Case %d:", cas);
        if (!cnt)
            printf(" No answer\n");
        else if (cnt == 1)
        {
            for (int i = 0; i < 8; i++)
                printf(" %d", ans[i]);
            printf("\n");
        }
        else
            printf(" Not unique\n");
    }
    return 0;
}
