#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 100+5;
int T, n, m, r[MAXN*MAXN], p[MAXN], u[MAXN*MAXN], v[MAXN*MAXN];
double x[MAXN], y[MAXN], d[MAXN*MAXN];
int cmp(const int a, const int b)
{
    return d[a] < d[b];
}
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
double Kruskal()
{
    double ans = 0;
    for (int i = 1; i <= m; i++)
        r[i] = i;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    sort(r+1, r+1+m, cmp);
    for (int i = 1; i <= m; i++)
    {
        int e = r[i], x = find(u[e]), y = find(v[e]);
        if (x != y)
        {
            ans += d[e];
            p[x] = y;
        }
    }
    return ans;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &x[i], &y[i]);
        m = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i+1; j <= n; j++)
            {
                d[++m] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                u[m] = i; v[m] = j;
            }
        printf("%.2lf\n", Kruskal());
        if (T) printf("\n");
    }
    return 0;
}
