//2012-08-07 19:35:48	Accepted	1698	1015MS	2288K	2220 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 200000+5;
int T, N, Q, X, Y, Z;
int Tr[MAXN<<2], mark[MAXN<<2];
void PushUp(int idx)
{
    int left = idx*2, right = idx*2+1;
    Tr[idx] = Tr[left]+Tr[right];
}
void PushDown(int idx, int L, int R)
{
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    Tr[left] = mark[idx]*(mid-L+1);
    mark[left] = mark[idx];
    Tr[right] = mark[idx]*(R-mid);
    mark[right] = mark[idx];
    mark[idx] = 0;
}
void Init(int idx, int L, int R)
{
    if (L == R)
    {
        Tr[idx] = 1;
        mark[idx] = 0;
        return;
    }
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    Init(left, L, mid);
    Init(right, mid+1, R);
    PushUp(idx);
    mark[idx] = 0;
}
void Update(int idx, int L, int R, int l, int r, int c)
{
    if (L == l && R == r)
    {
        Tr[idx] = c*(R-L+1);
        mark[idx] = c;
        return;
    }
    if (mark[idx])
        PushDown(idx, L, R);
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    if (r <= mid)
        Update(left, L, mid, l, r, c);
    else if (mid < l)
        Update(right, mid+1, R, l, r, c);
    else
    {
        Update(left, L, mid, l, mid, c);
        Update(right, mid+1, R, mid+1, r, c);
    }
    PushUp(idx);
}
void Update_PIAOYI(int idx, int L, int R, int l, int r, int c)
{
    if (l <= L && R <= r)
    {
        Tr[idx] = c*(R-L+1);
        mark[idx] = c;
        return;
    }
    if (mark[idx])
        PushDown(idx, L, R);
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    if (l <= mid)
        Update_PIAOYI(left, L, mid, l, r, c);
    if (mid < r)
        Update_PIAOYI(right, mid+1, R, l, r, c);
    PushUp(idx);
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d", &N, &Q);
        Init(1, 1, N);
        for (int i = 0; i < Q; i++)
        {
            scanf("%d%d%d", &X, &Y, &Z);
            Update(1, 1, N, X, Y, Z);
        }
        printf("Case %d: The total value of the hook is %d.\n", cas, Tr[1]);
    }
    return 0;
}
