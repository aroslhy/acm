#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, INF = 1<<30;
int T, n, a[MAXN], sum, smin, d1[MAXN], d2[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &n) && n)
    {
        memset(d1, 0, sizeof(d1));
        memset(d2, 0, sizeof(d2));
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sum = 0; smin = INF;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1 && a[1] < 0)
            {
                smin = sum = d1[1] = a[1];
                continue;
            }
            smin = min(smin, sum);
            sum += a[i];
            d1[i] = max(d1[i-1], sum-smin);
        }
        sum = 0; smin = INF;
        for (int i = n; i >= 1; i--)
        {
            if (i == n && a[n] < 0)
            {
                smin = sum = d2[n] = a[n];
                continue;
            }
            smin = min(smin, sum);
            sum += a[i];
            d2[i] = max(d2[i+1], sum-smin);
        }
        int ans = -INF;
        for (int i = 1; i < n; i++)
            ans = max(ans, d1[i]+d2[i+1]);
        printf("%d\n", ans);
    }
    return 0;
}
