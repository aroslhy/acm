#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 500+5, MAXC = 100+5;
int N, color[MAXN][6+5], dp[MAXN][MAXC], p[MAXN][MAXC], q[MAXN][MAXC], T = 0;
char face[6+5][10] = {"\0", "front", "back", "left", "right", "top", "bottom"};
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	while (scanf("%d", &N))
	{
	    if (!N) break;
	    T++;
	    for (int i = 1; i <= N; i++)
            for (int j = 1; j <= 6; j++)
                scanf("%d", &color[i][j]);
	    memset(dp, 0, sizeof(dp));
	    memset(p, 0, sizeof(p));
        for (int i = N; i >= 1; i--)
            for (int j = 1; j <= 100; j++)
            {
                dp[i][j] = dp[i+1][j];
                for (int k = 1; k <= 6; k++)
                    if (j == color[i][k] && dp[i+1][color[i][k%2 ? k+1 : k-1]]+1 > dp[i][j])
                    {
                        dp[i][j] = dp[i+1][color[i][k%2 ? k+1 : k-1]]+1;
                        p[i][j] = 1, q[i][j] = k;
//                        printf("p(%d,%d)=%d\n", i, j, p[i][j]);
                    }
//                printf("%d,%d:%d\n", i, j, dp[i][j]);
            }
        int ans = 0, c, f;
        for (int i = 1; i <= 100; i++)
            if (dp[1][i] > ans)
                ans = dp[1][i], c = i;
        printf("Case #%d\n", T);
        printf("%d\n", ans);
        for (int i = 1; i <= N; i++)
        {
//            printf("c=%d  ", c);
            if (p[i][c])
            {
                f = q[i][c];
                printf("%d %s\n", i, face[f]);
                c = color[i][f%2 ? f+1 : f-1];
            }
        }
        printf("\n");
	}
	return 0;
}
