//2012-09-12 10:02:47	Accepted	4284	2531MS	4364K	1945 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5, MAXM = 10000+5;
const int MAX = 16;
const int INF = 0x3f3f3f3f;
int T, N, M, Money, H, U, V, W;
int chs[MAX], C[MAX], D[MAX];
int d[MAXN][MAXN], f[1<<MAX][MAX];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        memset(f, -1, sizeof(f));
        scanf("%d%d%d", &N, &M, &Money);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= i; j++)
                d[i][j] = d[j][i] = (i != j) ? INF : 0;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &U, &V, &W);
            if (W < d[U][V])
                d[U][V] = d[V][U] = W;
        }
        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                {
                    if (d[i][k] < INF && d[k][j] < INF && d[i][j] > d[i][k]+d[k][j])
                        d[i][j] = d[i][k]+d[k][j];
                }
        scanf("%d", &H);
        for (int i = 0; i < H; i++)
        {
            scanf("%d%d%d", &chs[i], &C[i], &D[i]);
            if (Money >= d[1][chs[i]]+D[i])
                f[1<<i][i] = max(f[1<<i][i], Money-d[1][chs[i]]-D[i]+C[i]);
        }
        int tot = (1<<H)-1;
        for (int u = 0; u < tot; u++)
            for (int i = 0; i < H; i++) if (u&(1<<i))
                for (int j = 0; j < H; j++) if (!(u&(1<<j)))
                {
                    int v = u|(1<<j);
                    if (f[u][i] >= d[chs[i]][chs[j]]+D[j])
                        f[v][j] = max(f[v][j], f[u][i]-d[chs[i]][chs[j]]-D[j]+C[j]);
                }
        bool flag = 0;
        for (int i = 0; i < H && !flag; i++)
            if (f[tot][i] >= d[chs[i]][1])
                flag = 1;
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
