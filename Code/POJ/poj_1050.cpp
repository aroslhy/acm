#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5;
const int INF = 0x3f3f3f3f;
int N, a[MAXN][MAXN], s[MAXN][MAXN][MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &a[i][j]);
            for (int p = 1; p <= i; p++)
                for (int q = i; q <= N; q++)
                    s[p][q][j] += a[i][j];
        }
    int ans = -INF;
    for (int p = 1; p <= N; p++)
        for (int q = p; q <= N; q++)
        {
            int sum = 0, smin = 0, smax = -INF;
            for (int i = 1; i <= N; i++)
            {
                sum += s[p][q][i];
                smax = max(smax, sum-smin);
                smin = min(smin, sum);
            }
            ans = max(ans, smax);
        }
    printf("%d\n", ans);
    return 0;
}
