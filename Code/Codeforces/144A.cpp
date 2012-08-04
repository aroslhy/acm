#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100+5, INF = 0x3f3f3f3f;
int n, a[MAXN];
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int max_ = -INF, pos_max;
    for (int i = 1; i <= n; i++)
        if (a[i] > max_)
            max_ = a[i], pos_max = i;
    int min_ = INF, pos_min;
    for (int i = n; i >= 1; i--)
        if (a[i] < min_)
            min_ = a[i], pos_min = i;
    int ans = n-pos_min+pos_max-1;
    if (pos_min < pos_max) ans--;
    printf("%d\n", ans);
    return 0;
}
