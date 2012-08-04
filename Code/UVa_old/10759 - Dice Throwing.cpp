#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 24+5, MAXX = 150+5;
int n, x;
long long dp[MAXN][MAXX];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	while (scanf("%d%d", &n, &x))
	{
	    if (!n && !x) break;
	    memset(dp, 0, sizeof(dp));
	    dp[0][0] = 1;
	    for (int i = 1; i <= n; i++)
            for (int j = 1; j < x; j++)
            {
                for (int k = 1; k <= 6; k++)
                    if (j >= k)
                        dp[i][j] += dp[i-1][j-k];
//                printf("%d,%d:%lld\n", i, j, dp[i][j]);
            }
        long long tot = 1;
        for (int i = 1; i <= n; i++)
            tot *= 6;
        long long count = tot;
        for (int i = 1; i < x; i++)
            count -= dp[n][i];
//        printf("%lld/%lld\n", count, tot);
        for (long long i = 2; i <= 3; i++)
            while (!(count%i) && !(tot%i))
                count /= i, tot /= i;
        if (!count)
            printf("0\n");
        else if (count == tot)
            printf("1\n");
        else
            printf("%lld/%lld\n", count, tot);
	}
	return 0;
}
