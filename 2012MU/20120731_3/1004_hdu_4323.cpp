#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1500+5, MAXM = 10+5, MAXP = 400+5;
const int INF = 0x3f3f3f3f;
int T, n, m, t, cnt;
int d[MAXM][MAXM], next[MAXN][MAXM];
char str1[MAXN][MAXM], str2[MAXM];
int Distance(char *s1, char *s2)
{
    int l1 = strlen(s1), l2 = strlen(s2);
    for (int i = 0; i <= l1; i++)
        for (int j = 0; j <= l2; j++)
        {
            if (!(i*j))
                d[i][j] = i+j;
            else
            {
                d[i][j] = min(d[i-1][j]+1, d[i][j-1]+1);
                if (s1[i-1] == s2[j-1])
                    d[i][j] = min(d[i][j], d[i-1][j-1]);
                else
                    d[i][j] = min(d[i][j], d[i-1][j-1]+1);
            }
//            printf("%d,%d:%d\n", i, j, d[i][j]);
        }
    return d[l1][l2];
}
void dfs(int u)
{
    int dis = Distance(str1[u], str2);
    if (u && dis <= t)
        cnt++;
    for (int k = dis-t; k <= dis+t; k++)
        if (k >= 0 && next[u][k])
            dfs(next[u][k]);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        memset(next, 0, sizeof(next));
        scanf("%d%d", &n, &m);
        strcpy(str1[0], "");
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", str1[i]);
            for (int j = 0; ; )
            {
                int dis = Distance(str1[i], str1[j]);
                if (!next[j][dis])
                {
                    next[j][dis] = i;
                    break;
                }
                j = next[j][dis];
            }
        }
        printf("Case #%d:\n", cas);
        for (int i = 1; i <= m; i++)
        {
            scanf("%s%d", str2, &t);
            cnt = 0;
            dfs(0);
            printf("%d\n", cnt);
        }
    }
    return 0;
}
