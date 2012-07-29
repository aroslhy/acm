#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 5000+5, MAXM = 1000*2+5;
const int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
const long long inf = 1<<30, INF = inf*inf;
int r, c, cost, cnt;
char mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
struct Node
{
    int x, y;
    long long Cost;
    Node(){}
    Node(int a, int b)
    {
        x = a; y = b;
        Cost = 0;
    }
};
bool operator < (const Node a, const Node b)
{
    return a.Cost> b.Cost;
}
Node WH[2500000+5];
priority_queue<Node> Q;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d%d", &r, &c, &cost) != EOF)
    {
        cnt = 0;
        Node s, t;
        for (int i = 0; i < r; i++)
        {
            scanf("%s", mat[i]);
            for (int j = 0; j < c; j++)
            {
                vis[i][j] = 0;
                if (mat[i][j] == 'P')
                    WH[cnt++] = Node(i, j);
                else if (mat[i][j] == 'Y')
                    s = Node(i, j);
                else if (mat[i][j] == 'C')
                    t = Node(i, j);
            }
        }
        long long ans = INF;
        bool flag = 0;
        while (!Q.empty()) Q.pop();
        Q.push(s);
        vis[s.x][s.y] = 1;
        while (!Q.empty())
        {
            Node u = Q.top(); Q.pop();
            if (mat[u.x][u.y] == 'C')
            {
                ans = u.Cost;
                break;
            }
            else if (mat[u.x][u.y] == 'P' && !flag)
            {
                flag = 1;
                for (int i = 0; i < cnt; i++)
                {
                    Node v = u;
                    v.x = WH[i].x; v.y = WH[i].y;
                    if (!vis[v.x][v.y])
                    {
                        Q.push(v);
                        vis[v.x][v.y] = 1;
                    }
                }
            }
            for (int i = 0; i < 4; i++)
            {
                Node v = u;
                v.x += dir[i][0]; v.y += dir[i][1];
                if (0 <= v.x && v.x < r && 0 <= v.y && v.y < c && mat[v.x][v.y] != '#' && !vis[v.x][v.y])
                {
                    if (mat[v.x][v.y] == '*')
                        v.Cost += cost;
                    Q.push(v);
                    vis[v.x][v.y] = 1;
                }
            }
        }
        if (ans < INF)
            printf("%I64d\n", ans);
        else
            printf("Damn teoy!\n");
    }
    return 0;
}
