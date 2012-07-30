#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX = 200 +5, INF = 0x3f3f3f3f;
int t, h, c, x[MAX];
double d[MAX][MAX], Err[MAX][MAX];
double err(int i, int j, int k)
{
    return fabs((x[k]-(x[i]+(x[j]-x[i])*(double)(k-i)/(j-i))));
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &h, &c);
        for (int i = 1; i <= h; i++)
            scanf("%d", &x[i]);
        memset(Err, 0, sizeof(Err));
        for (int i = 1; i <= h; i++)
            for (int j = 1; j < i; j++)
                for (int k = i+1; k <= h; k++)
                    Err[j][k] += err(j, k, i);
        for (int j = 2; j <= h; j++)
            d[2][j] = Err[1][j];
        for (int i = 3; i <= c; i++)
            for (int j = i; j <= h; j++)
            {
                d[i][j] = (double)INF;
                for (int k = i-1; k < j; k++)
                    d[i][j] = min(d[i][j], d[i-1][k]+Err[k][j]);
//                printf("%d,%d:%.3lf\n", i, j, d[i][j]);
            }
        printf("%.4lf\n", d[c][h]/h);
    }
    return 0;
}
