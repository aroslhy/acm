//2012-09-24 17:05:54	Accepted	4415	796MS	1392K	1847 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
const int INF = 0x3f3f3f3f;
int T, N, M, A[MAXN], B[MAXN], r[MAXN];
bool cmp(const int a, const int b)
{
    return A[a] < A[b];
}
int main()
{
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++)
        {
            scanf("%d%d", &A[i], &B[i]);
            r[i] = i;
        }
        sort(r, r+N, cmp);
        int ans[2] = {}, dur[2] = {M, M}, swd = 0, m = N;
        A[m] = B[m] = INF;
        for (int i = 0; i < N; i++)
        {
            if (B[r[i]])
            {
                if (A[r[i]] < A[m])
                    m = r[i];
                swd += B[r[i]];
            }
            else if (dur[0] >= A[r[i]])
            {
                ans[0]++;
                dur[0] -= A[r[i]];
            }
        }
        if (dur[1] >= A[m])
        {
            ans[1] = min(swd+1, N);
            dur[1] -= A[m];
            for (int i = 0; i < N && ans[1] < N; i++)
            {
                if (r[i] == m)
                    continue;
                if (dur[1] >= A[r[i]])
                {
                    ans[1]++;
                    dur[1] -= A[r[i]];
                }
                else
                    break;
            }
            ans[1] = min(ans[1], N);
        }
        if (ans[0] > ans[1])
            printf("Case %d: %d %d\n", cas, ans[0], M-dur[0]);
        else if (ans[0] < ans[1])
            printf("Case %d: %d %d\n", cas, ans[1], M-dur[1]);
        else if (dur[0] > dur[1])
            printf("Case %d: %d %d\n", cas, ans[0], M-dur[0]);
        else
            printf("Case %d: %d %d\n", cas, ans[1], M-dur[1]);
    }
    return 0;
}
