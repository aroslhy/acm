//2012-08-29 09:32:16 	Accepted 	3633 	C++ 	1120 	17708 	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 500000+5, MAXM = 50000+5;
const int INF = 0x3f3f3f3f;
int N, M, u, v, tip[MAXN], seq[MAXN];
int Tr[MAXN<<2];
map<int, int> mp;
void Build(int idx, int L, int R)
{
    if (L == R)
    {
        Tr[idx] = seq[R];
        return;
    }
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    Build(left, L, mid);
    Build(right, mid+1, R);
    Tr[idx] = max(Tr[left], Tr[right]);
}
int Query(int idx, int L, int R, int l, int r)
{
    if (l <= L && R <= r)
        return Tr[idx];
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    int res = 0;
    if (l <= mid)
        res = max(res, Query(left, L, mid, l, r));
    if (mid < r)
        res = max(res, Query(right, mid+1, R, l, r));
    return res;
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    while (scanf("%d", &N) != EOF)
    {
        mp.clear();
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &tip[i]);
            seq[i] = mp[tip[i]];
            mp[tip[i]] = i;
        }
        Build(1, 1, N);
        scanf("%d", &M);
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d", &u, &v);
            int q = Query(1, 1, N, u, v);
            if (q < u)
                printf("OK\n");
            else
                printf("%d\n", tip[q]);
        }
        printf("\n");
    }
    return 0;
}
