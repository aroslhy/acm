#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 100+5, MAXL = 30+5;
char seq1[MAXN][MAXL], seq2[MAXN][MAXL];
int len1, len2, dp[MAXN][MAXN]; bool p[MAXN][MAXN];
void Print(int x, int y)
{
    if (x >= len1 || y >= len2)
        return;
    if (p[x][y])
    {
        printf("%s%s", seq1[x], dp[x][y] == 1 ? "" : " ");
        Print(x+1, y+1);
    }
    else
        dp[x+1][y] > dp[x][y+1] ? Print(x+1, y) : Print(x, y+1);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%s", seq1[0]) != EOF)
    {
        len1 = 1;
        while (scanf("%s", seq1[len1]) && seq1[len1][0] != '#')
            len1++;
        len2 = 0;
        while (scanf("%s", seq2[len2]) && seq2[len2][0] != '#')
            len2++;
        memset(dp, 0, sizeof(dp));
        memset(p, 0, sizeof(p));
        for (int i = len1-1; i >= 0; i--)
            for (int j = len2-1; j >= 0; j--)
            {
                if (!strcmp(seq1[i], seq2[j]))
                    dp[i][j] = dp[i+1][j+1]+1, p[i][j] = 1;
                else
                {
                    if (dp[i+1][j] > dp[i][j+1])
                        dp[i][j] = dp[i+1][j];
                    else
                        dp[i][j] = dp[i][j+1];
                }
            }
        Print(0, 0), printf("\n");
    }
	return 0;
}
