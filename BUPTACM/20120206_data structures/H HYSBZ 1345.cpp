#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
long long a, b;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    long long ans = 0;
    scanf("%lld", &a);
    for (int i = 2; i <= n; i++)
    {
        scanf("%lld", &b);
        ans += max(a, b);
        a = b;
    }
    printf("%lld\n", ans);
    return 0;
}
