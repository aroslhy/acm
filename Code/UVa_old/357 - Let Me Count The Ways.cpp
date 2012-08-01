#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 30000+5;
int c[] = {0, 1, 5, 10, 25, 50}, n;
long long dp[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &n) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= 5; i++)
            for (int j = 0; j <= n; j++)
                if (j >= c[i])
                    dp[j] += dp[j-c[i]];
//        for (int i = 0; i <= n; i++)
//            printf("%d:%d\n", i, dp[i]);
        if (dp[n] == 1)
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
    }
	return 0;
}
