#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXL = 16+5, MAXN = 25000+5;
char word[MAXN][MAXL]; int dp[MAXN];
int Search(int l, int r, char *s)
{
    int m, t;
    while (l < r)
    {
        m = l+(r-l)/2;
        if (!(t = strcmp(s, word[m])))
            return m;
        else if (t > 0)
            l = m+1;
        else
            r = m;
    }
    if (!strcmp(s, word[m]))
        return m;
    return -1;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n = 0;
    for (int i = 1; scanf("%s", word[i]) != EOF; i++) n++;
    memset(dp, 0, sizeof(dp));
    int ans = dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        int len = strlen(word[i]);
        char t[MAXL];
        for (int j = len-1; j >= 0; j--)
        {
            strcpy(t, word[i]);
            for (int k = j; k < len; k++)
                t[k] = t[k+1];
            int p = Search(0, i, t);
            if (p != -1)
                dp[i] = max(dp[i], dp[p]+1);
        }
        for (int j = len; j >= 0; j--)
        {
            strcpy(t, word[i]);
            for (int k = len; k >= j; k--)
                t[k+1] = t[k];
            int up;
            if (j == len)
                up = 25;
            else
                up = word[i][j]-'a';
            for (int k = 0; k <= up; k++)
            {
                t[j] = j+'a';
                int p = Search(0, i, t);
                if (p != -1)
                    dp[i] = max(dp[i], dp[p]+1);
            }
        }
        for (int j = len-1; j >= 0; j--)
        {
            strcpy(t, word[i]);
            for (int k = 0; k < word[i][j]-'a'; k++)
            {
                t[j] = k+'a';
                int p = Search(0, i, t);
                if (p != -1)
                    dp[i] = max(dp[i], dp[p]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
	return 0;
}
