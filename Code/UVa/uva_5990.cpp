#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 100+5;
const int INF = 0x3f3f3f3f;
const long long MOD = 1000000007;
int T, a[MAXN], C[MAXN];
long long N, l[MAXN], r[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &N);
        int p = INF, q = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &a[i]);
            p = min(p, a[i]);
            q = max(q, a[i]);
        }
        if (p == q)
        {
            printf("%lld ", (N*(N+1)/2)%MOD);
            long long ans = 1;
            for (int i = 1; i <= N; i++)
                ans = (ans<<1)%MOD;
            printf("%lld\n", (ans-1+MOD)%MOD);
            continue;
        }
//        printf("%d %d\n", p, q);
        a[N+1] = INF;
        int cnt = 0, lastp = 0, lastq = 0, cur = 0;
        int cntp = 0, cntq = 0;
        for (int i = 1; i <= N+1; i++)
        {
            if (a[i] == p || a[i] == INF)
            {
                if (a[i] == p) cntp++;
                if (a[i] != cur)
                {
                    cnt++;
                    C[cnt] = p;
                    l[cnt] = lastq+1;
                    r[cnt-1] = i-1;
                    cur = p;
                }
                lastp = i;
            }
            else if (a[i] == q || a[i] == INF)
            {
                if (a[i] == q) cntq++;
                if (a[i] != cur)
                {
                    cnt++;
                    C[cnt] = q;
                    l[cnt] = lastp+1;
                    r[cnt-1] = i-1;
                    cur = q;
                }
                lastq = i;
            }
        }
        cnt--;
        long long tot1 = (N*(N+1)/2)%MOD, ans1 = 0;
        for (int i = 1; i <= cnt; i++)
        {
//            printf("%d:%lld,%lld\n", C[i], l[i], r[i]);
            ans1 = (ans1+((r[i]-l[i]+1)*(r[i]-l[i]+2)/2)%MOD)%MOD;
            if (i-1)
                ans1 = (ans1-((r[i-1]-l[i]+1)*(r[i-1]-l[i]+2)/2)%MOD)%MOD;
        }
        ans1 = ((tot1-ans1)%MOD+MOD)%MOD;
        long long tot2 = 1, ta21 = 1, ta22 = 1, ta23 = 1;
        for (int i = 1; i <= N; i++)
        {
            if (i <= N-cntp-cntq)
                ta23 = (ta23<<1)%MOD;
            if (i <= cntp)
                ta21 = (ta21<<1)%MOD;
            if (i <= cntq)
                ta22 = (ta22<<1)%MOD;
            tot2 = (tot2<<1)%MOD;
        }
        long long ans2 = (((ta21-1)*(ta22-1)%MOD)*ta23+MOD)%MOD;
        printf("%lld %lld\n", ans1, ans2);
    }
    return 0;
}
