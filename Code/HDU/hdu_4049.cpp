#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10+5, MAXM = 10+5;
const int INF = 0x3f3f3f3f;
int N, M, P[MAXM], V[MAXN][MAXM], B[MAXN][MAXN];
int d[MAXM][1<<10];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &N, &M) && N && M)
    {
        for (int i = 1; i <= M; i++)
            scanf("%d", &P[i]);
        for (int i = 0; i < N; i++)
            for (int j = 1; j <= M; j++)
                scanf("%d", &V[i][j]);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &B[i][j]);
        int U = (1<<N)-1;
        for (int i = 1; i <= M; i++)
            for (int u = 0; u <= U; u++)
            {
                d[i][u] = -INF;
                int add = 0;
                for (int k = 0; k < N; k++) if ((1<<k)&u)
                {
                    add += V[k][i]-P[i];
                    for (int j = 0; j < k; j++) if ((1<<j)&u)
                        add += B[k][j];
                }
                for (int v = u; v <= U; v++) if ((u&v) == u)
                    d[i][u] = max(d[i][u], d[i-1][v]+add);
            }
        int ans = -INF;
        for (int u = 0; u <= U; u++)
            ans = max(ans, d[M][u]);
        if (ans)
            printf("%d\n", ans);
        else
            printf("STAY HOME\n");
    }
    return 0;
}
