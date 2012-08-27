//2012-08-24 09:13:45	Accepted	4393	343MS	932K	1372 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX = 100, MAXN = 50000+5, MAXM = MAX+5;
const int INF = 0x3f3f3f3f;
int T, N, F[MAXN], S[MAXN];
struct cmp
{
    bool operator()(const int a, const int b)
    {
        if (F[a] != F[b])
            return F[a] < F[b];
        else
            return a > b;
    }
};
priority_queue<int, vector<int>, cmp> pq[MAXM];
int main()
{
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        for (int i = 1; i <= MAX; i++)
            while (!pq[i].empty())
                pq[i].pop();
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
        {
            scanf("%d%d", &F[i], &S[i]);
            pq[S[i]].push(i);
        }
        printf("Case #%d:\n", cas);
        for (int k = 0; k < N; k++)
        {
            int p, ans = 0;
            for (int i = 1; i <= MAX; i++)
                if (!pq[i].empty())
                {
                    int x = pq[i].top();
                    if (F[x]+k*S[x] > F[ans]+k*S[ans] || (F[x]+k*S[x] == F[ans]+k*S[ans] && x < ans))
                        ans = x, p = i;
                }
            pq[p].pop();
            if (k)
                printf(" ");
            printf("%d", ans);
        }
        printf("\n");
    }
    return 0;
}
