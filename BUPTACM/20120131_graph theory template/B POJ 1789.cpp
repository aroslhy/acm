#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int V = 2000+5;
int N;
char code[V][10];
#define typec int // type of cost
const typec inf = 0x3f3f3f3f; // max of cost
int vis[V]; typec lowc[V];
typec cost[V][V];
typec prim(int n) // vertex: 0 ~ n-1
{
    int i, j, p;
    typec minc, res = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    for (i=1; i<n; i++) lowc[i] = cost[0][i];
    for (i=1; i<n; i++) {
        minc = inf; p = -1;
        for (j=0; j<n; j++)
            if (0 == vis[j] && minc > lowc[j]) {
                minc = lowc[j]; p = j;
            }
        if (inf == minc) return -1; // 原图不连通
        res += minc; vis[p] = 1;
        for (j=0; j<n; j++)
            if (0 == vis[j] && lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
    }
    return res;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &N))
    {
        if (!N) break;
        for (int i = 0; i < N; i++)
        {
            scanf("%s", code[i]);
            cost[i][i] = 0;
            for (int j = 0; j < i; j++)
            {
                cost[i][j] = 0;
                for (int k = 0; k < 7; k++)
                    if (code[i][k] != code[j][k])
                        cost[i][j]++;
                cost[j][i] = cost[i][j];
            }
        }
        printf("The highest possible quality is 1/%d.\n", prim(N));
    }
    return 0;
}
