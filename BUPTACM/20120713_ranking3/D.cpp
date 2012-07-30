#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 20000+5, MAXM = 10000+5;
int T, N, K, A[MAXN];
int Tr[MAXN<<2];
void Init(int idx, int L, int R)
{
    int left = (idx<<1), right = (idx<<1)^1;
    if (L < R)
    {
        int mid = ((L+R)>>1);
        Init(left, L, mid);
        Init(right, mid+1, R);
        Tr[idx] = Tr[left]&Tr[right];
    }
    else
        Tr[idx] = A[L];
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
        return Query(left, L, mid, l, mid)&Query(right, mid+1, R, mid+1, r);
}
int main()
{
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &N, &K);
        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);
//        int x = 0x7ffffff;
//        for (int i = 0; i < N; i++)
//            x &= A[i];
//        printf("%d\n", x);
        Init(1, 0, N-1);
        for (int i = 0; i < N; i++)
        {
            int k = (K < N/2) ? K : N/2;
            int a = i-k, b = i+k;
            int y;
            if (0 <= a && b < N)
            {
                y = Query(1, 0, N-1, a, b);
            }
            else if (b >= N)
            {
                y = Query(1, 0, N-1, a, N-1)&Query(1, 0, N-1, 0, b%N);
            }
            else if (a < 0)
            {
                y = Query(1, 0, N-1, 0, b)&Query(1, 0, N-1, a+N, N-1);
            }
            printf("%d", y);
            printf((i != N-1) ? " " : "\n");
        }
    }
    return 0;
}
