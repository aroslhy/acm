#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 13;
const int INF = 0x3f3f3f3f;
int n, w[MAXN][MAXN];
int d[1<<11][MAXN];
void floyd()
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                w[i][j] = min(w[i][j], w[i][k]+w[k][j]);
}
void hamilton_path()
{
    int m = (1<<n);
    for (int u = 0; u < m; u++)
        for(int i = 0; i < n; i++)
            d[u][i] = INF;
    for (int i = 0; i < n; i++)
        d[(1<<i)][i] = w[0][i];
    for (int u = 0; u < m; u++)
        for (int i = 0; i < n; i++) if ((1<<i)&u)
            for (int j = 0; j < n; j++) if ((1<<j)&u)
                if (i != j)
                {
                    int v = u^(1<<j);
                    d[u][j] = min(d[u][j], d[v][i]+w[i][j]);
                }
}
int main()
{
    while (scanf("%d", &n) && n)
    {
        n++;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &w[i][j]);
        floyd(); hamilton_path();
        printf("%d\n", d[(1<<n)-1][0]);
    }
    return 0;
}
