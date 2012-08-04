#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 300*100+5, c[11+5] = {0, 5/5, 10/5, 20/5, 50/5, 100/5, 200/5, 500/5, 1000/5, 2000/5, 5000/5, 10000/5};
double r; int n; long long dp[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	while (scanf("%lf", &r) && r)
	{
	    n = (int)(100*r+0.5);
	    memset(dp, 0, sizeof(dp));
	    if (n%5)
            n = 0;
        else
            n /= 5, dp[0] = 1;
	    for (int i = 1; i <= 11; i++)
            for (int j = 1; j <= n; j++)
            {
                if (j >= c[i])
                    dp[j] += dp[j-c[i]];
//                printf("%d:%d\n", j, dp[j]);
            }
        printf("%6.2lf%17lld\n", r, dp[n]);
	}
	return 0;
}
