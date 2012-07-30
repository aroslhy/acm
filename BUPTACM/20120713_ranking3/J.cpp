#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 500000+5, MAXM = 1000000+5;
const int INF = 0x3f3f3f3f;
const int MAX = 500000;
int n, a, sum[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    for (int i = 1; i <= MAX; i++)
        for (int j = i+i; j <= MAX; j += i)
            sum[j] += i;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        printf("%d\n", sum[a]);
    }
    return 0;
}
