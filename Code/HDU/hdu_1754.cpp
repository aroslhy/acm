//2012-08-06 20:20:26	Accepted	1754	1093MS	3060K	1651 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 200000+5, MAXM = 10000+5;
int N, M, A, B, scr[MAXN];
int Tr[MAXN<<2];
char cmd[5];
void Init(int idx, int L, int R)
{
    if (L == R)
    {
        Tr[idx] = scr[L];
        return;
    }
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    Init(left, L, mid);
    Init(right, mid+1, R);
    Tr[idx] = max(Tr[left], Tr[right]);
}
void Update(int idx, int L, int R, int x, int c)
{
    if (L == x && R == x)
    {
        Tr[idx] = c;
        return;
    }
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    if (x <= mid)
        Update(left, L, mid, x, c);
    else
        Update(right, mid+1, R, x, c);
    Tr[idx] = max(Tr[left], Tr[right]);
}
int Query(int idx, int L, int R, int l, int r)
{
    if (L == l && R == r)
        return Tr[idx];
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    if (r <= mid)
        return Query(left, L, mid, l, r);
    else if (mid < l)
        return Query(right, mid+1, R, l, r);
    else
        return max(Query(left, L, mid, l, mid), Query(right, mid+1, R, mid+1, r));
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &N, &M) != EOF)
    {
        for (int i = 1; i <= N; i++)
            scanf("%d", &scr[i]);
        Init(1, 1, N);
        for (int i = 1; i <= M; i++)
        {
            scanf("%s%d%d", cmd, &A, &B);
            if (cmd[0] == 'Q')
                printf("%d\n", Query(1, 1, N, A, B));
            else
                Update(1, 1, N, A, B);
        }
    }
    return 0;
}
