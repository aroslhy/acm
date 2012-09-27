#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 10000+5, MAXM = 20000+5;
const int ALL = 1<<3;
int T, N, Y[MAXN][2], clr[MAXN], X[MAXM], y[MAXM], r[MAXM];
int ID[1<<8];
int Tsum[ALL][MAXM<<2], Tcov[ALL][MAXM<<2];
char C[5];
map<int, int> mp;
bool cmp(const int a, const int b)
{
    return X[a] < X[b];
}
//void Build(int idx, int L, int R)
//{
//    for (int k = 1; k < ALL; k++)
//        Tsum[k][idx] = Tcov[k][idx] = 0;
//    if (R-L == 1)
//        return;
//    int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
//    Build(left, L, mid);
//    Build(right, mid, R);
//}
void Update(int tr, int idx, int L, int R, int l, int r, int c)
{
    int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
    if (l <= L && R <= r)
        Tcov[tr][idx] += c;
    else
    {
        if (l < mid)
            Update(tr, left, L, mid, l, r, c);
        if (mid < r)
            Update(tr, right, mid, R, l, r, c);
    }
    if (Tcov[tr][idx])
        Tsum[tr][idx] = y[R-1]-y[L-1];
    else if (R-L == 1)
        Tsum[tr][idx] = 0;
    else
        Tsum[tr][idx] = Tsum[tr][left]+Tsum[tr][right];
}
int main()
{
    ID['R'] = 1<<0;
    ID['G'] = 1<<1;
    ID['B'] = 1<<2;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        mp.clear();
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%s%d%d%d%d", C, &X[i<<1], &Y[i][0], &X[i<<1|1], &Y[i][1]);
            clr[i] = ID[C[0]];
            y[i<<1] = Y[i][0];
            y[i<<1|1] = Y[i][1];
            r[i<<1] = i<<1;
            r[i<<1|1] = i<<1|1;
        }
        int n = N<<1;
        sort(r, r+n, cmp);
        sort(y, y+n);
        for (int i = 1; i <= n; i++)
            mp[y[i-1]] = i;
//        Build(1, 1, n);
        long long area[ALL] = {};
        for (int i = 0; i < n; i++)
            for (int k = 1; k < ALL; k++)
            {
                if (k&clr[r[i]>>1])
                    Update(k, 1, 1, n, mp[Y[r[i]>>1][0]], mp[Y[r[i]>>1][1]], (r[i]&1 ? -1 : 1));
                if (i+1 < n)
                    area[k] += (long long)Tsum[k][1]*(X[r[i+1]]-X[r[i]]);
            }
        printf("Case %d:\n", cas);
        printf("%I64d\n", area[7]-area[6]);
        printf("%I64d\n", area[7]-area[5]);
        printf("%I64d\n", area[7]-area[3]);
        printf("%I64d\n", area[5]+area[6]-area[4]-area[7]);
        printf("%I64d\n", area[3]+area[6]-area[2]-area[7]);
        printf("%I64d\n", area[3]+area[5]-area[1]-area[7]);
        printf("%I64d\n", area[1]+area[2]+area[4]-area[3]-area[5]-area[6]+area[7]);
    }
    return 0;
}
