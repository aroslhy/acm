//2012-08-21 21:40:44	Accepted	4385	406MS	4344K	1920 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX = 20, MAXN = MAX+5;
const int INF = 0x3f3f3f3f;
int T, N, x[MAXN], y[MAXN], dist[MAXN][MAXN];
int d[1<<MAX], p[1<<MAX], cnt;
void print_path(int u)
{
    if (p[u])
        print_path(p[u]);
    for (int i = 1; i <= N; i++)
        if (u&(1<<(i-1)) && !(p[u]&(1<<(i-1))))
        {
            if (cnt++)
                printf(" ");
            printf("%d", i);
        }
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d%d", &x[0], &y[0], &N);
        for (int i = 1; i <= N; i++)
        {
            scanf("%d%d", &x[i], &y[i]);
            for (int j = 0; j < i; j++)
                dist[i][j] = dist[j][i] = abs(x[i]-x[j])*abs(x[i]-x[j])+abs(y[i]-y[j])*abs(y[i]-y[j]);
        }
        int S = (1<<N)-1;
        for (int u = 1; u <= S; u++)
        {
            d[u] = INF;
            for (int i = N; i >= 1; i--) if (u&(1<<(i-1)))
            {
                int v = u^(1<<(i-1));
                if (d[v]+dist[0][i]*2 < d[u])
                {
                    d[u] = d[v]+dist[0][i]*2;
                    p[u] = v;
                }
                for (int j = N; j > i; j--) if (u&(1<<(j-1)))
                {
                    int w = v^(1<<(j-1));
                    if (d[w]+dist[0][i]+dist[i][j]+dist[j][0] < d[u])
                    {
                        d[u] = d[w]+dist[0][i]+dist[i][j]+dist[j][0];
                        p[u] = w;
                    }
                }
            }
//            printf("%d:%d\n", u, d[u]);
        }
        printf("Case %d:\n%d\n", cas, d[S]);
        cnt = 0;
        print_path(S);
        printf("\n");
    }
    return 0;
}
