#include<cstdio>
#include<cstring>
using namespace std;
const int MAXL = 1000+5;
int T, dp[MAXL][MAXL];
char str[MAXL];
inline int max(int x, int y) {return x>y?x:y;}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T); getchar();
    while (T--)
    {
        memset(dp, 0, sizeof(dp));
        fgets(str, MAXL, stdin);
        int len = strlen(str)-1;
        for (int i = len-1; i >= 0; i--)
            for (int j = 0; j <= len-1; j++)
            {
                if (i == j)
                    dp[i][j] = 1;
                else if (i+1 == j)
                    if (str[i] == str[j])
                        dp[i][j] = 2;
                    else
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                else if (i+1 < j)
                {
                    if (str[i] == str[j])
                        dp[i][j] = dp[i+1][j-1]+2;
                    else
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
//        for (int i = len-1; i >= 0; i--)
//            for (int j = 0; j <= len-1; j++)
//                if (i <= j) printf("%d,%d:%d\n", i+1, j+1, dp[i][j]);
        printf("%d\n", dp[0][len-1]);
    }
	return 0;
}
