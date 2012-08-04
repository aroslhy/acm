#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 55000+5, MAXM = 155000*2+5;
const int INF = 0x3f3f3f3f;
int N, M;
int n, s, t;
int e, v[MAXM], next[MAXM], head[MAXN];
int cap[MAXM];
int h[MAXN], gap[MAXN];
void init()
{
    e = 0;
    memset(head, -1, sizeof(head));
    memset(gap, 0, sizeof(gap));
    memset(h, 0, sizeof(h));
}
void addedge(int x, int y, int c)
{
    v[e] = y; cap[e] = c;
    next[e] = head[x]; head[x] = e++;
    v[e] = x; cap[e] = 0;
    next[e] = head[y]; head[y] = e++;
}
int sap(int u, int f)
{
    if (u == t)
       return f;
    int minh = n-1, rf = f;
    for (int i = head[u]; i != -1; i = next[i]) if (cap[i])
    {
        if (h[v[i]]+1 == h[u])
        {
            int cf = sap(v[i], min(cap[i], rf));
            cap[i] -= cf;
            cap[i^1] += cf;
            rf -= cf;
            if (h[s] >= n)
                return f-rf;
            if (!rf)
                break;
        }
        minh = min(minh, h[v[i]]);
    }
    if (rf == f)
    {
        gap[h[u]]--;
        if (!gap[h[u]])
            h[s] = n;
        h[u] = minh+1;
        gap[h[u]]++;
    }
    return f-rf;
}
int maxflow()
{
    int res = 0;
    gap[0] = n;
    while (h[s] < n)
       res += sap(s, INF);
    return res;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &N, &M) != EOF)
    {
        init();
        n = N+M+2; s = N+M+1; t = s+1;
        for (int i = 1; i <= N; i++)
        {
            int P;
            scanf("%d", &P);
            addedge(i, t, P);
        }
        int tp = 0;
        for (int i = 1; i <= M; i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            tp += z;
            addedge(s, N+i, z);
            addedge(N+i, x, INF);
            addedge(N+i, y, INF);
        }
        int f = maxflow();
        printf("%d\n", tp-f);
    }
    return 0;
}
