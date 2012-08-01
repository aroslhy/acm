#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 50000+5, MAXM = 10000+5;
int T, n, m;
int tp, a, b, c;
char ler[MAXN], ch[5];
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
void Update(int idx, int L, int R, int m, int c)
{
    int left = (idx<<1), right = (idx<<1)^1;
    if (L == m && R == m)
        Tr[idx] += c;
    else
    {
        int mid = ((L+R)>>1);
        if (m <= mid)
            Update(left, L, mid, m, c);
        else
            Update(right, mid+1, R, m, c);
        Tr[idx] = Tr[left]+Tr[right];
    }
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
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d%s", &n, &m, ler);
        Init(1, 1, n-2);
        int S = 2, P = 3;
        for (int i = 0; i < n; i++)
        {
            S = (S*3)%27+((ler[i] == 'b') ? 1 : 0);
            if (S == P)
                Update(1, 1, n-2, i-1, 1);
        }
        printf("Case %d:\n", cas);
        while (m--)
        {
            scanf("%d", &tp);
            if (!tp)
            {
                scanf("%d%d", &a, &b);
                if (b-a > 1)
                {
                    int q = Query(1, 1, n-2, a+1, b-1);
                    printf("%d\n", q);
                }
                else
                    printf("0\n");
            }
            else
            {
                scanf("%d%s", &c, ch);
                if (ch[0] == 'w' && ler[c] == 'b')
                {
                    if (ler[c-1] == 'w' && ler[c+1] == 'w')
                        Update(1, 1, n-2, c, -1);
                    if (ler[c-2] == 'w' && ler[c-1] == 'b')
                        Update(1, 1, n-2, c-1, 1);
                    if (ler[c+1] == 'b' && ler[c+2] == 'w')
                        Update(1, 1, n-2, c+1, 1);
                }
                else if (ch[0] == 'b' && ler[c] == 'w')
                {
                    if (ler[c-1] == 'w' && ler[c+1] == 'w')
                        Update(1, 1, n-2, c, 1);
                    if (ler[c-2] == 'w' && ler[c-1] == 'b')
                        Update(1, 1, n-2, c-1, -1);
                    if (ler[c+1] == 'b' && ler[c+2] == 'w')
                        Update(1, 1, n-2, c+1, -1);
                }
                ler[c] = ch[0];
            }
        }
    }
    return 0;
}
