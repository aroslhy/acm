#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1000+5, MAXM = 2000000+5, MAXP = 1000000+5;
const int INF = 0x7fffffff;
int N, M, R, X, Y, Z, A, B, C, fa[MAXN];
vector<int> u, v, w, a, b, c, re, rq;
vector<bool> ans;
bool cmp_e(const int a, const int b)
{
    return w[a] > w[b];
}
bool cmp_q(const int a, const int b)
{
    return c[a] > c[b];
}
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main()
{
    for (int cas = 1; scanf("%d%d%d", &N, &M, &R) != EOF; cas++)
    {
        u.clear(); v.clear(); w.clear();
        a.clear(); b.clear(); c.clear();
        re.clear(); rq.clear();
        ans.clear();
        for (int i = 1; i <= N; i++)
            fa[i] = i;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &X, &Y, &Z);
            u.push_back(X);
            v.push_back(Y);
            w.push_back(Z);
            re.push_back(i);
        }
        sort(re.begin(), re.end(), cmp_e);
        for (int i = 0; i < R; i++)
        {
            scanf("%d%d%d", &A, &B, &C);
            a.push_back(A);
            b.push_back(B);
            c.push_back(C);
            rq.push_back(i);
            ans.push_back(0);
        }
        sort(rq.begin(), rq.end(), cmp_q);
        for (int i = 0, j = 0; i < R; i++)
        {
            for (; w[re[j]] >= c[rq[i]] && j < M; j++)
            {
                int x = find(u[re[j]]), y = find(v[re[j]]);
                if (x != y)
                    fa[x] = y;
            }
            int x = find(a[rq[i]]), y = find(b[rq[i]]);
            if (x == y)
                ans[rq[i]] = 1;
        }
        printf("Case %d:\n", cas);
        for (int i = 0; i < R; i++)
            printf("%s\n", ans[i] ? "yes" : "no");
    }
    return 0;
}
