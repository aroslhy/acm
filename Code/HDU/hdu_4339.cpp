//2012-08-03 12:49:34	Accepted	4339	2625MS	10408K	2726 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000000+5, MAXM = 100000+5, MAXP = 1000000+5;
int T, Len, Q, cmd, a, b;
int Tr[MAXN<<2];
char s[2][MAXN], c[10];
void Init(int idx, int L, int R)
{
    int left = (idx<<1), right = (idx<<1)^1;
    if (L == R)
    {
        Tr[idx] = s[0][L] == s[1][L] ? 1 : 0;
        return;
    }
    int mid = ((L+R)>>1);
    Init(left, L, mid);
    Init(right, mid+1, R);
    Tr[idx] = Tr[left]+((mid-L+1 == Tr[left]) ? Tr[right] : 0);
}
void Update(int idx, int L, int R, int x, int c)
{
    int left = (idx<<1), right = (idx<<1)^1;
    if (L == x && R == x)
    {
        Tr[idx] = c;
        return;
    }
    int mid = ((L+R)>>1);
    if (x <= mid)
        Update(left, L, mid, x, c);
    else
        Update(right, mid+1, R, x, c);
    Tr[idx] = Tr[left]+((mid-L+1 == Tr[left]) ? Tr[right] : 0);
}
int Query(int idx, int L, int R, int l, int r)
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
    {
        int ql = Query(left, L, mid, l, mid), qr = Query(right, mid+1, R, mid+1, r);
        return ql+((mid-l+1 == ql) ? qr : 0);
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%s%s", s[0], s[1]);
        Len = min(strlen(s[0]), strlen(s[1]));
        Init(1, 0, Len-1);
        printf("Case %d:\n", cas);
        scanf("%d", &Q);
        while (Q--)
        {
            scanf("%d", &cmd);
            if (cmd == 1)
            {
                scanf("%d%d%s", &a, &b, c);
                if (b < Len)
                {
                    if (s[0][b] == s[1][b])
                    {
                        s[a-1][b] = c[0];
                        if (s[0][b] != s[1][b])
                            Update(1, 0, Len-1, b, 0);
                    }
                    else
                    {
                        s[a-1][b] = c[0];
                        if (s[0][b] == s[1][b])
                            Update(1, 0, Len-1, b, 1);
                    }
                }
            }
            else
            {
                scanf("%d", &b);
                if (b < Len)
                {
                    int q = Query(1, 0, Len-1, b, Len-1);
                    printf("%d\n", q);
                }
                else
                    printf("0\n");
            }
        }
    }
    return 0;
}
