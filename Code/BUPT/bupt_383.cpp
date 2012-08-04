#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAX = 100+5;
const int INF = 0x3f3f3f3f;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int N, M, mat[MAX][MAX];
int A, H;
bool vis[MAX][MAX];
int dfs(int x, int y)
{
//    cout<<"dfs "<<x<<" "<<y<<endl;
    int height = INF;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int p = x+dir[i][0], q = y+dir[i][1];
        if (vis[p][q])
            continue;
        if (mat[p][q] == mat[x][y])
        {
            int tmp = dfs(p, q);
            if (tmp < INF)
                height = min(height, tmp);
            else
                return height = INF;
        }
        else if (mat[p][q] > mat[x][y])
            height = min(height, mat[p][q]);
        else
            return height = INF;
    }
    return height;
}
void up(int x, int y)
{
    A++;
    mat[x][y] = H;
    vis[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int p = x+dir[i][0], q = y+dir[i][1];
        if (vis[p][q])
            up(p, q);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &N, &M) != EOF)
    {
        memset(mat, 0, sizeof(mat));
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                scanf("%d", &mat[i][j]);
        bool flag = 1;
        int ans = 0;
        while (flag)
        {
            flag = 0;
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= M; j++)
                {
                    memset(vis, 0, sizeof(vis));
                    int a = mat[i][j];
                    H = dfs(i, j);
                    while (H < INF)
                    {
                        flag = 1;
                        A = 0;
                        up(i, j);
                        ans += A*(H-a);
                        a = mat[i][j], H = dfs(i, j);
                    }
                }
        }
        printf("%d\n", ans);
    }
    return 0;
}
