/*HDU 1003*/
#include<cstdio>
using namespace std;
const int MAXN = 100000+5, INF = 0x3f3f3f3f;
int T, n, a, sum, min_, max_, s_, s, t, cas;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        sum = 0; min_ = 0; max_ = -INF, s_ = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a);
            sum += a;
            if (sum-min_ > max_)
            {
                max_ = sum-min_;
                s = s_; t = i;
            }
            if (sum < min_)
            {
                min_ = sum;
                s_ = i+1;
            }
        }
        printf("Case %d:\n", ++cas);
        printf("%d %d %d\n", max_, s, t);
        if (T) printf("\n");
    }
    return 0;
}
