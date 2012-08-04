#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5;
int T, amount, num, mini[MAXN], maxi[MAXN], dp[450000+5], bottle[4500+5];
bool vis[4500+5];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
	    scanf("%d%d", &amount, &num);
	    amount *= 1000;
	    memset(vis, 0, sizeof(vis));
	    memset(bottle, 0, sizeof(bottle));
	    int cnt = 0, limit = 1<<30;
	    for (int i = 1; i <= num; i++)
	    {
            scanf("%d%d", &mini[i], &maxi[i]);
            for (int j = mini[i]; j <= maxi[i]; j++)
                if (!vis[j]) bottle[++cnt] = j, vis[j] = 1;
            limit = min(limit, (maxi[i]*mini[i]/(maxi[i]-mini[i])));
//            printf("%d\n", limit);
	    }
	    if (amount >= limit)
	    {
	        printf("0\n");
            if (T) printf("\n");
	        continue;
	    }
	    memset(dp, 0, sizeof(dp));
	    for (int i = 1; i <= cnt; i++)
            for (int j = bottle[i]; j <= amount; j++)
            {
                dp[j] = max(dp[j], dp[j-bottle[i]]+bottle[i]);
//                printf("%d:%d\n", j, dp[j]);
            }
        printf("%d\n", amount-dp[amount]);
        if (T) printf("\n");
	}
	return 0;
}
