#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5, MAXM = 20+5;
const int INF = 0x3f3f3f3f;
int N, R;
struct Node
{
    int x, y;
} lx[MAXN], ly[MAXN];
bool cmpx(const Node a, const Node b)
{
    return a.x < b.x;
}
bool cmpy(const Node a, const Node b)
{
    return a.y < b.y;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &N, &R) != EOF)
    {
        for (int i = 0; i < N; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            lx[i].x = x; lx[i].y = y;
            ly[i].x = x; ly[i].y = y;
        }
        sort(lx, lx+N, cmpx);
        sort(ly, ly+N, cmpy);
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            int Y = ly[i].y;
            int s = 0;
            int cnt = 0;
            for (int t = 0; t < N; t++)
            {
                if (0 <= lx[t].y-Y && lx[t].y-Y <= R)
                    cnt++;
                while (lx[t].x-lx[s].x > R)
                {
                    if (0 <= lx[s].y-Y && lx[s].y-Y <= R)
                        cnt--;
                    s++;
                }
                ans = max(ans, cnt);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
