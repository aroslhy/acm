#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5;
const int INF = 0x3f3f3f3f;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n, r[MAXN];
bool vis[MAXN];
struct Node
{
    int a, b;
} c[MAXN];
bool cmp(const int x, const int y)
{
    return c[x].a < c[y].a;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &c[i].a, &c[i].b);
            r[i] = i;
        }
        memset(vis, 0, sizeof(vis));
        sort(r, r+n, cmp);
        int ans = c[0].a;
        for (int i = 0; i < n; i++)
        {
            int m = i, t_b = 0;
            int j;
            for (j = 0; j <= i; j++)
                if (!vis[r[j]] && c[r[j]].b > t_b)
                {
                    m = j, t_b = c[r[j]].b;
                }
            ans += t_b;
            vis[j] = 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
