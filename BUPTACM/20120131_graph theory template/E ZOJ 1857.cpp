#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 500+5, MAXM = 10000+5, INF = 0x3f3f3f3f;
int F, N;
char line[100];
int n, m, s, e;
int head[MAXN], d[MAXN];
int v[MAXM], w[MAXM], next[MAXM];
bool inq[MAXN];
queue<int> Q;
void addedge(int x, int y, int z)
{
    v[e] = y; w[e] = z;
    next[e] = head[x]; head[x] = e++;
    v[e] = x; w[e] = z;
    next[e] = head[y]; head[y] = e++;
}
void deledge(int x, int y)
{
    head[x] = next[head[x]]; e--;
    head[y] = next[head[y]]; e--;
}
void SPFA()
{
    for (int i = 1; i <= n; i++)
        d[i] = (i == s ? 0 : INF);
    memset(inq, 0, sizeof(inq));
    while (!Q.empty()) Q.pop();
    Q.push(s);
    inq[s] = 1;
    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        inq[u] = 0;
        for(int e = head[u]; e != -1; e = next[e])
            if(d[v[e]] > d[u]+w[e])
            {
                d[v[e]] = d[u]+w[e];
                if(!inq[v[e]])
                {
                    Q.push(v[e]);
                    inq[v[e]] = 1;
                }
            }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &F, &N) != EOF)
    {
        s = N+1; n = N+1;
        memset(head, -1, sizeof(head));
        e = 0;
        for (int i = 1; i <= F; i++)
        {
            int x;
            scanf("%d", &x);
            addedge(s, x, 0);
        }
        getchar();
        while (fgets(line, 100, stdin))
        {
            int x, y, z;
            if (sscanf(line, "%d%d%d", &x, &y, &z) == 3)
                addedge(x, y, z);
            else
                break;
        }
        int ans, a = INF;
        for (int i = 1; i <= N; i++)
        {
            addedge(s, i, 0);
            SPFA();
            int b = 0;
            for (int j = 1; j <= N; j++)
                b = max(b, d[j]);
            if (b < a)
                a = b, ans = i;
            deledge(s, i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
