//2012-08-06 16:48:49	Accepted	1828	343MS	1148K	3714 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 20000+5, MAXM = 10000+5;
const int A = 10000, Len = 20000;
int N, x[MAXM], y[MAXM], r[MAXM];
int Tr[MAXN<<2], covl[MAXN<<2], covr[MAXN<<2], mark[MAXN<<2];
bool cmpx(const int a, const int b)
{
    return x[a] < x[b];
}
bool cmpy(const int a, const int b)
{
    return y[a] < y[b];
}
void Init(int idx, int L, int R)
{
    if (L == R)
    {
        Tr[idx] = 0;
        covl[idx] = covr[idx] = 0;
        mark[idx] = 0;
        return;
    }
    Tr[idx] = 0;
    covl[idx] = covr[idx] = 0;
    mark[idx] = 0;
}
void UpdateSon(int idx, int L, int R)
{
    int left = 2*idx, right = 2*idx+1;
    Tr[left] += mark[idx];
    covl[left] += mark[idx];
    covr[left] += mark[idx];
    mark[left] += mark[idx];
    Tr[right] += mark[idx];
    covl[right] += mark[idx];
    covr[right] += mark[idx];
    mark[right] += mark[idx];
    mark[idx] = 0;
}
void Update(int idx, int L, int R, int l, int r, int c)
{
    if (L == l && R == r)
    {
        Tr[idx] += c;
        covl[idx] += c;
        covr[idx] += c;
        mark[idx] += c;
        return;
    }
    if (mark[idx])
        UpdateSon(idx, L, R);
    int mid = (L+R)/2, left = 2*idx, right = 2*idx+1;
    if (r <= mid)
        Update(left, L, mid, l, r, c);
    else if (mid < l)
        Update(right, mid+1, R, l, r, c);
    else
    {
        Update(left, L, mid, l, mid, c);
        Update(right, mid+1, R, mid+1, r, c);
    }
    covl[idx] = covl[left];
    covr[idx] = covr[right];
}
int Query(int idx, int L, int R)
{
    if (Tr[idx] || L == R)
        return Tr[idx] ? 1 : 0;
    if (mark[idx])
        UpdateSon(idx, L, R);
    int mid = (L+R)/2, left = 2*idx, right = 2*idx+1;
    return Query(left, L, mid)+Query(right, mid+1, R)-(covr[left] && covl[right] ? 1 : 0);
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0, j; i < N; i++)
        {
            j = 2*i;
            scanf("%d%d", &x[j], &y[j]);
            x[j] += A; y[j] += A;
            r[j] = j;
            j = 2*i+1;
            scanf("%d%d", &x[j], &y[j]);
            x[j] += A; y[j] += A;
            r[j] = j;
        }
        int ans = 0;
        sort(r, r+2*N, cmpx);
//        Init(1, 0, Len-1);
        for (int i = 0; i < 2*N; )
        {
            bool flag = 1;
            for (; (flag || x[r[i]] == x[r[i-1]]) && i < 2*N; i++)
            {
                flag = 0;
                int k = r[i];
                if (!(k%2))
                    Update(1, 0, Len-1, y[k], y[k^1]-1, 1);
                else
                    Update(1, 0, Len-1, y[k^1], y[k]-1, -1);
    //            printf("[%d,%d) %d\n", y[k], y[k^1], Query(1, 0, Len-1));
            }
            if (i < 2*N)
                ans += (x[r[i]]-x[r[i-1]])*Query(1, 0, Len-1)*2;
    //        printf("%d\n", ans);
        }
        sort(r, r+2*N, cmpy);
//        Init(1, 0, Len-1);
        for (int i = 0; i < 2*N; )
        {
            bool flag = 1;
            for (; (flag || y[r[i]] == y[r[i-1]]) && i < 2*N; i++)
            {
                flag = 0;
                int k = r[i];
                if (!(k%2))
                    Update(1, 0, Len-1, x[k], x[k^1]-1, 1);
                else
                    Update(1, 0, Len-1, x[k^1], x[k]-1, -1);
    //            printf("[%d,%d) %d\n", x[k], x[k^1], Query(1, 0, Len-1));
            }
            if (i < 2*N)
                ans += (y[r[i]]-y[r[i-1]])*Query(1, 0, Len-1)*2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
