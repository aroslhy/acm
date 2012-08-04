#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 20+5;
int n, c[MAXN], r[MAXN];
int dp[MAXN][MAXN];
inline int Max(int x, int y) {return x>y?x:y;}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        c[t] = i;
    }
    int u;
    while (scanf("%d", &u) != EOF)
    {
        r[u] = 1;
        for (int i = 2; i <= n; i++)
        {
            int t;
            scanf("%d", &t);
            r[t] = i;
        }
        for (int i = n; i >= 1; i--)
            for (int j = n; j >= 1; j--)
            {
                if (r[j] == c[i])
                    dp[i][j] = dp[i+1][j+1]+1;
                else
                    dp[i][j] = Max(dp[i+1][j], dp[i][j+1]);
//                printf("%d,%d:%d\n", i, j, dp[i][j]);
            }
        printf("%d\n", dp[1][1]);
    }
    return 0;
}
