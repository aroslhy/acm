#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
const int MAXN = 300+5;
char line[1<<7]; int N, L1, L2; long long dp[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	while (fgets(line, 1<<7, stdin))
	{
	    int n = sscanf(line, "%d%d%d", &N, &L1, &L2);
	    memset(dp, 0, sizeof(dp)); dp[0] = 1;
	    long long tmp = 0;
	    switch (n)
	    {
        case 1:
	        for (int i = 1; i <= 300; i++)
                for (int j = 1; j <= N; j++)
                    if (j >= i)
                        dp[j] += dp[j-i];
            printf("%lld\n", dp[N]);
            break;
        case 2:
            if (L1 > 300) L1 = 300;
            for (int i = 1; i <= L1; i++)
                for (int j = 1; j <= N; j++)
                    if (j >= i)
                        dp[j] += dp[j-i];
            printf("%lld\n", dp[N]);
            break;
        case 3:
            if (L1 > 300) L1 = 300;
            if (L2 > 300) L2 = 300;
            for (int i = 1; i <= L2; i++)
            {
                if (i == L1) tmp = dp[N];
                for (int j = 1; j <= N; j++)
                    if (j >= i)
                        dp[j] += dp[j-i];
            }
            printf("%lld\n", dp[N]-tmp);
            break;
        default:
            break;
	    }
	}
	return 0;
}
