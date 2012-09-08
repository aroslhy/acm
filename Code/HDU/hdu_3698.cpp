//2012-09-08 18:54:52	Accepted	3698	1609MS	4324K	2521 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5, MAXM = 5000+5;
const int INF = 0x3f3f3f3f;
int N, M, T[MAXN][MAXM], F[MAXN][MAXM];
int d[2][MAXM];
int Tr[MAXM<<2], add[MAXM<<2];
void PushDown(int idx)
{
    int left = idx<<1, right = (idx<<1)^1;
    add[left] = min(add[left], add[idx]);
    Tr[left] = min(Tr[left], add[left]);
    add[right] = min(add[right], add[idx]);
    Tr[right] = min(Tr[right], add[right]);
    add[idx] = INF;
}
void Build(int idx, int L, int R)
{
    Tr[idx] = add[idx] = INF;
    if (L == R)
        return;
    int mid = (L+R)>>1, left = idx<<1, right = (idx<<1)^1;
    Build(left, L, mid);
    Build(right, mid+1, R);
}
void Update(int idx, int L, int R, int l, int r, int c)
{
    if (l <= L && R <= r)
    {
        add[idx] = min(add[idx], c);
        Tr[idx] = min(Tr[idx], add[idx]);
        return;
    }
    if (add[idx] < INF)
        PushDown(idx);
    int mid = (L+R)>>1, left = idx<<1, right = (idx<<1)^1;
    if (l <= mid)
        Update(left, L, mid, l, r, c);
    if (mid < r)
        Update(right, mid+1, R, l, r, c);
    Tr[idx] = min(Tr[left], Tr[right]);
}
int Query(int idx, int L, int R, int l, int r)
{
    if (l <= L && R <= r)
        return Tr[idx];
    if (add[idx] < INF)
        PushDown(idx);
    int mid = (L+R)>>1, left = idx<<1, right = (idx<<1)^1, res = INF;
    if (l <= mid)
        res = min(res, Query(left, L, mid, l, r));
    if (mid < r)
        res = min(res, Query(right, mid+1, R, l, r));
    return res;
}
int main()
{
    while (scanf("%d%d", &N, &M))
    {
        if (!N && !M)
            break;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                scanf("%d", &T[i][j]);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                scanf("%d", &F[i][j]);
        int s = 0, t = 1;
        for (int i = 1; i <= M; i++)
            d[t][i] = T[1][i];
        for (int i = 2; i <= N; i++)
        {
            swap(s, t);
            Build(1, 1, M);
            for (int j = 1; j <= M; j++)
                Update(1, 1, M, j-F[i-1][j], j+F[i-1][j], d[s][j]);
            for (int j = 1; j <= M; j++)
                d[t][j] = T[i][j]+Query(1, 1, M, j-F[i][j], j+F[i][j]);
        }
        int ans = INF;
        for (int i = 1; i <= M; i++)
            ans = min(ans, d[t][i]);
        printf("%d\n", ans);
    }
    return 0;
}
