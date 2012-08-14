//2012-08-14 18:28:19	Accepted	4360	78MS	720K	3194 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1500*4+5, MAXM = 15000*2+5;
const long long INF = 1LL<<60;
int T, N, M, X, Y, W;
int e, head[MAXN], next[MAXM], v[MAXM];
int p[MAXN];
long long w[MAXM], d[MAXN];
bool inq[MAXN];
char id[5];
queue<int> Q;
void addedge(int x, int y, int z)
{
    v[e] = y; w[e] = z;
    next[e] = head[x]; head[x] = e++;
}
void init()
{
    e = 0;
    memset(head, -1, sizeof(head));
}
void spfa(int s, int n)
{
    for (int i = 4; i < 4+n; i++)
    {
        d[i] = (i == s) ? 0 : INF;
        p[i] = 0;
    }
    memset(inq, 0, sizeof(inq));
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        inq[u] = 0;
        for (int i = head[u]; i != -1; i = next[i])
            if ((d[v[i]] > d[u]+w[i]) || (d[v[i]] == d[u]+w[i] && p[v[i]] < p[u]+1))
            {
                d[v[i]] = d[u]+w[i];
                p[v[i]] = p[u]+1;
                if (!inq[v[i]])
                {
                    Q.push(v[i]);
                    inq[v[i]] = 1;
                }
            }
    }
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        init();
        scanf("%d%d", &N, &M);
        long long ans = INF;
        int P;
        if (N == 1)
        {
            long long c[4];
            fill(c, c+4, INF);
            for (int i = 1; i <= M; i++)
            {
                scanf("%d%d%d%s", &X, &Y, &W, id);
                if (id[0] == 'L')
                    c[0] = min(c[0], (long long)W);
                else if (id[0] == 'O')
                    c[1] = min(c[1], (long long)W);
                else if (id[0] == 'V')
                    c[2] = min(c[2], (long long)W);
                else
                    c[3] = min(c[3], (long long)W);
            }
            if (c[0] < INF && c[1] < INF && c[2] < INF && c[3] < INF)
                ans = c[0]+c[1]+c[2]+c[3], P = 1;
        }
        else
        {
            for (int i = 1; i <= M; i++)
            {
                scanf("%d%d%d%s", &X, &Y, &W, id);
                if (id[0] == 'L')
                    addedge((X<<2)+3, (Y<<2)+0, W), addedge((Y<<2)+3, (X<<2)+0, W);
                else if (id[0] == 'O')
                    addedge((X<<2)+0, (Y<<2)+1, W), addedge((Y<<2)+0, (X<<2)+1, W);
                else if (id[0] == 'V')
                    addedge((X<<2)+1, (Y<<2)+2, W), addedge((Y<<2)+1, (X<<2)+2, W);
                else
                    addedge((X<<2)+2, (Y<<2)+3, W), addedge((Y<<2)+2, (X<<2)+3, W);
            }
            int s = (1<<2)+3, t = (N<<2)+3;
            spfa(s, N<<2);
            ans = d[t]; P = p[t]>>2;
        }
        if (ans < INF)
            printf("Case %d: Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n", cas, ans, P);
        else
            printf("Case %d: Binbin you disappoint Sangsang again, damn it!\n", cas);
    }
    return 0;
}
