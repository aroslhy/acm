//2012-08-11 20:57:10	Accepted	4359	1171MS	3324K	1504 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAX = 360;
const int MAXN = MAX+5;
const long long MOD = 1000000007;
int T, N, D;
long long f[MAXN][MAXN], g[MAXN][MAXN]; //g[i][j] = f[i][1]+...+f[i][j]
long long C[MAXN][MAXN];
void initC(int n)
{
    for (int i = 0; i <= n; i++)
        C[i][0] = C[i][i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i/2; j++)
        {
            C[i][j] = C[i][i-j] = (C[i-1][j-1]+C[i-1][j])%MOD;
//            if (C[i][j] < 0)
//                printf("C(%d,%d)=%lld\n", i, j, C[i][j]);
        }
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    initC(MAX);
    for (int n = 1; n <= MAX; n++)
        for (int d = 1; d <= MAX; d++)
        {
            if (d == 1)
                f[n][d] = (n == 1) ? 1 : 0;
            else if (d <= n)
            {
                for (int i = 1; i < n-1; i++)
                    f[n][d] += C[n-2][i]*(f[i][d-1]*g[n-i-1][d-1]%MOD+g[i][d-2]*f[n-i-1][d-1]%MOD)%MOD;
                f[n][d] += 2*f[n-1][d-1];
                f[n][d] = f[n][d]*n%MOD;
            }
            g[n][d] = (g[n][d-1]+f[n][d])%MOD;
//            if (f[n][d] < 0)
//                printf("%d,%d:%lld\n", n, d, f[n][d]);
        }
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d", &N, &D);
        printf("Case #%d: %I64d\n", cas, f[N][D]);
    }
    return 0;
}
