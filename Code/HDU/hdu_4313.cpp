#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100000+5, MAXM = 640000+5, MAXP = 400+5;
const int INF = 0x3f3f3f3f;
int T, N, K, is[MAXN], fa[MAXN];
struct Edge
{
    int x, y;
    long long z;
} e[MAXN];
bool operator < (const Edge a, const Edge b)
{
    return a.z > b.z;
}
int find(int x)
{
    return (x == fa[x]) ? x : fa[x] = find(fa[x]);
}
int main()
{

    scanf("%d", &T);
    while (T--)
    {
        memset(is, 0, sizeof(is));
        scanf("%d%d", &N, &K);
        long long tot = 0, add = 0;
        for (int i = 0; i < N-1; i++)
        {
            scanf("%d%d%I64d", &e[i].x, &e[i].y, &e[i].z);
            tot += e[i].z;
            fa[i] = i;
        }
        fa[N-1] = N-1;
        for (int i = 0; i < K; i++)
        {
            int t;
            scanf("%d", &t);
            is[t] = 1;
        }
        sort(e, e+N-1);
        for (int i = 0; i < N-1; i++)
        {
            int u = find(e[i].x), v = find(e[i].y);
            if (!(is[u] && is[v]))
            {
                fa[u] = v;
                add += e[i].z;
                if (is[u] || is[v])
                    is[v] = 1;
//                printf("%d\n", e[i].z);
            }
        }
        printf("%I64d\n", tot-add);
    }
    return 0;
}
