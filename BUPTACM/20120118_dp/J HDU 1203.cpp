#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, INF = 0x3f3f3f3f;
int T, n, a[MAXN], sum, smin, d[MAXN], s_, s, t, cas = 0, max_;
int main()
{

//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        memset(d, 0, sizeof(d));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sum = 0; max_ = -INF, s_ = 1;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i];
            if (sum > max_)
                max_ = sum, s = s_, t = i;
            if (sum < 0)
                sum = 0, s_ = i+1;
        }
        printf("Case %d:\n", ++cas);
        printf("%d %d %d\n", max_, s, t);
        if (T) printf("\n");
    }
    return 0;
}
