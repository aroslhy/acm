/*
ID: bigocea1
PROG: humble
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
const int MAXK = 100+5, MAXN = 100000+5, INF = 2147483647;
int K, N, p[MAXK], dp[MAXN], s[MAXK];
int main()
{
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);
	scanf("%d%d", &K, &N);
	for (int i = 1; i <= K; i++)
        scanf("%d", p+i);
    dp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        dp[i] = INF;
        for (int j = 1; j <= K; j++)
            for (int k = s[j]; ; k++)
                if (dp[k]*p[j] > dp[i-1])
                {
                    dp[i] = min(dp[i], dp[k]*p[j]);
                    s[j] = k;
                    break;
                }
//        printf("%d:%d\n", i, dp[i]);
    }
    printf("%d\n", dp[N]);
	return 0;
}
