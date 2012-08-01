#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5, MAXM = 10+5;
const int INF = 0x3f3f3f3f;
const long long MOD = 1000000007;
int n, r, k, m;
long long f[MAXN][MAXN], s[MAXN][MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d%d%d", &n, &r, &k, &m) != EOF)
    {
        for (int i = 0; i <= n; i++)
            f[i][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= r && j <= i; j++)
            {
                f[i][j] = f[i-1][j];
                if (i >= k)
                    f[i][j] = (f[i][j]+f[i-k][j-1])%MOD;
                else if (j == 1)
                    f[i][j] = (f[i][j]+1)%MOD;
//                printf("%d,%d:%lld\n", i, j, f[i][j]);
            }
        s[0][0] = 1;
        m = min(m, n);
        int sum = 0;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= m; j++)
            {
                s[i][j] = (s[i-1][j-1]+(s[i-1][j]*j)%MOD)%MOD;
                if (i == r)
                    sum = (sum+s[i][j])%MOD;
            }
        long long ans = (f[n][r]*sum)%MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
