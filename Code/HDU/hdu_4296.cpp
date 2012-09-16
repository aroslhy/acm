//2012-09-16 19:39:09	Accepted	4296	546MS	1392K	658 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
int N, w[MAXN], s[MAXN], r[MAXN];
bool cmp(const int a, const int b)
{
    return w[a]+s[a] < w[b]+s[b];
}
int main()
{
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%d%d", &w[i], &s[i]);
            r[i] = i;
        }
        sort(r, r+N, cmp);
        long long ans = 0, sumw = 0;
        for (int i = 0; i < N; i++)
        {
            ans = max(ans, sumw-s[r[i]]);
            sumw += w[r[i]];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
