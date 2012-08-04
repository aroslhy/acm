#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 100000+5;
int N, T, O;
int Tr[MAXN<<2];
bool mark[MAXN<<2];
void Init(int idx, int L, int R)
{
    Tr[idx] = (1<<0);
    mark[idx] = 0;
    int left = (idx<<1), right = (idx<<1)^1;
    if (L < R)
    {
        int mid = ((L+R)>>1);
        Init(left, L, mid);
        Init(right, mid+1, R);
    }
}
void UpdateSon(int idx)
{
    int left = (idx<<1), right = (idx<<1)^1;
    Tr[left] = Tr[idx];
    mark[left] = 1;
    Tr[right] = Tr[idx];
    mark[right] = 1;
    mark[idx] = 0;
}
void Update(int idx, int L, int R, int l, int r, int c)
{
    if (L < R && mark[idx]) UpdateSon(idx);
    int left = (idx<<1), right = (idx<<1)^1;
    if (L == l && R == r)
    {
        Tr[idx] = (1<<(c-1));
        mark[idx] = 1;
    }
    else
    {
        int mid = ((L+R)>>1);
        if (r <= mid)
            Update(left, L, mid, l, r, c);
        else if (mid < l)
            Update(right, mid+1, R, l, r, c);
        else
        {
            Update(left, L, mid, l, mid, c);
            Update(right, mid+1, R, mid+1, r, c);
        }
        Tr[idx] = Tr[left]|Tr[right];
    }
}
int Query(int idx, int L, int R, int l, int r)
{
    if (L < R && mark[idx]) UpdateSon(idx);
    int left = (idx<<1), right = (idx<<1)^1;
    if (L == l && R == r)
        return Tr[idx];
    int mid = ((L+R)>>1);
    if (r <= mid)
        return Query(left, L, mid, l, r);
    else if (mid < l)
        return Query(right, mid+1, R, l, r);
    else
        return Query(left, L, mid, l, mid)|Query(right, mid+1, R, mid+1, r);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &N, &T, &O);
    Init(1, 1, N);
    while (O--)
    {
        char op[5];
        scanf("%s", op);
        if (op[0] == 'C')
        {
            int A, B, C;
            scanf("%d%d%d", &A, &B, &C);
            if (A > B) swap(A, B);
            Update(1, 1, N, A, B, C);
        }
        else if (op[0] == 'P')
        {
            int A, B;
            scanf("%d%d", &A, &B);
            if (A > B) swap(A, B);
            int m = Query(1, 1, N, A, B);
            int cnt = 0;
            for (int i = 0; i < T; i++)
                if ((1<<i)&m) cnt++;
            printf("%d\n", cnt);
        }
    }
    return 0;
}
