#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 20+5, MAXM = 16+5;
int N, w[MAXN], M, data[MAXM][MAXN], effect[MAXN], num[MAXN], count, vis[MAXN];
void Search(int x)
{
    if (x > M)
    {
        for (int i = 1; i <= N; i++)
            if (effect[i] < w[i])
                return;
        int _count = 0;
        for (int i = 1; i <= N; i++)
            if (vis[i])
            _count++;
        if (_count <= count)
            return;
        count = 0;
        for (int i = 1; i <= M; i++)
            if (vis[i])
                num[++count] = i;
        return;
    }
    for (int i = 1; i >= 0; i--)
    {
        for (int j = 1; j <= N; j++)
            effect[j] += i*data[x][j];
        vis[x] += i;
        Search(x+1);
        for (int j = 1; j <= N; j++)
            effect[j] -= i*data[x][j];
        vis[x] -= i;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 1; i <= N; i++)
            scanf("%d", &w[i]);
        scanf("%d", &M);
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++)
                scanf("%d", &data[i][j]);
        count = 0; Search(1);
        printf("%d", count);
        for (int i = 1; i <= count; i++)
            printf(" %d", num[i]);
        printf("\n");
    }
    return 0;
}
