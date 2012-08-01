#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 100+5, MAXK = 9+5;
int k, n; double f[MAXN][MAXK];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &k, &n) != EOF)
    {
        memset(f, 0, sizeof(f));
        for (int i = 0; i <= k; i++)
            f[1][i] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 0; j <= k; j++)
            {
                if (j-1 >= 0)
                    f[i][j] += f[i-1][j-1];
                f[i][j] += f[i-1][j];
                if (j+1 <= k)
                    f[i][j] += f[i-1][j+1];
            }
        double ans = 0;
        for (int i = 0; i <= k; i++)
            ans += f[n][i];
        ans *= 100;
        double tot = 1;
        for (int i = 1; i <= n; i++)
            tot *= (double)(k+1);
        printf("%.5lf\n", ans/tot);
    }
    return 0;
}
