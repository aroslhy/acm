#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 16+5, MAXM = 500000+5;
const int INF = 0x3f3f3f3f;
int T, on[MAXN], ANS[1<<18];
bool vis[1<<18];
struct Node
{
    int st, cnt;
} root;
queue<Node> Q;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int G[MAXN][MAXN] = {{},
        {2,3,5,9},
        {1,4,6,10},
        {1,4,7,11},
        {2,3,8,12},
        {1,6,7,13},
        {2,5,8,14},
        {3,7,8,15},
        {4,6,7,16},
        {1,10,11,13},
        {2,9,12,14},
        {3,9,12,15},
        {4,10,11,16},
        {5,9,14,15},
        {6,10,13,16},
        {7,11,13,16},
        {8,12,14,15}};
    memset(ANS, -1, sizeof(ANS));
    int fin = 130560;
    root.st = fin; root.cnt = 0;
    Q.push(root);
    vis[root.st] = 1;
    while (!Q.empty())
    {
        Node u = Q.front(); Q.pop();
        if (u.cnt <= 3)
            ANS[u.st] = u.cnt;
        else
            continue;
        for (int i = 1; i <= 16; i++) if ((1<<i)&u.st)
            for (int k = 0; k < 4; k++)
            {
                int j = G[i][k];
//                for (int j = 1; j <= 16; j++) if (!((1<<j)&u.st)) if (g[i][j])
                if (!((1<<j)&u.st))
                {
                    Node v = u;
                    v.st ^= (1<<i);
                    v.st ^= (1<<j);
                    if (!vis[v.st])
                    {
                        vis[v.st] = 1;
                        v.cnt++;
                        Q.push(v);
                    }
                }
            }
    }
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        memset(vis, 0, sizeof(vis));
        int q = 0;
        for (int i = 1; i <= 16; i++)
        {
            scanf("%d", &on[i]);
            if (on[i])
                q ^= (1<<i);
        }
        if (ANS[q]+1)
            printf("Case #%d: %d\n", cas, ANS[q]);
        else
            printf("Case #%d: more\n", cas);
    }
    return 0;
}
