#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n, m, K;
double d[9+5][(9+9)*9+5];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d%d", &n, &m, &K) != EOF)
    {
        memset(d, 0, sizeof(d));
        d[0][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = i; j <= i*n; j++)
            {
                for (int k = 1; k <= n; k++)
                    d[i][j] += d[i-1][j-k];
                d[i][j] /= n;
//                printf("%d,%d:%.4lf\n", i, j, d[i][j]);
            }
        }
        printf("%.2lf\n", d[m][K]);
    }
    return 0;
}
