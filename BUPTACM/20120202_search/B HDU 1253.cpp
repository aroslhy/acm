#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX = 50+5;
const int dir[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
struct Node{int x, y, z, t;};
int K, A, B, C, T, m[MAX][MAX][MAX];
bool vis[MAX][MAX][MAX];
queue<Node> Q;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &K);
    while (K--)
    {
        scanf("%d%d%d%d", &A, &B, &C, &T);
        for (int i = 0; i < A; i++)
            for (int j = 0; j < B; j++)
                for (int k = 0; k < C; k++)
                    scanf("%d", &m[i][j][k]);
        memset(vis, 0, sizeof(vis));
        Node root;
        root.x = 0; root.y = 0; root.z = 0; root.t = 0;
        Q.push(root); vis[0][0][0] = 1;
        int ans = 0x3f3f3f3f;
        while (!Q.empty())
        {
            Node u = Q.front(); Q.pop();
            if (u.x == A-1 && u.y == B-1 && u.z == C-1)
                ans = u.t;
            for (int i = 0; i < 6; i++)
            {
                Node v;
                v.x = u.x+dir[i][0];
                v.y = u.y+dir[i][1];
                v.z = u.z+dir[i][2];
                if (0 <= v.x && v.x < A && 0 <= v.y && v.y < B && 0 <= v.z && v.z < C && !m[v.x][v.y][v.z] && !vis[v.x][v.y][v.z])
                {
                    v.t = u.t+1;
                    Q.push(v);
                    vis[v.x][v.y][v.z] = 1;
                }
            }
        }
        if (ans > T)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
