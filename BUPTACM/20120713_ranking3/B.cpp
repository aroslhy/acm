#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 1000000+5;
const int INF = 0x3f3f3f3f;
int n, a[MAXN];
bool vis[MAXM];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int Max = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        vis[a[i]] = 1;
        Max = max(Max, a[i]);
    }
    int ans = 0;
    for (int i = Max; i >= 1 && !ans; i--)
    {
        int cnt = 0;
        for (int j = i; j <= Max && !ans; j += i)
        {
            if (vis[j])
                cnt++;
            if (cnt == 2)
                ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
