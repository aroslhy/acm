//2012-08-21 09:15:32	Accepted	3677	15MS	264K	1034 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 8+5, MAXM = 200000+5, MAXP = 1000000+5;
const int INF = 0x7fffffff;
int L, T, N, spd[MAXN], v[MAXN];
double ANS;
bool vis[MAXN];
void dfs(int x)
{
    if (x == N)
    {
        double ans = 0;
        for (int i = 1; i < N; i++)
        {
            if ((v[i]-v[i-1])*L <= v[i]*v[i-1]*T)
                ans += T;
            else
                return;
        }
        ans += (double)L/v[N-1];
        ANS = min(ANS, ans);
        return;
    }
    for (int i = 0; i < N; i++)
        if (!vis[i])
        {
            vis[i] = 1;
            v[x] = spd[i];
            dfs(x+1);
            vis[i] = 0;
        }
}
int main()
{
    for (int cas = 1; scanf("%d", &L) && L; cas++)
    {
        scanf("%d%d", &N, &T);
        for (int i = 0; i < N; i++)
            scanf("%d", &spd[i]);
        ANS = INF;
        dfs(0);
        printf("Case %d: %.0lf\n", cas, ANS);
    }
    return 0;
}
