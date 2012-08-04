/*
ID: bigocea1
PROG: stamps
LANG: C++
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 50+5, MAXK = 200+5, INF = 1<<30;
int K, N, value[MAXN], dp[2000000+5];
int main()
{
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
    scanf("%d%d", &K, &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &value[i]);
    dp[0] = 0;
    int i;
    for (i = 1; ; i++)
    {
        dp[i] = INF;
        for (int j = 1; j <= N; j++)
            if (i-value[j] >= 0 && dp[i-value[j]] < K)
                dp[i] = min(dp[i], dp[i-value[j]]+1);
        if (dp[i] == INF) break;
    }
    printf("%d\n", i-1);
	return 0;
}
