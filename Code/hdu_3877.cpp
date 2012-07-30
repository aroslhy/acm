#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5, MAXM = 200000+5, MAXP = 1000000+5;
const double eps = 1e-8;
int T, N, mark[MAXN], r[MAXN];
long long a[MAXN], b[MAXN];
bool cmp(const int i, const int j)
{
    if (a[i]+b[i] != a[j]+b[j])
        return a[i]+b[i] > a[j]+b[j];
    else if (mark[i] != mark[j])
        return mark[i] > mark[j];
    else
        return i < j;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%I64d%I64d", &a[i], &b[i]);
            if (a[i] > b[i])
                mark[i] = 1;
            else if (a[i] < b[i])
                mark[i] = -1;
            else
                mark[i] = 0;
            r[i] = i;
        }
        sort(r, r+N, cmp);
        for (int i = 0; i < N; i++)
        {
            int j = r[i];
            printf("%I64d+%I64d=[%s%I64d]\n", a[j], b[j], mark[j] ? (mark[j] > 0 ? ">" : "<") : "=", a[j]+b[j]);
        }
        printf("\n");
    }
    return 0;
}
