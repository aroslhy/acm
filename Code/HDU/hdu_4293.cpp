//2012-09-16 18:56:27	Accepted	4293	156MS	2260K	1900 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 500+5, MAXM = 300000+5;
const int INF = 0x3f3f3f3f;
int N, a, b, A[MAXN], B[MAXN];
int n, s, t, mp[MAXN][MAXN];
int val[MAXN], d[MAXN];
int e, head[MAXN], next[MAXM], v[MAXM];
bool inq[MAXN];
queue<int> Q;
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e++;
}
void spfa()
{
    for (int i = 1; i <= n; i++)
        d[i] = 0;
    memset(inq, 0, sizeof(inq));
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        inq[u] = 0;
        for (int i = head[u]; i != -1; i = next[i])
            if (d[v[i]] < d[u]+val[v[i]])
            {
                d[v[i]] = d[u]+val[v[i]];
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
    while (scanf("%d", &N) != EOF)
    {
        e = 0; n = 0;
        memset(head, -1, sizeof(head));
        memset(mp, 0, sizeof(mp));
        memset(val, 0, sizeof(val));
        for (int i = 1; i <= N; i++)
        {
            scanf("%d%d", &a, &b);
            if (a+b >= N)
                continue;
            int x = a+1, y = N-b, &m = mp[x][y];
            if (!m)
            {
                m = ++n;
                A[m] = x;
                B[m] = y;
            }
            val[m] = min(B[m]-A[m]+1, val[m]+1);
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (B[i] < A[j])
                    addedge(i, j);
        s = n+1, t = n+2; val[s] = val[t] = 0;
        for (int i = 1; i <= n; i++)
            addedge(s, i), addedge(i, t);
        n += 2;
        spfa();
        printf("%d\n", d[t]);
    }
    return 0;
}
