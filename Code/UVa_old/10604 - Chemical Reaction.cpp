#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
const int MAXM = 6+5, MAXK = 10+2, INF = 1<<30;
int T, m, result[MAXM][MAXM], heat[MAXM][MAXM], k, tube[MAXK];
int dp[MAXK][MAXK][MAXK][MAXK][MAXK][MAXK], vis[MAXK][MAXK][MAXK][MAXK][MAXK][MAXK], num[MAXM];
int DP(int a, int b, int c, int d, int e, int f)
{
    int &res = dp[a][b][c][d][e][f];
    if (vis[a][b][c][d][e][f]) return res;
    res = INF;
    int n[MAXK] = {0, a, b, c, d, e, f};
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            if (n[i] && n[j])
            {
                if (i == j && n[j] < 2) continue;
                n[result[i][j]]++; n[i]--; n[j]--;
                res = min(res, DP(n[1], n[2], n[3], n[4], n[5], n[6])+heat[i][j]);
                n[result[i][j]]--; n[i]++; n[j]++;
            }
    vis[a][b][c][d][e][f] = 1;
    if (res == INF) res = 0;
//    printf("%d,%d,%d,%d,%d,%d:%d\n", a, b, c, d, e, f, res);
    return res;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d%d", &result[i][j], &heat[i][j]);
        scanf("%d", &k);
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= k; i++)
        {
            int tmp; scanf("%d", &tmp);
            num[tmp]++;
        }
        char s[3]; scanf("%s", s);
        memset(vis, 0, sizeof(vis));
        printf("%d\n", DP(num[1], num[2], num[3], num[4], num[5], num[6]));
    }
	return 0;
}
