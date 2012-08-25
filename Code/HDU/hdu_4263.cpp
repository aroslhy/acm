//2012-08-25 20:10:56	Accepted	4263	1796MS	400K	1450 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5, MAXM = 1000000+5;
const int INF = 0x3f3f3f3f;
int N, M, K, f, t;
int u[MAXM], v[MAXM], fa[MAXN];
char c[5];
int find(int x)
{
    return fa[x] == x ? x : find(fa[x]);
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    while (scanf("%d%d%d", &N, &M, &K))
    {
        if (!N && !M && !K)
            break;
        for (int i = 1; i <= N; i++)
            fa[i] = i;
        int cntR = 0, cntB = 0, needR = N-1, needB = N-1;
        for (int i = 1; i <= M; i++)
        {
            scanf("%s%d%d", c, &f, &t);
            if (c[0] == 'R')
            {
                cntR++;
                int x = find(f), y = find(t);
                if (x != y)
                    fa[x] = y, needB--;
            }
            else
            {
                cntB++;
                u[cntB] = f;
                v[cntB] = t;
            }
        }
        for (int i = 1; i <= N; i++)
            fa[i] = i;
        for (int i = 1; i <= cntB; i++)
        {
            int x = find(u[i]), y = find(v[i]);
            if (x != y)
                fa[x] = y, needR--;
        }
        if (cntR >= N-1-K && N-1-K >= needR && cntB >= K && K >= needB)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
