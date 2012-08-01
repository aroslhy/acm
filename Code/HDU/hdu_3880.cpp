#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 55000+5, MAXM = 155000*2+5;
const int INF = 0x3f3f3f3f;
long long a, b, M;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%I64d%I64d%I64d", &a, &b, &M) != EOF)
    {
        if (a == b && b == 1)
        {
            printf("%I64d\n", M);
            continue;
        }
        long long c = max(a, b), m = c, ans = 0, k = 1;
        while (M/m)
        {
            ans += M/m*k;
            m *= c;
            k *= -1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
