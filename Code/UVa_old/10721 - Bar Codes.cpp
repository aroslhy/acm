#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 50+5;
int n, k, m;
long long f[MAX][MAX];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d%d", &n, &k, &m) != EOF)
    {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; i++)
            f[1][i] = 1;
        for (int i = 2; i <= k; i++)
            for (int j = 1; j <= n; j++)
            {
                for (int p = 1; p <= m && p <= j; p++)
                    f[i][j] += f[i-1][j-p];
//                printf("%d,%d:%lld\n", i, j, f[i][j]);
            }
        printf("%lld\n", f[k][n]);
    }
    return 0;
}
