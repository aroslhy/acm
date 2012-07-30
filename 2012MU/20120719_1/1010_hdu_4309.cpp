#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 120+5, MAXM = 1140*2+5, MAXP = 1000+5;
const int INF = 0x7fffffff;
int N, M, P[MAXN], x[MAXP], y[MAXP], w[MAXP], p[MAXP], CNTbridge, sum, cost;
int n, s, t;
int e, v[MAXM], next[MAXM], head[MAXN];
int cap[MAXM];
int h[MAXN], gap[MAXN];
bool fix[12+5];
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
void dfs(int cur)
{
    if (cur > CNTbridge)
    {
        init();
        int cnt = N, cntbridge = 0, tc = 0;
        s = ++cnt; t = ++cnt;
        for (int i = 1; i <= N; i++)
            addedge(s, i, P[i]);
        for (int i = 1; i <= M; i++)
        {
            if (p[i] < 0)
            {
                addedge(++cnt, t, w[i]);
                addedge(x[i], cnt, INF);
                addedge(cnt, y[i], INF);
            }
            else if (p[i] > 0)
            {
                if (fix[++cntbridge])
                {
                    addedge(x[i], y[i], INF);
                    tc += w[i];
                }
                else
                    addedge(x[i], y[i], 1);
            }
            else
                addedge(x[i], y[i], INF);
        }
        n = cnt;
        int tf = maxflow();
        if (tf > sum)
        {
            sum = tf;
            cost = tc;
        }
        else if (tf == sum)
            cost = min(cost, tc);
        return;
    }
    fix[cur] = 0;
    dfs(cur+1);
    fix[cur] = 1;
    dfs(cur+1);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &N, &M) != EOF)
    {
        CNTbridge = 0;
        for (int i = 1; i <= N; i++)
            scanf("%d", &P[i]);
        for (int i = 1; i <= M; i++)
        {
            scanf("%d%d%d%d", &x[i], &y[i], &w[i], &p[i]);
            if (p[i] > 0)
                CNTbridge++;
        }
        sum = 0; cost = INF;
        dfs(1);
        if (sum)
            printf("%d %d\n", sum, cost);
        else
            printf("Poor Heaven Empire\n");
    }
    return 0;
}
