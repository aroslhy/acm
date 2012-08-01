#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 500+5, MAXM = 52+5;
const int INF = 0x3f3f3f3f;
char s1[MAXN], s2[MAXN];
char c[MAXM];
int d[MAXN][MAXN][MAXM];
int match[1<<8];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    for (int i = 'a', j = 1; i <= 'z'; i++, j++)
    {
        match[i] = j;
        c[j] = i;
    }
    for (int i = 'A', j = 27; i <= 'Z'; i++, j++)
    {
        match[i] = j;
        c[j] = i;
    }
    while (scanf("%s", s1))
    {
        if (!strcmp(s1, "#")) break;
        scanf("%s", s2);
        int len1 = strlen(s1), len2 = strlen(s2);
        for (int i = 0; i <= len1; i++)
            for (int j = 0; j <= len2; j++)
                for (int k = 0; k <= 52; k++)
                {
                    if (i == len1)
                        d[i][j][k] = len2-j;
                    if (j == len2)
                        d[i][j][k] = len1-i;
                }
        for (int i = len1-1; i >= 0; i--)
            for (int j = len2-1; j >= 0; j--)
                for (int k = 0; k <= 52; k++)
                {
                    int &dp = d[i][j][k], l;
                    dp  = INF;
                    if (!k)
                    {
                        l = match[(int)s2[j+1]];
                        if (s1[i] == s2[j])
                        {
                            dp = min(dp, d[i+1][j+1][l]+(k != l ? 1 : 0));
                            dp = min(dp, d[i+1][j+1][k]);
                        }
                        else
                        {
                            dp = min(dp, d[i+1][j+1][l]+1+(k != l ? 1 : 0));
                            dp = min(dp, d[i+1][j+1][k]+1);
                        }
                    }
                    else
                    {
                        l = match[(int)s2[j+1]];
                        if (c[k] == s2[j])
                        {
                            dp = min(dp, d[i+1][j+1][l]+(k != l ? 1 : 0));
                            dp = min(dp, d[i+1][j+1][k]);
                        }
                        else
                        {
                            dp = min(dp, d[i+1][j+1][l]+1+(k != l ? 1 : 0));
                            dp = min(dp, d[i+1][j+1][k]+1);
                        }
                    }
                    l = match[(int)s2[j]];
                    dp = min(dp, d[i+1][j][l]+1+(k != l ? 1 : 0));
                    dp = min(dp, d[i+1][j][k]+1);
                    dp = min(dp, d[i][j+1][l]+1+(k != l ? 1 : 0));
                    dp = min(dp, d[i][j+1][k]+1);
//                    printf("%d,%d,%d:%d\n", i, j, k, dp);
                }
        int ans = INF;
        ans = min(ans, d[0][0][match[(int)s2[0]]]+(match[(int)s2[0]] ? 1 : 0));
        ans = min(ans, d[0][0][0]);
        printf("%d\n",ans);
    }
    return 0;
}
