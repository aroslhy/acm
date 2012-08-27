//2012-08-27 17:18:08	Accepted	4091	0MS	224K	1097 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 5000+5, MAXM = 200000+5, MAXK = 50+5;
const int INF = 0x3f3f3f3f;
int T;
long long N, S[2], V[2];
long long gcd(long long x, long long y)
{
    return y ? gcd(y, x%y) : x;
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
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%I64d", &N);
        for (int i = 0; i < 2; i++)
            scanf("%I64d%I64d", &S[i], &V[i]);
        long long l = lcm(S[0], S[1]);
        long long n1 = (N/l)*l, n2 = N%l;
        if (n1)
            n1 -= l, n2 += l;
        int c1 = V[0]*S[1] > V[1]*S[0] ? 0 : 1, c2 = S[0] > S[1] ? 0 : 1;;
        long long ans1 = n1/S[c1]*V[c1], ans2 = 0;
        for (int i = 0; i*S[c2] <= n2; i++)
            ans2 = max(ans2, i*V[c2]+(n2-i*S[c2])/S[1-c2]*V[1-c2]);
        printf("Case #%d: %I64d\n", cas, ans1+ans2);
    }
    return 0;
}
