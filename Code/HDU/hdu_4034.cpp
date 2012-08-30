//2012-08-30 09:50:26	Accepted	4034	187MS	260K	1096 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5;
const int INF = 0x3f3f3f3f;
int T, N, d[MAXN][MAXN];
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                scanf("%d", &d[i][j]);
        int ans = 0;
        for (int i = 1; i <= N && ans != -1; i++)
            for (int j = 1; j <= N && ans != -1; j++) if (j != i)
            {
                int t = INF;
                for (int k = 1; k <= N; k++) if (k != j && k != i)
                    t = min(t, d[i][k]+d[k][j]);
                if (t > d[i][j])
                    ans++;
                else if (t < d[i][j])
                    ans = -1;
            }
        if (ans != -1)
            printf("Case %d: %d\n", cas, ans);
        else
            printf("Case %d: impossible\n", cas);
    }
    return 0;
}
