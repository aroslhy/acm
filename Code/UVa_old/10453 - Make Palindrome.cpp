#include<cstdio>
#include<cstring>
using namespace std;
const int MAXL = 1000+5;
char str[MAXL];
int dp[MAXL][MAXL], p[MAXL][MAXL];
int DP(int x, int y)
{
    if (x >= y)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    if (str[x] == str[y])
        dp[x][y] = DP(x+1, y-1), p[x][y] = 0;
    else if (DP(x+1, y) <= DP(x, y-1))
        dp[x][y] = DP(x+1, y)+1, p[x][y] = 1;
    else
        dp[x][y] = DP(x, y-1)+1, p[x][y] = -1;
    return dp[x][y];
}
void Print(int x, int y)
{
    if (x > y)
        return;
    if (x == y)
        printf("%c", str[x]);
    else if (p[x][y] == 0)
        printf("%c", str[x]), Print(x+1, y-1), printf("%c", str[x]);
    else if (p[x][y] == 1)
        printf("%c", str[x]), Print(x+1, y), printf("%c", str[x]);
    else if (p[x][y] == -1)
        printf("%c", str[y]), Print(x, y-1), printf("%c", str[y]);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%s", str) != EOF)
    {
        int len = strlen(str);
        memset(dp, -1, sizeof(dp));
        printf("%d ", DP(0, len-1));
        Print(0, len-1);
        printf("\n");
    }
	return 0;
}
