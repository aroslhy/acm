#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5, INF = 0x3f3f3f3f;
int N, M, d[MAXN][MAXN], c[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (i != j) d[i][j] = INF;
    while (M--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        d[u][v] = 0;
    }
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        bool flag = 1;
        for (int j = 1; j <= N; j++)
        {
            if (d[j][i] != 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
