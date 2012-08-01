#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN = 10+5, MAXK = 30+5;
int k, n, m[MAXK][MAXN], dp[MAXK];
int cmp1(const void *a, const void *b) {return *(int *)b-*(int *)a;}
bool cmp2(const int *a, const int *b)
{
    for (int i = 1; i <= n; i++)
        if (a[i] >= b[i])
            return 0;
    return 1;
}
int DP(int x)
{
    if (dp[x] > 0)
        return dp[x];
    dp[x] = 1;
    for (int i = 1; i <= k; i++)
        if (cmp2(m[i], m[x]) && DP(i)+1 > dp[x])
            dp[x] = DP(i)+1;
//    printf("%d:%d\n", x, dp[x]);
    return dp[x];
}
void print_ans(int x)
{
    for (int i = 1; i <= k; i++)
        if (cmp2(m[i], m[x]) && dp[i]+1 == dp[x])
        {
            print_ans(i);
            printf(" ");
            break;
        }
    printf("%d", x);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	while (scanf("%d%d", &k, &n) != EOF)
	{
	    memset(dp, 0, sizeof(dp));
	    for (int i = 1; i <= k; i++)
	    {
            for (int j = 1; j <= n; j++)
                scanf("%d", &m[i][j]);
            qsort(m[i]+1, n, sizeof(int), cmp1);

//            printf("%d: ", i);
//            for (int j = 1; j <= n; j++)
//                printf("%2d ", m[i][j]);
//            printf("\n");
	    }
        int ans = 0, t;
        for (int i = 1; i <= k; i++)
            if (DP(i) > ans)
                ans = DP(i), t = i;
        printf("%d\n", ans);
        print_ans(t), printf("\n");
	}
	return 0;
}
