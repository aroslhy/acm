//2012-08-16 21:19:11	Accepted	4362	281MS	868K	2339 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1000+5, MAXM = 50+5;
const int INF = 2000000000+5;
int T, m, n, s;
struct Ball
{
    int loc, cost;
} ball[MAXM][MAXN];
bool operator < (const Ball a, const Ball b)
{
    return a.loc < b.loc;
}
int d[MAXM][MAXN];
vector<int> mq;
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &m, &n, &s);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &ball[i][j].loc);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &ball[i][j].cost);
        for (int j = 1; j <= n; j++)
            ball[0][j].loc = s;
        for (int i = 1; i <= m; i++)
        {
            fill(d[i]+1, d[i]+1+n, INF);
            sort(ball[i]+1, ball[i]+1+n);
            mq.clear();
            int cur = 1;
            for (int j = 1; j <= n; j++)
            {
                for (; ball[i-1][cur].loc <= ball[i][j].loc && cur <= n; cur++)
                {
                    int u = d[i-1][cur]+ball[i][n].loc-ball[i-1][cur].loc;
                    while (mq.size() && u < mq[mq.size()-1])
                        mq.pop_back();
                    mq.push_back(u);
                }
                if (mq.size())
                    d[i][j] = mq[0]-(ball[i][n].loc-ball[i][j].loc)+ball[i][j].cost;
            }
            mq.clear();
            cur = n;
            for (int j = n; j >= 1; j--)
            {
                for (; ball[i-1][cur].loc >= ball[i][j].loc && cur >= 1; cur--)
                {
                    int u = d[i-1][cur]+ball[i-1][cur].loc-ball[i][1].loc;
                    while (mq.size() && u < mq[mq.size()-1])
                        mq.pop_back();
                    mq.push_back(u);
                }
                if (mq.size())
                    d[i][j] = min(d[i][j], mq[0]-(ball[i][j].loc-ball[i][1].loc)+ball[i][j].cost);
            }
        }
        int ans = INF;
        for (int j = 1; j <= n; j++)
            ans = min(ans, d[m][j]);
        printf("%d\n", ans);
    }
    return 0;
}
