#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 100000+5, MAXM = 100000+5, MAXP = 300000+5;
int T, N, M, Q[MAXM];
int Tr[MAXP<<2], mark[MAXP<<2];
int t[MAXP];
struct Flower
{
    int S, T;
} f[MAXN];
map<int, int> match;
void Init(int idx, int L, int R)
{
    int left = (idx<<1), right = (idx<<1)^1;
    if (L < R)
    {
        int mid = (L+R)>>1;
        Init(left, L, mid);
        Init(right, mid+1, R);
    }
    Tr[idx] = 0;
    mark[idx] = 0;
}
void UpdateSon(int idx)
{
    int left = (idx<<1), right = (idx<<1)^1;
    Tr[left] += mark[idx];
    mark[left] += mark[idx];
    Tr[right] += mark[idx];
    mark[right] += mark[idx];
    mark[idx] = 0;
}
void Update(int idx, int L, int R, int l, int r)
{
    if (L < R && mark[idx])
        UpdateSon(idx);
    int left = (idx<<1), right = (idx<<1)^1;
    if (L == l && R == r)
    {
        Tr[idx]++;
        mark[idx]++;
    }
    else
    {
        int mid = (L+R)>>1;
        if (r <= mid)
            Update(left, L, mid, l, r);
        else if (mid < l)
            Update(right, mid+1, R, l, r);
        else
        {
            Update(left, L, mid, l, mid);
            Update(right, mid+1, R, mid+1, r);
        }
        Tr[idx]++;
    }
}
int Query(int idx, int L, int R, int x)
{
    if (L < R && mark[idx])
        UpdateSon(idx);
    int left = (idx<<1), right = (idx<<1)^1;
    if (L == x && R == x)
        return Tr[idx];
    int mid = (L+R)>>1;
    if (x <= mid)
        return Query(left, L, mid, x);
    else
        return Query(right, mid+1, R, x);
}
int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        match.clear();
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++)
        {
            scanf("%d%d", &f[i].S, &f[i].T);
            t[2*i+0] = f[i].S;
            t[2*i+1] = f[i].T;
        }
        for (int i = 0; i < M; i++)
        {
            scanf("%d", &Q[i]);
            t[2*N+i] = Q[i];
        }
        sort(t, t+2*N+M);
        int n = 0;
        match[t[0]] = ++n;
        for (int i = 1; i < 2*N+M; i++)
            if (t[i] != t[i-1])
                match[t[i]] = ++n;
        Init(1, 1, n);
        for (int i = 0; i < N; i++)
            Update(1, 1, n, match[f[i].S], match[f[i].T]);
        printf("Case #%d:\n", cas);
        for (int i = 0; i < M; i++)
        {
            int x = match[Q[i]];
            int q = Query(1, 1, n, x);
            printf("%d\n", q);
        }
    }
    return 0;
}
