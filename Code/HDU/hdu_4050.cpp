#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2000+5, MAXM = 10+5;
const int INF = 0x3f3f3f3f;
int T, n, A, B;
double p[MAXN][4], d[MAXN][4];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        memset(d, 0, sizeof(d));
        scanf("%d%d%d", &n, &A, &B);
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 4; j++)
                scanf("%lf", &p[i][j]);
        for (int i = n+1; i <= n+A; i++)
            p[i][3] = 1.0;
        p[0][3] = 1.0;
        d[0][3] = 1.0;
        double ans = 0.0;
        for (int i = 1; i <= n+A; i++)
        {
            double P[4][3] = {{1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,1.0,1.0}};
            for (int j = A; j <= B; j++) if (i-j >= 0)
            {
                d[i][1] += p[i][1]*P[1][0]*d[i-j][2];
                P[1][0] *= p[i-(j-A)-1][0]+p[i-(j-A)-1][2];

                d[i][1] += p[i][1]*P[1][1]*d[i-j][3];
                P[1][1] *= p[i-(j-A)-1][0];

                d[i][2] += p[i][2]*P[2][0]*d[i-j][1];
                P[2][0] *= p[i-(j-A)-1][0]+p[i-(j-A)-1][1];

                d[i][2] += p[i][2]*P[2][1]*d[i-j][3];
                P[2][1] *= p[i-(j-A)-1][0];

                d[i][3] += p[i][3]*P[3][0]*d[i-j][1];
                P[3][0] *= p[i-(j-A)-1][0]+p[i-(j-A)-1][1];

                d[i][3] += p[i][3]*P[3][1]*d[i-j][2];
                P[3][1] *= p[i-(j-A)-1][0]+p[i-(j-A)-1][2];

                d[i][3] += p[i][3]*P[3][2]*d[i-j][3];
                P[3][2] *= p[i-(j-A)-1][0];
            }
            ans += d[i][1]+d[i][2]+d[i][3];
        }
        printf("%.8lf\n", ans);
    }
    return 0;
}
