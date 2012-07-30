#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 100+5;
int N, T, L, B;
bool l[MAX], b[MAX];
double d[MAX][MAX];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d%d%d", &N, &T, &L, &B))
    {
        if (!N && !T) break;
        memset(l, 0, sizeof(l));
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= L; i++)
        {
            int x;
            scanf("%d", &x);
            l[x] = 1;
        }
        for (int i = 1; i <= B; i++)
        {
            int x;
            scanf("%d", &x);
            b[x] = 1;
        }
        d[0][0] = 1;
        for (int i = 1; i <= T; i++)
        {
            d[i][0] = 0;
            for (int j = 1; j <= N; j++)
            {
                d[i][j] = 0;
                for (int k = 1; k <= 6; k++)
                {
                    int x = j-k;
                    if (x >= 0)
                    {
                        if (l[x] && i-2 >= 0)
                            d[i][j] += d[i-2][x];
                        else if (!b[x])
                            d[i][j] += d[i-1][x];
                    }
                    int y = 2*N-k-j;
                    if (0 <= y && y < N && x != y)
                    {
                        if (l[y] && i-2 >= 0)
                            d[i][j] += d[i-2][y];
                        else if (!b[y])
                            d[i][j] += d[i-1][y];
                    }
                }
                if (b[j])
                    d[i][0] += d[i][j];
                d[i][j] /= 6;
//                printf("%d,%d:%.6lf\n", i, j, d[i][j]);
            }
            d[i][0] /= 6;
//            printf("%d,%d:%.6lf\n", i, 0, d[i][0]);
        }
        double ans = 0;
        for (int i = 1; i <= T; i++)
            ans += d[i][N];
        printf("%.6lf\n", ans);
    }
    return 0;
}
