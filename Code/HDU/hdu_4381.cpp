//2012-08-22 11:57:52	Accepted	4381	78MS	300K	1975 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1000+5, MAXM = 1000+5;
const int INF = 0x3f3f3f3f;
int T, N, M, si, ai, xi, d[2][MAXN];
struct Operation
{
    int a, x;
    Operation(){}
    Operation(int e1, int e2)
    {
        a = e1; x = e2;
    }
};
bool cmp (const Operation A, const Operation B)
{
    return A.a < B.a;
}
vector<Operation> opt[2];
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        opt[0].clear(); opt[1].clear();
        scanf("%d%d", &N, &M);
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &si, &ai, &xi);
            if (si == 2)
                ai = N-ai+1;
            opt[si-1].push_back(Operation(ai, xi));
        }
        for (int k = 0; k < 2; k++)
        {
            sort(opt[k].begin(), opt[k].end(), cmp);
            fill(d[k]+1, d[k]+1+N, INF);
            for (int j = 0; j < (int)opt[k].size(); j++)
                for (int i = N; i >= 1; i--)
                {
                    if (i >= opt[k][j].x && i <= opt[k][j].a)
                        d[k][i] = min(d[k][i], d[k][i-opt[k][j].x]+1);
                }
//            for (int i = 1; i <= N; i++)
//                if (d[k][i] < INF)
//                    printf("%d,%d:%d\n", k, i, d[k][i]);
        }
        int ans_max = -1, ans_min = INF;
        for (int k = N; k >= 0 && ans_max == -1; k--)
            for (int i = 0; i <= k && ans_max == -1; i++)
                if (d[0][i] < INF && d[1][k-i] < INF)
                    ans_max = k;
        for (int i = 0; i <= ans_max; i++)
            if (d[0][i] < INF && d[1][ans_max-i] < INF)
                ans_min = min(ans_min, d[0][i]+d[1][ans_max-i]);
        printf("Case %d: %d %d\n", cas, ans_max, ans_min);
    }
    return 0;
}
