#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
const int MAXN = 100+5;
const int INF = 0x7fffffff;
int M, K, x, d[MAXN][6][32];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &M, &K) && M && K)
    {
        memset(d, 0, sizeof(d));
        int maxl = 0;
        for (int i = 1; i <= M; i++)
        {
            scanf("%d", &x);
            for (int j = 1; j <= K; j++)
                for (int k = 1; k < (1<<K); k++) if ((1<<(j-1))&k)
                {
                    int &dp = d[i][j][k];
                    if (j == x)
                    {
                        dp = max(dp, d[i-1][j][k]+1);
                        for (int l = 1; l <= K; l++) if ((1<<(l-1))&(k^(1<<(j-1))))
                            dp = max(dp, d[i-1][l][k^(1<<(j-1))]+1);
                    }
                    else
                        dp = max(dp, d[i-1][j][k]);
//                    if (dp)
//                        printf("%d,%d,%d:%d\n", i, j, k, dp);
                    maxl = max(maxl, d[M][j][k]);
                }
        }
        printf("%d\n", M-maxl);
    }
    return 0;
}
