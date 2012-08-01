#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN = 1005;
int n, d, cas = 0;
bool vis[MAXN];
struct Pos { double L, R; } pos[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &n, &d))
    {
        if (n == 0 && d == 0)
            break;
        cas++;
        memset(vis, 0, sizeof(vis));
        double sta = 0;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (y-d > 0 || y+d < 0)
            {
                printf("Case %d: %d\n", cas, -1);
                break;
            }
            double dx = sqrt(pow((double)d, 2)-pow((double)y, 2));
            pos[i].L = (double)x-dx;
            pos[i].R = (double)x+dx;
            //printf("%lf %lf\n", pos[i].L, pos[i].R);
            sta = sta == 0 ? pos[i].R : (sta < pos[i].R ? sta : pos[i].R);
        }
        int cnt_n = 0, ans = 0;
        while (cnt_n < n)
        {
            for (int i = 0; i < n; i++)
                if (!vis[i] && pos[i].L <= sta+0.000001 && sta-0.000001 <= pos[i].R)
                {
                    cnt_n++; vis[i] = 1;
                    //printf("%d ", i);
                }
            sta = 0;
            for (int i = 0; i < n; i++)
                if (!vis[i])
                    sta = sta == 0 ? pos[i].R : (sta < pos[i].R ? sta : pos[i].R);
            ans++;
        }
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}
