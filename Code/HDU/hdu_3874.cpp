#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 50000+5, MAXM = 200000+5, MAXP = 1000000+5;
int T, N, M, val[MAXN], A[MAXM], B[MAXM], r[MAXM], last[MAXP];
long long Tr[MAXN<<2], ans[MAXM];
bool cmp(const int a, const int b)
{
    return B[a] < B[b];
}
void Init(int idx, int L, int R)
{
    int left = (idx<<1), right = (idx<<1)^1;
    if (L < R)
    {
        int mid = ((L+R)>>1);
        Init(left, L, mid);
        Init(right, mid+1, R);
    }
    else
        Tr[idx] = 0;
}
void Update(int idx, int L, int R, int x, int c)
{
    int left = (idx<<1), right = (idx<<1)^1;
    if (L == x && R == x)
        Tr[idx] += c;
    else
    {
        int mid = ((L+R)>>1);
        if (x <= mid)
            Update(left, L, mid, x, c);
        else
            Update(right, mid+1, R, x, c);
        Tr[idx] = Tr[left]+Tr[right];
    }
}
long long Query(int idx, int L, int R, int l, int r)
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
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d", &val[i]);
        scanf("%d", &M);
        for (int i = 1; i <= M; i++)
        {
            scanf("%d%d", &A[i], &B[i]);
            r[i] = i;
        }
        sort(r+1, r+1+M, cmp);
        int cur = 1;
        Init(1, 1, N);
        memset(last, 0, sizeof(last));
        for (int i = 1; i <= N && cur <= M; i++)
        {
            if (last[val[i]])
                Update(1, 1, N, last[val[i]], -val[i]);
            Update(1, 1, N, i, val[i]);
            last[val[i]] = i;
            while (i == B[r[cur]] && cur <= M)
            {
                ans[r[cur]] = Query(1, 1, N, A[r[cur]], B[r[cur]]);
                cur++;
            }
        }
        for (int i = 1; i <= M; i++)
            printf("%lld\n", ans[i]);
    }
    return 0;
}
