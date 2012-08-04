#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 100+5, MAXM = 155000*2+5;
const int INF = 0x3f3f3f3f;
int n, m, mat[MAXN][MAXN], d[MAXN][MAXN][MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        int K = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &mat[i][j]);
                K = max(K, abs(mat[i][j]));
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                int x = abs(mat[i][j]);
                for (int k = K; k >= 0; k--)
                {
                    int &dp = d[i][j][k];
                    if (i == 1 && j == 1)
                        dp = (x >= k) ? mat[i][j] : -INF;
                    else
                    {
                        dp = -INF;
                        if (i > 1)
                            dp = max(dp, d[i-1][j][k]);
                        if (j > 1)
                            dp = max(dp, d[i][j-1][k]);
                        if (x >= k)
                        {
                            int tdp = -INF;
                            if (i > 1)
                                tdp = max(tdp, d[i-1][j][x+1]);
                            if (j > 1)
                                tdp = max(tdp, d[i][j-1][x+1]);
                            if (tdp > -INF)
                                dp = max(dp, mat[i][j]-tdp);
                            else
                                dp = max(dp, mat[i][j]);
                        }
                    }
//                    printf("%d,%d,%d:%d\n", i, j, k, dp);
                }
            }
        printf("%d\n", d[n][m][0]);
    }
    return 0;
}
