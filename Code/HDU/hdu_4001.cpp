//2012-08-13 20:10:56	Accepted	4001	93MS	2840K	1942 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5, MAXM = 500000+5, MAXP = 10+5;
int N, a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int e, head[MAXN], next[MAXM], v[MAXM];
long long f[MAXN];
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e++;
}
void init()
{
    e = 0;
    memset(head, -1, sizeof(head));
    memset(f, 0, sizeof(f));
}
long long F(int u)
{
    if (f[u])
        return f[u];
    for (int i = head[u]; i != -1; i = next[i])
        f[u] = max(f[u], F(v[i]));
    return f[u] = f[u]+c[u];
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    while (scanf("%d", &N) && N)
    {
        init();
        for (int i = 1; i <= N; i++)
        {
            scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
            if (a[i] > b[i])
                swap(a[i], b[i]);
        }
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) if (i != j)
            {
                if (d[i] == 0)
                {
                    if (a[i] >= a[j] && b[i] >= b[j])
                    {
                        if (a[i] == a[j] && b[i] == b[j] && d[i] == d[j] && i < j)
                            continue;
                        addedge(i, j);
                    }
                }
                else if (d[i] == 1)
                {
                    if (a[i] >= a[j] && b[i] >= b[j] && (long long)a[i]*b[i] > (long long)a[j]*b[j])
                        addedge(i, j);
                }
                else
                {
                    if (a[i] > a[j] && b[i] > b[j])
                        addedge(i, j);
                }
            }
        long long ans = 0;
        for (int u = 1; u <= N; u++)
            ans = max(ans, F(u));
        printf("%I64d\n", ans);
    }
    return 0;
}
