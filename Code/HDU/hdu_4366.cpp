//2012-08-15 12:18:12	Accepted	4366	296MS	3844K	3444 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN = 50000+5, MAXM = 100000+5;
int T, N, M, fa[MAXN], loy[MAXN], abi[MAXN], r[MAXN], fir[MAXN], ans[MAXN];
int e, head[MAXN], next[MAXN], v[MAXN];
int s[MAXN], t[MAXN];
int Tr[MAXM<<2];
bool qed[MAXN];
stack<int> sta;
bool cmp(const int a, const int b)
{
    if (abi[a] != abi[b])
        return abi[a] > abi[b];
    else
        return a < b;
}
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e++;
}
void PushUp(int idx)
{
    int left = idx*2, right = idx*2+1;
    if (Tr[left] != -1 && Tr[right] != -1)
    {
        if (loy[Tr[left]] > loy[Tr[right]])
            Tr[idx] = Tr[left];
        else
            Tr[idx] = Tr[right];
    }
    else
        Tr[idx] = max(Tr[left], Tr[right]);
}
void Init(int idx, int L, int R)
{
    if (L == R)
    {
        Tr[idx] = -1;
        return;
    }
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    Init(left, L, mid);
    Init(right, mid+1, R);
    PushUp(idx);
}
void Update(int idx, int L, int R, int u)
{
    int x = s[u];
    if (x <= L && R <= x)
    {
        Tr[idx] = u;
        return;
    }
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    if (x <= mid)
        Update(left, L, mid, u);
    else
        Update(right, mid+1, R, u);
    PushUp(idx);
}
int Query(int idx, int L, int R, int l, int r)
{
    if (l <= L && R <= r)
        return Tr[idx];
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    int ql = -1, qr = -1, q = -1;
    if (l <= mid)
        ql = Query(left, L, mid, l, r);
    if (mid < r)
        qr = Query(right, mid+1, R, l, r);
    if (ql != -1 && qr != -1)
    {
        if (loy[ql] > loy[qr])
            q = ql;
        else
            q = qr;
    }
    else
        q = max(ql, qr);
    return q;
}
void init()
{
    e = 0;
    memset(head, -1, sizeof(head));
    memset(s, 0, sizeof(s));
    memset(qed, 0, sizeof(qed));
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        init();
        scanf("%d%d", &N, &M);
        for (int i = 1; i < N; i++)
        {
            scanf("%d%d%d", &fa[i], &loy[i], &abi[i]);
            addedge(fa[i], i);
            r[i] = i;
        }
        sort(r+1, r+N, cmp);
        for (int i = 1; i <= M; i++)
        {
            scanf("%d", &fir[i]);
            qed[fir[i]] = 1;
        }
        int step = 0;
        sta.push(0);
        while (!sta.empty())
        {
            int u = sta.top();
            if (!s[u])
                s[u] = ++step;
            for (int i = head[u]; i != -1; i = next[i])
                if (!s[v[i]])
                    sta.push(v[i]);
            if (u == sta.top())
            {
                t[u] = ++step;
                sta.pop();
            }
        }
//        for (int i = 0; i < N; i++)
//            printf("%d:[%d,%d]\n", i, s[i], t[i]);
        Init(1, 1, 2*N);
        for (int i = 1; i < N; i++)
        {
            int u = r[i];
            if (qed[u])
                ans[u] = Query(1, 1, 2*N, s[u], t[u]);
            Update(1, 1, 2*N, u);
        }
        for (int i = 1; i <= M; i++)
            printf("%d\n", ans[fir[i]]);
    }
    return 0;
}
