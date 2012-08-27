//2012-08-24 15:42:27	Accepted	4396	734MS	4152K	1697 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 5000+5, MAXM = 200000+5, MAXK = 50+5;
const int INF = 0x3f3f3f3f;
int N, M, A, B, C, S, T, K, mk;
int e, head[MAXN], next[MAXM], v[MAXM];
int d[MAXN][MAXK], w[MAXM];
bool inq[MAXN][MAXK];
queue<pair<int, int> > Q;
void addedge(int x, int y, int z)
{
    v[e] = y; w[e] = z;
    next[e] = head[x]; head[x] = e++;
}
void spfa(int s)
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= mk; j++)
            d[i][j] = INF;
    Q.push(make_pair(s, 0));
    while (!Q.empty())
    {
        int u = Q.front().first, k = Q.front().second;
        Q.pop();
        inq[u][k] = 0;
        for (int i = head[u]; i != -1; i = next[i])
        {
            int l = k+(k < mk ? 1 : 0);
            if (d[u][k]+w[i] < d[v[i]][l])
            {
                d[v[i]][l] = d[u][k]+w[i];
                if (!inq[v[i]][l])
                {
                    Q.push(make_pair(v[i], l));
                    inq[v[i]][l] = 1;
                }
            }
        }
    }
}
void init()
{
    e = 0;
    memset(head, -1, sizeof(head));
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    while (scanf("%d%d", &N, &M) != EOF)
    {
        init();
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &A, &B, &C);
            addedge(A, B, C);
            addedge(B, A, C);
        }
        scanf("%d%d%d", &S, &T, &K);
        mk = (K-1)/10+1;
        spfa(S);
        printf("%d\n", d[T][mk] < INF ? d[T][mk] : -1);
    }
    return 0;
}
