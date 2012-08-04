#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5, MAXM = 20+5;
const int INF = 0x3f3f3f3f;
int m, n, rec[MAXN];
bool vis[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    for (int cas = 1; scanf("%d%d", &m, &n) && m && n; cas++)
    {
        memset(vis, 0, sizeof(vis));
        int tot = m*n;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &rec[i]);
            vis[rec[i]] = 1;
        }
        sort(rec, rec+n);
        int ans = 0;
        for (int i = n-1; i >= 0; i--)
        {
            bool flag = 1;
            for (int j = rec[i]+1; j <= tot && flag; j++) if (!vis[j])
            {
                vis[j] = 1;
                flag = 0;
            }
            for (int j = 1; j < rec[i] && flag; j++) if (!vis[j])
            {
                vis[j] = 1;
                flag = 0;
                ans++;
            }
        }
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}
