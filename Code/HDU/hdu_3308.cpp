//2012-08-06 21:29:45	Accepted	3308	484MS	5752K	3143 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 10000+5;
int T, N, M, A, B, a[MAXN];
struct Node
{
    int ml, lml, rml, tol, tor;
} Tr[MAXN<<2];
char cmd[5];
void Init(int idx, int L, int R)
{
    if (L == R)
    {
        Tr[idx].ml = 1;
        Tr[idx].lml = 1;
        Tr[idx].rml = 1;
        Tr[idx].tol = a[L];
        Tr[idx].tor = a[R];
        return;
    }
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    Init(left, L, mid);
    Init(right, mid+1, R);
    Tr[idx].ml = max(Tr[left].ml, Tr[right].ml);
    if (Tr[left].tor < Tr[right].tol)
        Tr[idx].ml = max(Tr[idx].ml, Tr[left].rml+Tr[right].lml);
    Tr[idx].lml = Tr[left].lml;
    if (Tr[left].lml == mid-L+1 && Tr[left].tor < Tr[right].tol)
        Tr[idx].lml += Tr[right].lml;
    Tr[idx].rml = Tr[right].rml;
    if (Tr[right].rml == R-mid && Tr[left].tor < Tr[right].tol)
        Tr[idx].rml += Tr[left].rml;
    Tr[idx].tol = Tr[left].tol;
    Tr[idx].tor = Tr[right].tor;

}
void Update(int idx, int L, int R, int x, int c)
{
    if (L == x && R == x)
    {
        Tr[idx].tol = c;
        Tr[idx].tor = c;
        return;
    }
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    if (x <= mid)
        Update(left, L, mid, x, c);
    else
        Update(right, mid+1, R, x, c);
    Tr[idx].ml = max(Tr[left].ml, Tr[right].ml);
    if (Tr[left].tor < Tr[right].tol)
        Tr[idx].ml = max(Tr[idx].ml, Tr[left].rml+Tr[right].lml);
    Tr[idx].lml = Tr[left].lml;
    if (Tr[left].lml == mid-L+1 && Tr[left].tor < Tr[right].tol)
        Tr[idx].lml += Tr[right].lml;
    Tr[idx].rml = Tr[right].rml;
    if (Tr[right].rml == R-mid && Tr[left].tor < Tr[right].tol)
        Tr[idx].rml += Tr[left].rml;
    Tr[idx].tol = Tr[left].tol;
    Tr[idx].tor = Tr[right].tor;
}
int Query(int idx, int L, int R, int l, int r)
{
    if (L == l && R == r)
        return Tr[idx].ml;
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    if (r <= mid)
        return Query(left, L, mid, l, r);
    else if (mid < l)
        return Query(right, mid+1, R, l, r);
    else
    {
        int q = max(Query(left, L, mid, l, mid), Query(right, mid+1, R, mid+1, r));
        if (Tr[left].tor < Tr[right].tol)
            q = max(q, (Tr[left].rml < mid-l+1 ? Tr[left].rml : mid-l+1)+(Tr[right].lml < r-mid ? Tr[right].lml : r-mid));
        return q;
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++)
            scanf("%d", &a[i]);
        Init(1, 0, N-1);
//        for (int i = 0; i < N; i++)
//            for (int j = i; j < N; j++)
//                printf("[%d,%d]:%d\n", i, j, Query(1, 0, N-1, i, j));
        for (int i = 0; i < M; i++)
        {
            scanf("%s%d%d", cmd, &A, &B);
            if (cmd[0] == 'Q')
                printf("%d\n", Query(1, 0, N-1, A, B));
            else
                Update(1, 0, N-1, A, B);
        }
    }
    return 0;
}
