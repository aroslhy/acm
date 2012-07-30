#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5, MAXM = 1000+5;
int n, m, a[MAXM];
double b[MAXM], d[MAXN];
int main()
{

//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &n, &m))
    {
        if (!n && !m) break;
        for (int i = 1; i <= m; i++)
            scanf("%d%lf", &a[i], &b[i]);
        for (int i = 0; i <= n; i++)
            d[i] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = n; j >= a[i]; j--)
                d[j] = min(d[j], d[j-a[i]]*(1-b[i]));
        printf("%.1lf%%\n", 100*(1-d[n]));
    }
    return 0;
}
