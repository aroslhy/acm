//2012-08-28 15:27:28	Accepted	4028	187MS	11760K	1217 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAX = 40, MAXN = MAX+5;
const int INF = 0x3f3f3f3f;
int T, N;
long long M;
struct cmp
{
    bool operator()(const long long a, const long long b)
    {
        return a > b;
    }
};
map<long long, long long, cmp> d[MAXN];
long long gcd(long long x, long long y)
{
    return !y ? x : gcd(y, x%y);
}
long long lcm(long long x, long long y)
{
    return x/gcd(x, y)*y;
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    scanf("%d", &T);
    for (int i = 1; i <= MAX; i++)
    {
        d[i] = d[i-1];
        d[i][i]++;
        map<long long, long long, cmp>::iterator p = d[i-1].begin();
        for (; p != d[i-1].end(); p++)
            d[i][lcm(p->first, i)] += p->second;
    }
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%I64d", &N, &M);
        long long ans = 0;
        map<long long, long long, cmp>::iterator p = d[N].begin();
        for (; p != d[N].end() && p->first >= M; p++)
            ans += p->second;
        printf("Case #%d: %I64d\n", cas, ans);
    }
    return 0;
}
