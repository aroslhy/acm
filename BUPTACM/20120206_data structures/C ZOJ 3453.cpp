#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
int n, m, life[MAXN], a[MAXN], b[MAXN], k;
int Mlife[MAXN<<2], up[MAXN<<2];
void Build(int idx, int l, int r)
{
    int mid = (l+r)>>1, left = idx<<1, right = (idx<<1)^1;
    if (l < r)
    {
        Build(left, l, mid);
        Build(right, mid+1, r);
    }
    if (l == r)
        Mlife[idx] = life[l];
    else
        Mlife[idx] = max(Mlife[left], Mlife[right]);
    up[idx] = 0;
}
int Find(int idx, int l, int r)
{
    int mid = (l+r)>>1, left = idx<<1, right = (idx<<1)^1;
    if (l == r)
        return l;
    if (up[idx])
    {
        Mlife[left] += up[idx];
        up[left] += up[idx];
        Mlife[right] += up[idx];
        up[right] += up[idx];
        up[idx] = 0;
    }
    if (Mlife[right] >= k)
        return Find(right, mid+1, r);
    else if (Mlife[left] >= k)
        return Find(left, l, mid);
    else
        return 0;
}
void Decrease(int idx, int l, int r, int p)
{
    int mid = (l+r)>>1, left = idx<<1, right = (idx<<1)^1;
    if (l < r)
    {
        if (up[idx])
        {
            Mlife[left] += up[idx];
            up[left] += up[idx];
            Mlife[right] += up[idx];
            up[right] += up[idx];
            up[idx] = 0;
        }
        if (l <= p && p <= mid)
            Decrease(left, l, mid, p);
        else
            Decrease(right, mid+1, r, p);
    }
    if (l == r)
        Mlife[idx] = 1;
    else
        Mlife[idx] = max(Mlife[left], Mlife[right]);
}
void Increase(int idx, int l, int r, int p, int q)
{
    int mid = (l+r)>>1, left = idx<<1, right = (idx<<1)^1;
    if (!(l == p && r == q))
    {
        if (up[idx])
        {
            Mlife[left] += up[idx];
            up[left] += up[idx];
            Mlife[right] += up[idx];
            up[right] += up[idx];
            up[idx] = 0;
        }
        if (q <= mid)
            Increase(left, l, mid, p, q);
        else if (mid < p)
            Increase(right, mid+1, r, p, q);
        else
        {
            Increase(left, l, mid, p, mid);
            Increase(right, mid+1, r, mid+1, q);
        }
    }
    if (l == p && r == q)
        Mlife[idx]++, up[idx]++;
    else
        Mlife[idx] = max(Mlife[left], Mlife[right]);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d%d%d", &life[i], &a[i], &b[i]);
        Build(1, 1, n);
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d", &k);
            int x = Find(1, 1, n);
            if (x)
            {
                Decrease(1, 1, n, x);
                Increase(1, 1, n, a[x], b[x]);
            }
            else
                Increase(1, 1, n, 1, n);
        }
        printf("%d\n", Mlife[1]);
    }
    return 0;
}
