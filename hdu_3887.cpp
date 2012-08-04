#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN = 100000+5, MAXM = 200000+5;
int n, p, N;
int Tr[MAXM<<2];
int e, head[MAXN], next[MAXM], v[MAXM];
stack<int> S;
int s[MAXN], t[MAXN];
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e++;
}
void Init(int idx, int L, int R)
{
    Tr[idx] = 0;
    int left = (idx<<1), right = (idx<<1)^1;
    if (L < R)
    {
        int mid = ((L+R)>>1);
        Init(left, L, mid);
        Init(right, mid+1, R);
    }
}
void Update(int idx, int L, int R, int l)
{
    int left = (idx<<1), right = (idx<<1)^1;
    if (L == l && R == l)
        Tr[idx] += 1;
    else
    {
        int mid = ((L+R)>>1);
        if (l <= mid)
            Update(left, L, mid, l);
        else
            Update(right, mid+1, R, l);
        Tr[idx] = Tr[left]+Tr[right];
    }
}
int Query(int idx, int L, int R, int l, int r)
{
    int left = (idx<<1), right = (idx<<1)^1;
    if (L == l && R == r)
        return Tr[idx];
    int mid = ((L+R)>>1);
    if (r <= mid)
        return Query(left, L, mid, l, r);
    else if (mid < l)
        return Query(right, mid+1, R, l, r);
    else
        return Query(left, L, mid, l, mid)+Query(right, mid+1, R, mid+1, r);
}
void dfs()
{
    memset(s, 0, sizeof(s));
    int step = 0, cur[MAXN];
    for (int i = 1; i <= n; i++)
        cur[i] = head[i];
    S.push(p);
    while (!S.empty())
    {
        step++;
        int u = S.top();
        if (!s[u]) s[u] = step;
        for (; cur[u] != -1; cur[u] = next[cur[u]])
            if (!s[v[cur[u]]])
            {
                S.push(v[cur[u]]);
                cur[u] = next[cur[u]];
                break;
            }
        if (u == S.top())
        {
            S.pop();
            t[u] = step;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &n, &p) && n && p)
    {
        e = 0;
        memset(head, -1, sizeof(head));
        for (int i = 1; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addedge(x, y);
            addedge(y, x);
        }
        dfs();
//        for (int i = 1; i <= n; i++)
//            printf("%d:[%d,%d]\n", i, s[i], t[i]);
        N = 2*n-1;
        Init(1, 1, N);
        for (int i = 1; i <= n; i++)
        {
            int f = Query(1, 1, N, s[i], t[i]);
            Update(1, 1, N, s[i]);
            printf("%d", f);
            printf((i < n) ? " " : "\n");
        }
    }
    return 0;
}
