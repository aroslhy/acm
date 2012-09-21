//2012-09-20 16:05:55	Accepted	4293	46MS	1224K	1178 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 500+5;
const int INF = 0x3f3f3f3f;
int N, a, b, A[MAXN], B[MAXN], r[MAXN];
int mp[MAXN][MAXN], num[MAXN], d[MAXN];
bool cmp(const int a, const int b)
{
    return B[a] < B[b];
}
int main()
{
    while (scanf("%d", &N) != EOF)
    {
        memset(mp, 0, sizeof(mp));
        memset(num, 0, sizeof(num));
        memset(d, 0, sizeof(d));
        int n = 0, ans = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d%d", &a, &b);
            if (a+b >= N)
                continue;
            int &m = mp[a+1][N-b];
            if (!m)
            {
                m = ++n;
                A[n] = a+1;
                B[n] = N-b;
                r[n] = n;
            }
            num[m] = min(num[m]+1, N-a-b);
        }
        sort(r+1, r+1+n, cmp);
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < A[r[i]]; j++)
                d[B[r[i]]] = max(d[B[r[i]]], d[j]+num[r[i]]);
        for (int i = 1; i <= N; i++)
            ans = max(ans, d[i]);
        printf("%d\n", ans);
    }
    return 0;
}
