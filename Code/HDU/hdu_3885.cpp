#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN = 50+5, MAXM = 155000*2+5;
const int INF = 0x3f3f3f3f;
const int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,-1}};
int n, m, mat[2][MAXN][MAXN];
bool vis[MAXN][MAXN];
struct Rec
{
    int x1, y1, x2, y2;
    bool act;
    Rec(int a, int b, int c, int d)
    {
        x1 = a; y1 = b; x2 = c; y2 = d;
        act = 1;
    }
};
bool operator < (const Rec a, const Rec b)
{
    if (a.x1 == b.x1)
        return a.y1 < b.y1;
    else
        return a.x1 < b.x1;
}
vector<Rec> V;
struct Node
{
    int x, y;
    Node(int a, int b)
    {
        x = a; y = b;
    }
};
queue<Node> Q;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(vis, 0, sizeof(vis));
        for (int k = 0; k < 2; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    scanf("%d", &mat[k][i][j]);
        V.clear();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (!vis[i][j] && mat[0][i][j] != mat[1][i][j])
                {
                    int x1 = i, y1 = j, x2 = i, y2 = j;
                    Node x(i, j);
                    Q.push(x); vis[i][j] = 1;
                    while (!Q.empty())
                    {
                        Node u = Q.front(); Q.pop();
                        x1 = min(x1, u.x);
                        y1 = min(y1, u.y);
                        x2 = max(x2, u.x);
                        y2 = max(y2, u.y);
                        for (int k = 0; k < 8; k++)
                        {
                            Node v = u;
                            v.x += dir[k][0];
                            v.y += dir[k][1];
                            if (1 <= v.x && v.x <= n && 1 <= v.y && v.y <= m && !vis[v.x][v.y] && mat[0][v.x][v.y] != mat[1][v.x][v.y])
                            {
                                Q.push(v);
                                vis[v.x][v.y] = 1;
                            }
                        }
                    }
                    V.push_back(Rec(x1, y1, x2, y2));
                }
        int cnt = V.size();
//        for (int i = 0; i < cnt; i++)
//            printf("%d %d %d %d\n", V[i].x1, V[i].y1, V[i].x2, V[i].y2);
        bool fin = 0;
        while (!fin)
        {
            fin = 1;
            for (int i = 0; i < cnt; i++) if (V[i].act)
                for (int j = 0; j < cnt; j++) if (V[j].act) if (i != j)
                {
                    if (
                        (V[i].x1-1 <= V[j].x1 && V[j].x1 <= V[i].x2+1 && V[i].y1-1 <= V[j].y1 && V[j].y1 <= V[i].y2+1) ||
                        (V[i].x1-1 <= V[j].x1 && V[j].x1 <= V[i].x2+1 && V[i].y1-1 <= V[j].y2 && V[j].y2 <= V[i].y2+1) ||
                        (V[i].x1-1 <= V[j].x2 && V[j].x2 <= V[i].x2+1 && V[i].y1-1 <= V[j].y1 && V[j].y1 <= V[i].y2+1) ||
                        (V[i].x1-1 <= V[j].x2 && V[j].x2 <= V[i].x2+1 && V[i].y1-1 <= V[j].y2 && V[j].y2 <= V[i].y2+1) ||
                        ((V[i].x1-1 <= V[j].x1 && V[j].x1 <= V[i].x2+1 && V[i].x1-1 <= V[j].x2 && V[j].x2 <= V[i].x2+1) &&
                        (V[j].y1-1 <= V[i].y1 && V[i].y1 <= V[j].y2+1 && V[j].y1-1 <= V[i].y2 && V[i].y2 <= V[j].y2+1)))
                    {
                        V[i].x1 = min(V[i].x1, V[j].x1);
                        V[i].y1 = min(V[i].y1, V[j].y1);
                        V[i].x2 = max(V[i].x2, V[j].x2);
                        V[i].y2 = max(V[i].y2, V[j].y2);
                        V[j].act = 0;
                        fin = 0;
//                        printf("%d %d\n", i, j);
                    }
                }
        }
        sort(V.begin(), V.end());
        int ans = 0;
        for (int i = 0; i < cnt; i++)
        {
            if (V[i].act)
                ans++;
//            printf("%d %d %d %d\n", V[i].x1, V[i].y1, V[i].x2, V[i].y2);
        }
        printf("%d\n", ans);
        for (int i = 0; i < cnt; i++) if (V[i].act)
            printf("%d %d %d %d\n", V[i].x1, V[i].y1, V[i].x2, V[i].y2);
    }
    return 0;
}
