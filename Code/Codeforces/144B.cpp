#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1000+5, INF = 0x3f3f3f3f;
int n, xa, ya, xb, yb;
double x[MAXN], y[MAXN], r[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
    if (xa > xb) swap(xa, xb);
    if (ya > yb) swap(ya, yb);
    int ans = 0;
    for (int x_ = xa; x_ < xb; x_++)
    {
        bool flag = 1;
        for (int i = 1; i <= n; i++)
            if (sqrt((x_-x[i])*(x_-x[i])+(ya-y[i])*(ya-y[i])) <= r[i])
            {
                flag = 0;
                break;
            }
        if (flag) ans++;
    }
    for (int x_ = xb; x_ > xa; x_--)
    {
        bool flag = 1;
        for (int i = 1; i <= n; i++)
            if (sqrt((x_-x[i])*(x_-x[i])+(yb-y[i])*(yb-y[i])) <= r[i])
            {
                flag = 0;
                break;
            }
        if (flag) ans++;
    }
    for (int y_ = ya; y_ < yb; y_++)
    {
        bool flag = 1;
        for (int i = 1; i <= n; i++)
            if (sqrt((xb-x[i])*(xb-x[i])+(y_-y[i])*(y_-y[i])) <= r[i])
            {
                flag = 0;
                break;
            }
        if (flag) ans++;
    }
    for (int y_ = yb; y_ > ya; y_--)
    {
        bool flag = 1;
        for (int i = 1; i <= n; i++)
            if (sqrt((xa-x[i])*(xa-x[i])+(y_-y[i])*(y_-y[i])) <= r[i])
            {
                flag = 0;
                break;
            }
        if (flag) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
