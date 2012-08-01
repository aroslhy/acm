#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 16;
const int INF = 0x3f3f3f3f;
int n, q, a[MAXN];
int F[MAXN], S[MAXN], T[MAXN];
struct Node
{
    int f, s, t;
} Tr[MAXN<<2];
void Init(int idx, int L, int R)
{
    if (L == R)
    {
        Tr[idx].f = F[L];
        Tr[idx].s = S[L];
        Tr[idx].t = T[L];
        return;
    }
    int left = idx<<1, right = (idx<<1)^1;
    int mid = (L+R)>>1;
    Init(left, L, mid);
    Init(right, mid+1, R);
    Tr[idx].f = max(Tr[left].f, Tr[right].f);
    Tr[idx].s = Tr[left].s;
    Tr[idx].t = Tr[right].t;
}
int find(int l, int r, int x)
{
    int mid = (l+r)>>1;
    if (S[mid] <= x && x <= T[mid])
        return mid;
    if (x < S[mid])
        return find(l, mid, x);
    else
        return find(mid+1, r, x);
}
int Query(int idx, int L, int R, int l, int r)
{
    if (l == L && r == R)
        return Tr[idx].f;
    int left = idx<<1, right = (idx<<1)^1;
    int mid = (L+R)>>1;
    if (r <= mid)
        return Query(left, L, mid, l, r);
    else if (mid < l)
        return Query(right, mid+1, R, l, r);
    else
        return max(Query(left, L, mid, l, mid), Query(right, mid+1, R, mid+1, r));
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &n) && n)
    {
        scanf("%d", &q);
        int cnt = 0, last = INF;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] == last)
            {
                F[cnt]++;
                T[cnt]++;
            }
            else
            {
                F[++cnt] = 1;
                S[cnt] = T[cnt] = i;
                last = a[i];
            }
        }
        Init(1, 1, cnt);
        while (q--)
        {
            int A, B;
            scanf("%d%d", &A, &B);
            int C = find(1, cnt, A), D = find(1, cnt, B);
            int m1 = T[C]-A+1, m2 = B-S[D]+1;
            int ans;
            if (C == D)
                ans = B-A+1;
            else
            {
                ans = max(m1, m2);
                if (D-C > 1)
                    ans = max(ans, Query(1, 1, cnt, C+1, D-1));
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
