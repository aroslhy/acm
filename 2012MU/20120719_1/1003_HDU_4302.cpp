#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 1000*2+5;
const int INF = 0x3f3f3f3f;
int T, L, n, cmd, x;
int Tr[MAXN<<2];
void Init(int idx, int L, int R)
{
    Tr[idx] = 0;
    int left = (idx<<1), right = (idx<<1)^1;
    if (L < R)
    {
        int mid = ((L+R)>>1);
        Init(left, L, mid);
        Init(right, mid+1, R);
    }
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
int QueryA(int idx, int L, int R, int l, int r)
{
    int left = (idx<<1), right = (idx<<1)^1;
    if (L == R)
        return Tr[idx] ? R : -1;
    int mid = ((L+R)>>1);
    if (r <= mid)
    {
        if (!Tr[left]) return -1;
        return QueryA(left, L, mid, l, r);
    }
    else if (mid < l)
    {
        if (!Tr[right]) return -1;
        return QueryA(right, mid+1, R, l, r);
    }
    else
    {
        if (Tr[right])
        {
            int p = QueryA(right, mid+1, R, mid+1, r);
            if (p+1) return p;
        }
        if (Tr[left])
        {
            int p = QueryA(left, L, mid, l, mid);
            if (p+1) return p;
        }
        return -1;
    }
}
int QueryB(int idx, int L, int R, int l, int r)
{
    int left = (idx<<1), right = (idx<<1)^1;
    if (L == R)
        return Tr[idx] ? R : -1;
    int mid = ((L+R)>>1);
    if (r <= mid)
    {
        if (!Tr[left]) return -1;
        return QueryB(left, L, mid, l, r);
    }
    else if (mid < l)
    {
        if (!Tr[right]) return -1;
        return QueryB(right, mid+1, R, l, r);
    }
    else
    {
        if (Tr[left])
        {
            int p = QueryB(left, L, mid, l, mid);
            if (p+1) return p;
        }
        if (Tr[right])
        {
            int p = QueryB(right, mid+1, R, mid+1, r);
            if (p+1) return p;
        }
        return -1;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d", &L, &n);
        Init(1, 0, L);
        int cur = 0, dir = 0, ans = 0;
        while (n--)
        {
            scanf("%d", &cmd);
            if (cmd)
            {
                int a = QueryA(1, 0, L, 0, cur), b = QueryB(1, 0, L, cur, L);
                if (a+1 && b+1)
                {
                    int c;
                    if (cur-a < b-cur)
                        c = a, dir = -1;
                    else if (cur-a > b-cur)
                        c = b, dir = 1;
                    else
                        c = (dir < 0) ? a : b;
                    Update(1, 0, L, c, -1);
                    ans += fabs(c-cur);
                    cur = c;
                }
                else if (a+1)
                {
                    Update(1, 0, L, a, -1);
                    ans += cur-a;
                    cur = a;
                    dir = -1;
                }
                else if (b+1)
                {
                    Update(1, 0, L, b, -1);
                    ans += b-cur;
                    cur = b;
                    dir = 1;
                }
            }
            else
            {
                scanf("%d", &x);
                Update(1, 0, L, x, 1);
            }
        }
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}
