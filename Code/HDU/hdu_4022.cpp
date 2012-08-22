//2012-08-22 21:23:38	Accepted	4022	562MS	9808K	1770 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int MAXN = 100000+5, MAXM = 200000+5;
const int INF = 0x3f3f3f3f;
int N, M, x, y, c, d;
bool visP[MAXN], visL[2][MAXN];
vector<int> line[2][MAXN];
map<int, int> match[2];
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    while (scanf("%d%d", &N, &M) && N && M)
    {
        memset(visP, 0, sizeof(visP));
        memset(visL, 0, sizeof(visL));
        match[0].clear(); match[1].clear();
        int cnt[2] = {0, 0};
        for (int i = 0; i < N; i++)
        {
            scanf("%d%d", &x, &y);
            int m = match[0][x];
            if (!m)
            {
                m = ++cnt[0];
                match[0][x] = m;
                line[0][m].clear();
            }
            line[0][m].push_back(i);
            m = match[1][y];
            if (!m)
            {
                m = ++cnt[1];
                match[1][y] = m;
                line[1][m].clear();
            }
            line[1][m].push_back(i);
        }
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d", &c, &d);
            int ans = 0, m = match[c][d];
            if (m && !visL[c][m])
            {
                visL[c][m] = 1;
                for (int j = 0; j < (int)line[c][m].size(); j++)
                {
                    int p = line[c][m][j];
                    if (!visP[p])
                    {
                        visP[p] = 1;
                        ans++;
                    }
                }
            }
            printf("%d\n", ans);
        }
        printf("\n");
    }
    return 0;
}
