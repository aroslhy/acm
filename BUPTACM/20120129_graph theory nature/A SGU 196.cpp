#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5;
int N, M, d[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d%d", &N, &M);
    memset(d, 0, sizeof(d));
    while (M--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        d[u]++; d[v]++;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans += d[i]*d[i];
    printf("%d\n", ans);
    return 0;
}
