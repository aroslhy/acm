#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000+5;
int T, n, a[MAXN], f[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            f[i] = 1;
            if (a[i] == a[i-1])
                f[i] = max(f[i], f[i-1]+1);
            if (a[i] == a[i-2])
                f[i] = max(f[i], f[i-2]+1);
            ans = max(ans, f[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
