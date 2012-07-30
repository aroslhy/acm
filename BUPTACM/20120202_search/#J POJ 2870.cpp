#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAX = 7+5, INF = 0x3f3f3f3f;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int N, M, B, bn[MAX][MAX], bc[MAX][MAX], ans;
bool b[MAX][MAX], l[MAX][MAX], lit[MAX][MAX], lit_tmp[MAX][MAX];
bool canplace(int x, int y)
{
    if (b[x][y])
        return 0;
    for (int i = 0; i < 4; i++)
    {
        int p = x+dir[i][0], q = y+dir[i][1];
        if (1 <= p && p <= N && 1 <= q && q <= M)
        {
            if (b[p][q] && bn[p][q] != -1 && bc[p][q]+1 > bn[p][q])
                return 0;
            while (1 <= p && p <= N && 1 <= q && q <= M)
            {
                if (l[p][q])
                    return 0;
                if (b[p][q])
                    break;
                p += dir[i][0], q += dir[i][1];
            }
        }
    }
    return 1;
}
void place(int x, int y)
{
    l[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int p = x+dir[i][0], q = y+dir[i][1];
        if (1 <= p && p <= N && 1 <= q && q <= M)
        {
            if (b[p][q] && bn[p][q] != -1)
                bc[p][q]++;
            memcpy(lit_tmp, lit, sizeof(lit));
            while (1 <= p && p <= N && 1 <= q && q <= M)
            {
                if (b[p][q])
                    break;
                else
                    lit[p][q] = 1;
                p += dir[i][0], q += dir[i][1];
            }
        }
    }
}
void unplace(int x, int y)
{
    l[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int p = x+dir[i][0], q = y+dir[i][1];
        if (1 <= p && p <= N && 1 <= q && q <= M)
        {
            if (b[p][q] && bn[p][q] != -1)
                bc[p][q]--;
        }
    }
    memcpy(lit, lit_tmp, sizeof(lit));
}
void dfs(int x, int y)
{
    if (x > N)
    {
        int cnt = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
            {
                if (!b[i][j] && !l[i][j] && !lit[i][j])
                    return;
                if (l[i][j])
                    cnt++;
            }
        ans = min(ans, cnt);
        return;
    }
    for (int i = y; i <= M; i++)
    {
        if (canplace(x, i))
        {
            place(x, i);
            if (y == M)
                dfs(x+1, 1);
            else
                dfs(x, i+1);
            unplace(x, i);
        }
        else
        {
            if (y == M)
                dfs(x+1, 1);
            else
                dfs(x, i+1);
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &N, &M))
    {
        if (!N && !M) break;
        scanf("%d", &B);
        memset(b, 0, sizeof(b));
        memset(bc, 0, sizeof(bc));
        memset(l, 0, sizeof(l));
        for (int i = 1; i <= B; i++)
        {
            int R, C, K;
            scanf("%d%d%d", &R, &C, &K);
            b[R][C] = 1;
            bn[R][C] = K;
        }
        ans = INF;
        dfs(1, 1);
        if (ans < INF)
            printf("%d\n", ans);
        else
            printf("No solution\n");
    }
    return 0;
}
