#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 200+5;
int W, H, sg[MAX][MAX];
int g(int w, int h)
{
    if (sg[w][h] != -1)
        return sg[w][h];
    if (2 <= w && w <= 3 && 2 <= h && h <= 3)
        return sg[w][h] = sg[h][w] = 0;
    bool vis[MAX];
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= w/2; i++)
    {
        int x = g(i, h)^g(w-i, h);
        vis[x] = 1;
    }
    for (int i = 2; i <= h/2; i++)
    {
        int x = g(w, i)^g(w, h-i);
        vis[x] = 1;
    }
    for (int i = 0; ; i++)
        if (!vis[i])
            return sg[w][h] = sg[h][w] = i;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    memset(sg, -1, sizeof(sg));
    while (scanf("%d%d", &W, &H) != EOF)
    {
        if (g(W, H))
            printf("WIN\n");
        else
            printf("LOSE\n");
    }
    return 0;
}
