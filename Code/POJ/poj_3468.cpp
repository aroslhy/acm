//bigoceanlhy	3468	Accepted	4628K	1641MS	C++	2167B	2012-08-08 19:34:53
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 10000+5;
int N, Q, a, b, c, A[MAXN];
long long Tr[MAXN<<2], mark[MAXN<<2];
char cmd[5];
void PushDown(int idx, int L, int R)
{
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    Tr[left] += mark[idx]*(mid-L+1);
    mark[left] += mark[idx];
    Tr[right] += mark[idx]*(R-mid);
    mark[right] += mark[idx];
    mark[idx] = 0;
}
void Init(int idx, int L, int R)
{
    if (L == R)
    {
        Tr[idx] = A[L];
        mark[idx] = 0;
        return;
    }
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    Init(left, L, mid);
    Init(right, mid+1, R);
    Tr[idx] = Tr[left]+Tr[right];
    mark[idx] = 0;
}
void Update(int idx, int L, int R, int l, int r, int c)
{
    if (l <= L && R <= r)
    {
        Tr[idx] += c*(R-L+1);
        mark[idx] += c;
        return;
    }
    if (mark[idx])
        PushDown(idx, L, R);
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    if (l <= mid)
        Update(left, L, mid, l, r, c);
    if (mid < r)
        Update(right, mid+1, R, l, r, c);
    Tr[idx] = Tr[left]+Tr[right];
}
long long Query(int idx, int L, int R, int l, int r)
{
    if (l <= L && R <= r)
        return Tr[idx];
    if (mark[idx])
        PushDown(idx, L, R);
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    long long q = 0;
    if (l <= mid)
        q += Query(left, L, mid, l, r);
    if (mid < r)
        q += Query(right, mid+1, R, l, r);
    return q;
}
int main()
{
    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
    Init(1, 1, N);
    for (int i = 1; i <= Q; i++)
    {
        scanf("%s", cmd);
        if (cmd[0] == 'C')
        {
            scanf("%d%d%d", &a, &b, &c);
            if (c)
                Update(1, 1, N, a, b, c);
        }
        else
        {
            scanf("%d%d", &a, &b);
            printf("%lld\n", Query(1, 1, N, a, b));
        }
    }
    return 0;
}
