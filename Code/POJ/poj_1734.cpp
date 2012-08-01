#include<cstdio>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100+5;
int n, m; // n:节点个数, m:边的个数
int w[MAXN][MAXN], d[MAXN][MAXN]; // 无向图, 最短路径
int cnt, out[MAXN], r[MAXN][MAXN]; // 记录最小环路径, r[i][j]: j到i的最短路径的第一步
int make_ans(int i, int j, int k)
{// 记录最小环路径
    cnt = 0;
    while (j != i)
    {
        out[++cnt] = j;
        j = r[i][j];
    }
    out[++cnt] = i; out[++cnt] = k;
    return 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                w[i][j] = INF;
                r[i][j] = i;
            }
        for (int i = 1; i <= m; i++)
        {
            int x, y, l;
            scanf("%d%d%d", &x, &y, &l);
            if (l < w[x][y])
                w[x][y] = w[y][x] = l;
        }
        memcpy(d, w, sizeof(w));
        int ans = INF; // 最小环
        for (int k = 1; k <= n; k++)
        {//Floyd
            for (int i = 1; i < k; i++)// 一个环中的最大结点为k(编号最大)
                if (w[k][i] < INF)
                    for (int j = i+1; j < k; j++)
                        if (d[i][j] < INF && w[k][j] < INF && ans > d[i][j]+w[k][i]+w[k][j])
                        {
                            ans = d[i][j]+w[k][i]+w[k][j];
                            make_ans(i, j, k); // 记录最小环
                        }
            for (int i = 1; i <= n; i++)
                if (d[i][k] < INF)
                    for (int j = 1; j <= n; j++)
                        if (d[k][j] < INF && d[i][j] > d[i][k]+d[k][j])
                        {
                            d[i][j] = d[i][k]+d[k][j];
                            r[i][j] = r[k][j];
                        }
        }
        if (ans < INF)
        {
            for (int i = cnt; i >= 1; i--)
            {
                if (i < cnt)
                    printf(" ");
                printf("%d", out[i]);
            }
            printf("\n");
        }
        else
            printf("No solution.\n");
    }
    return 0;
}
