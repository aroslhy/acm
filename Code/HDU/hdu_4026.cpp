//2012-08-29 19:46:55	Accepted	4026	2250MS	8496K	2622 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 16, MAXN = 5;
const int dir[][2] = {
    {0,1},{1,4},{1,3},{1,2},{2,3},{3,4},{1,1},{4,3},{3,2},{2,1},{3,1},{4,1},
    {1,0},{1,-4},{1,-3},{1,-2},{2,-3},{3,-4},{1,-1},{4,-3},{3,-2},{2,-1},{3,-1},{4,-1},
    {0,-1},{-1,-4},{-1,-3},{-1,-2},{-2,-3},{-3,-4},{-1,-1},{-4,-3},{-3,-2},{-2,-1},{-3,-1},{-4,-1},
    {-1,0},{-1,4},{-1,3},{-1,2},{-2,3},{-3,4},{-1,1},{-4,3},{-3,2},{-2,1},{-3,1},{-4,1}
};
int N, M, mat[MAXN][MAXN];
int mp[MAXN][MAXN];
long long d[1<<MAX][MAX];
vector<vector<int> > vec[MAX];
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    while (scanf("%d%d", &N, &M) != EOF)
    {
        memset(d, 0, sizeof(d));
        int n = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                scanf("%d", &mat[i][j]);
                if (mat[i][j] == 0)
                {
                    mp[i][j] = n;
                    vec[n].clear();
                    n++;
                }
            }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (mat[i][j] == 0)
                {
                    for (int k = 0; k < 48; k++)
                    {
                        vector<int> t;
                        for (int l = 1; ; l++)
                        {
                            int x = i+l*dir[k][0], y = j+l*dir[k][1];
                            if (x < 0 || x >= N || y < 0 || y >= M || mat[x][y] == 1)
                                break;
                            if (mat[x][y] == 0)
                                t.push_back(mp[x][y]);
                        }
                        if (t.size())
                            vec[mp[i][j]].push_back(t);
                    }
                }
        int S = (1<<n)-1;
        for (int i = 0; i < n; i++)
            d[1<<i][i] = 1;
        for (int u = 1; u < S; u++)
            for (int i = 0; i < n; i++)
                for (int k = 0; k < (int)vec[i].size(); k++)
                    for (int j = 0; j < (int)vec[i][k].size(); j++)
                        if (!(u&(1<<vec[i][k][j])))
                        {
                            d[u|(1<<vec[i][k][j])][vec[i][k][j]] += d[u][i];
                            break;
                        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += d[S][i];
        printf("%I64d\n", ans);
    }
    return 0;
}
