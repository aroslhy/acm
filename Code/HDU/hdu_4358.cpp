//2012-08-13 13:04:48	Accepted	4358	1468MS	13712K	4040 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
using namespace std;
const int MAXN = 100000+5, MAXM = 200000+5;
int T, N, K, Q, X, Y, w[MAXN], q[MAXN], r[MAXN], ans[MAXN];
int fa[MAXN], s[MAXN], t[MAXN], ref[MAXN];
int e, head[MAXN], next[MAXM], v[MAXM];
int Tr[MAXN<<2];
bool vis[MAXN];
stack<int> sta;
map<int, int> match;
vector<int> pos[MAXN];
bool cmp(const int a, const int b)
{
    return t[q[a]] < t[q[b]];
}
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e++;
}
void Init(int idx, int L, int R)
{
    if (L == R)
    {
        Tr[idx] = 0;
        return;
    }
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    Init(left, L, mid);
    Init(right, mid+1, R);
    Tr[idx] = 0;
}
void PushDown(int idx)
{
    int left = idx*2, right = idx*2+1;
    Tr[left] += Tr[idx];
    Tr[right] += Tr[idx];
    Tr[idx] = 0;
}
void Update(int idx, int L, int R, int l, int r, int c)
{
    if (l <= L && R <= r)
    {
        Tr[idx] += c;
        return;
    }
    if (Tr[idx])
        PushDown(idx);
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    if (l <= mid)
        Update(left, L, mid, l, r, c);
    if (mid < r)
        Update(right, mid+1, R, l, r, c);
}
int Query(int idx, int L, int R, int x)
{
    if (x <= L && R <= x)
        return Tr[idx];
    if (Tr[idx])
        PushDown(idx);
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    if (x <= mid)
        return Query(left, L, mid, x);
    else
        return Query(right, mid+1, R, x);
}
void init()
{
    e = 0;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    match.clear();
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        init();
        scanf("%d%d", &N, &K);
        for (int i = 1; i <= N; i++)
            scanf("%d", &w[i]);
        for (int i = 1; i < N; i++)
        {
            scanf("%d%d", &X, &Y);
            addedge(X, Y);
            addedge(Y, X);
        }
        scanf("%d", &Q);
        for (int i = 0; i < Q; i++)
            scanf("%d", &q[i]), r[i] = i;
        sta.push(1);
        for (int step = 0; !sta.empty(); )
        {
            int u = sta.top();
            if (!vis[u])
            {
                vis[u] = 1;
                for (int i = head[u]; i != -1; i = next[i])
                    if (v[i] != fa[u])
                    {
                        sta.push(v[i]);
                        fa[v[i]] = u;
                    }
            }
            if (u == sta.top())
            {
                sta.pop();
                s[u] = t[u] = ++step;
                ref[t[u]] = u;
                for (int i = head[u]; i != -1; i = next[i])
                    if (v[i] != fa[u])
                        s[u] = min(s[u], s[v[i]]);
            }
        }
//        for (int u = 1; u <= N; u++)
//            printf("%d:[%d,%d]\n", u, s[u], t[u]);
        sort(r, r+Q, cmp);
        Init(1, 1, N);
        for (int cnt = 0, i = 1, k = 0; i <= N && k < Q; i++)
        {
            int u = ref[i], m = match[w[u]];
            if (!m)
            {
                m = match[w[u]] = ++cnt;
                pos[m].clear();
                pos[m].push_back(0);
            }
            pos[m].push_back(i);
            int n = pos[m].size()-1;
            if (n >= K)
                Update(1, 1, N, pos[m][n-K]+1, pos[m][n-K+1], 1);
            if (n > K)
                Update(1, 1, N, pos[m][n-K-1]+1, pos[m][n-K], -1);
            for (; t[q[r[k]]] == i && k < Q; k++)
                ans[r[k]] = Query(1, 1, N, s[q[r[k]]]);
        }
        printf("Case #%d:\n", cas);
        for (int i = 0; i < Q; i++)
            printf("%d\n", ans[i]);
        if (cas < T)
            printf("\n");
    }
    return 0;
}
