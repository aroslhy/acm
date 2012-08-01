#include<cstdio>
#include<cstring>
using namespace std;
const int MAXM = 10+5, MAXN = 100+5, INF = 1<<30;
int m, n, M[MAXM][MAXN], dp[MAXM][MAXN];
inline int min(int x, int y) {return x<y?x:y;}
int next(int x, int y)
{
    if (x+y < 1)
        return m;
    else if (x+y > m)
        return 1;
    else
        return x+y;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	while (scanf("%d%d", &m, &n) != EOF)
	{
	    memset(dp, 0, sizeof(dp));
	    for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &M[i][j]), dp[i][j] = INF;
        for (int i = n; i >= 1; i--)
            for (int j = 1; j <= m; j++)
            {
                for (int k = -1; k <= 1; k++)
                {
                    if (j+k < 1)
                        dp[j][i] = min(dp[j][i], dp[m][i+1]+M[j][i]);
                    else if (j+k > m)
                        dp[j][i] = min(dp[j][i], dp[1][i+1]+M[j][i]);
                    else
                        dp[j][i] = min(dp[j][i], dp[j+k][i+1]+M[j][i]);
                }
//                printf("%d,%d:%d\n", j, i, dp[j][i]);
            }
        int u = INF, v;
        for (int i = 1; i <= m; i++)
            if (dp[i][1] < u)
                u = dp[i][1], v = i;
        int ans = u;
        for (int i = 1; i <= n; i++)
        {
            printf("%d%s", v, i == n ? "" : " ");
            for (int j = 1; j <= m; j++)
                if ((j == next(v, -1) || j == next(v, 0) || j == next(v, 1)) && dp[j][i+1] == u-M[v][i])
                {
                    u = u-M[v][i], v = j;
                    break;
                }
        }
        printf("\n%d\n", ans);
	}
	return 0;
}
