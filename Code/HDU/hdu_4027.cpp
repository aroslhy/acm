//2012-08-28 13:54:56	Accepted	4027	875MS	4096K	2141 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 200000+5, MAXK = 50+5;
const int INF = 0x3f3f3f3f;
int N, M, T, X, Y;
int Type[MAXN<<2];
long long E[MAXN];
long long Tsum[MAXN<<2];
void PushUp(int idx)
{
    int left = idx*2, right = idx*2+1;
    Tsum[idx] = Tsum[left]+Tsum[right];
    Type[idx] = Type[left]|Type[right];
}
void Init(int idx, int L, int R)
{
    if (L == R)
    {
        Tsum[idx] = E[L];
        Type[idx] = E[L] > 1 ? 2 : 1;
        return;
    }
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    Init(left, L, mid);
    Init(right, mid+1, R);
    PushUp(idx);
}
void Update(int idx, int L, int R, int l, int r)
{
    if (l <= L && R <= r && Type[idx] == 1)
        return;
    if (L == R)
    {
        Tsum[idx] = sqrt(Tsum[idx]);
        Type[idx] = Tsum[idx] > 1 ? 2 : 1;
        return;
    }
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    if (l <= mid)
        Update(left, L, mid, l, r);
    if (mid < r)
        Update(right, mid+1, R, l, r);
    PushUp(idx);
}
long long Query(int idx, int L, int R, int l, int r)
{
    if (l <= L && R <= r)
        return Tsum[idx];
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    long long res = 0;
    if (l <= mid)
        res += Query(left, L, mid, l, r);
    if (mid < r)
        res += Query(right, mid+1, R, l, r);
    return res;
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    for (int cas = 1; scanf("%d", &N) != EOF; cas++)
    {
        for (int i = 1; i <= N; i++)
            scanf("%I64d", &E[i]);
        scanf("%d", &M);
        Init(1, 1, N);
        printf("Case #%d:\n", cas);
        for (int i = 1; i <= M; i++)
        {
            scanf("%d%d%d", &T, &X, &Y);
            if (X > Y)
                swap(X, Y);
            if (T)
                printf("%I64d\n", Query(1, 1, N, X, Y));
            else
                Update(1, 1, N, X, Y);
        }
        printf("\n");
    }
    return 0;
}
