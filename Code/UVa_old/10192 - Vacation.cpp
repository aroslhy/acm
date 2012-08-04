#include<cstdio>
#include<cstring>
using namespace std;
const int MAXL = 100+5;
char str1[MAXL], str2[MAXL];
int dp[MAXL][MAXL];
inline int max(int x, int y) {return x>y?x:y;}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    for (int T = 1; ; T++)
    {
        fgets(str1, MAXL, stdin);
        if (str1[0] == '#') break;
        fgets(str2, MAXL, stdin);
        memset(dp, 0, sizeof(dp));
        int len1 = strlen(str1)-1, len2 = strlen(str2)-1;
        for (int i = len1-1 ; i >= 0; i--)
            for (int j = len2-1; j >= 0; j--)
            {
                if (str1[i] == str2[j])
                    dp[i][j] = dp[i+1][j+1]+1;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        printf("Case #%d: you can visit at most %d cities.\n", T, dp[0][0]);
    }
    return 0;
}
