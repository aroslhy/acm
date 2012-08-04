#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
const int MAX = 1<<8;
int T, W, N, dp[MAX][MAX]; char line[MAX]; bool unsafe[MAX][MAX];
int DP(int x, int y)
{
    if (1+dp[x][y])
        return dp[x][y];
    dp[x][y] = 0;
    if (unsafe[x][y])
        return dp[x][y];
    if (x-1 >= 1)
        dp[x][y] += DP(x-1, y);
    if (y-1 >= 1)
        dp[x][y] += DP(x, y-1);
//    printf("%d,%d:%d\n", x, y, dp[x][y]);
    return dp[x][y];
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &W, &N); getchar();
        memset(unsafe, 0, sizeof(unsafe));
        while (fgets(line, MAX, stdin))
        {
            int len = strlen(line);
            if (len < 2) break;
            int w = line[0]-'0';
            int n = 0;
            for (int j = 1; j < len; j++)
            {
                if (isdigit(line[j]))
                    n = 10*n+line[j]-'0';
                else if (n)
                    unsafe[w][n] = 1, n = 0;
            }
//            for (int j = 1; j <= N; j++)
//                if (unsafe[w][j]) printf("%d %d\n", w, j);
        }
        memset(dp, -1, sizeof(dp));
        dp[1][1] = 1;
        printf("%d\n", DP(W, N));
        if (T) printf("\n");
    }
	return 0;
}
