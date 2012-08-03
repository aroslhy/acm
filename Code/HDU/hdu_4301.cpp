#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5, MAXM = 1000*2+5;
const int INF = 0x3f3f3f3f;
const int MOD = 100000007;
int T, N, K, d[MAXN][MAXM][2];
int D(int i, int j, int k)
{
    int &dp = d[i][j][k];
    if (dp+1)
        return dp;
    if (j > 2*i || j == 0)
        return dp = 0;
    if (j == 1)
        return dp = k ? 0 : 1;
    if (k)
        dp = (2*D(i-1, j-1, 0)+D(i-1, j-2, 0)+D(i-1, j, 1)+2*D(i-1, j-1, 1)+D(i-1, j-2, 1))%MOD;
    else
        dp = (D(i-1, j, 0)+D(i-1, j-1, 0)+2*D(i-1, j, 1)+D(i-1, j-1, 1))%MOD;
//    printf("%d,%d,%d:%d\n", i, j, k, dp);
    return dp;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    memset(d, -1, sizeof(d));
    while (T--)
    {
        scanf("%d%d", &N, &K);
        d[0][0][0] = 1;
        d[0][0][1] = 0;
        int ans = (D(N, K, 0)+D(N, K, 1))%MOD;
        printf("%d\n", ans);
    }
    return 0;
}
