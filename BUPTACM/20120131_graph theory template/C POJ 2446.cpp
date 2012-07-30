#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 32*32+5, MAXM = 6*MAXN;
const int INF = 0x3f3f3f3f;
int e, s, t, n;
int v[MAXM], next[MAXM], head[MAXN];
int cap[MAXM], a[MAXN], f;
int pv[MAXN], pe[MAXN];
queue<int> Q;
void addedge(int u_, int v_, int c_)
{
    v[e] = v_; cap[e] = c_;
    next[e] = head[u_]; head[u_] = e;
    e++;
    v[e] = u_; cap[e] = 0;
    next[e] = head[v_]; head[v_] = e;
    e++;
}
void maxflow()
{
    f = 0;
    for (;;)
    {
        memset(a, 0, sizeof(a));
        a[s] = INF;
        Q.push(s);
        while (!Q.empty())
        {
            int u = Q.front(); Q.pop();
            for (int e = head[u]; e != -1; e = next[e])
                if(!a[v[e]] && cap[e])
                {
                    Q.push(v[e]);
                    a[v[e]] = min(a[u], cap[e]);
                    pv[v[e]] = u; pe[v[e]] = e;
                }
        }
        if (!a[t]) break;
        for (int v = t; v != s; v = pv[v])
        {
            cap[pe[v]] -= a[t];
            cap[pe[v]^1] += a[t];
        }
        f += a[t];
    }
}
int M, N, K;
bool hole[MAXN][MAXN];
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int nodenum(int i, int j)
{
    return (i-1)*N+j;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &M, &N, &K);
    if ((M*N-K)%2)
    {
        printf("NO\n");
        return 0;
    }
    memset(hole, 0, sizeof(hole));
    for (int i = 1; i <= K; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        hole[y][x] = 1;
    }
    memset(cap, 0, sizeof(cap));
    memset(head, -1, sizeof(head));
    e = 0; s = M*N+1; t = M*N+2; n = M*N+2;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
        {
            if (hole[i][j]) continue;
            if ((i+j)%2)
            {
                int p = nodenum(i, j);
                addedge(s, p, 1);
                for (int k = 0; k < 4; k++)
                {
                    int x = i+dir[k][0], y = j+dir[k][1];
                    if (1 <= x && x <= M && 1 <= y && y <= N)
                    {
                        int q = nodenum(x, y);
                        addedge(p, q, 1);
                    }
                }
            }
            else
            {
                int p = nodenum(i, j);
                addedge(p, t, 1);
            }
        }
    maxflow();
    printf(f == (M*N-K)/2 ? "YES\n" : "NO\n");
    return 0;
}
