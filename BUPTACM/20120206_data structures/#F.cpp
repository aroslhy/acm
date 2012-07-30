#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int MAXN = 20000+5, MAXM = 2*60000+5;
const int INF = 0x3f3f3f3f;
int N, M, Q, value[MAXN];
int n, m, e, s;
int v[MAXM], next[MAXM], head[MAXN];
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e;
    e++;
}
void deledge(int x, int y)
{
    for (int e = head[x]; next[e] != -1; e = next[e])
        if (v[next[e]] == y)
        {
            next[e] = next[next[e]];
            break;
        }
}
int F(int X, int K)
{
    int res = INF;
    if (value[X] >= K)
        res = min(res, value[X]);
    for (int e = head[X]; next[e] != -1; e = next[e])
        if (value[v[e]] >= K)
            res = min(res, value[X]);
    if (res < INF)
        return res;
    else
        return 0;
}
void U(int X, int K)
{
    value[X] = K;
}
void E(int A, int B)
{
    deledge(A, B);
    deledge(B, A);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d%d", &N, &M, &Q) != EOF)
    {
        memset(head, -1, sizeof(head));
        e = 0;
        for (int i = 1; i <= N; i++)
            scanf("%d", &value[i]);
        for (int i = 1; i <= M; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addedge(x, y);
            addedge(y, x);
        }
        double sum = 0;
        int cnt = 0;
        for (int i = 1; i <= Q; i++)
        {
            char type[5];
            int a, b;
            scanf("%s%d%d", type, &a, &b);
            if (type[0] == 'F')
            {
                sum += (double)F(a, b);
                printf("%d\n", F(a, b));
                cnt++;
            }
            if (type[0] == 'U')
                U(a, b);
            if (type[0] == 'E')
                E(a, b);
        }
        printf("%.3lf\n", sum/cnt);
    }
    return 0;
}
