//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000000+5, MAXM = 100000+5, MAXP = 1000000+5;
int T, Len, Q, cmd, a, b, ans;
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
    Tr[idx] = Tr[left]+Tr[right];
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
    Tr[idx] = Tr[left]+Tr[right];
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
        return Query(left, L, mid, l, mid)+Query(right, mid+1, R, mid+1, r);
}
void find(int s, int x, int y)
{
    int mid = (x+y)>>1;
    int q = Query(1, 0, Len-1, s, mid);
    if (mid-s+1 == q)
        ans = max(ans, q);
    if (x < y)
    {
        if (q < mid-s+1)
            find(s, x, mid);
        else
            find(s, mid+1, y);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
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
            else
            {
                scanf("%d", &b);
                ans = 0;
                if (b < Len)
                {
                    find(b, b, Len-1);
                    printf("%d\n", ans);
                }
                else
                    printf("0\n");
            }
        }
    }
    return 0;
}
