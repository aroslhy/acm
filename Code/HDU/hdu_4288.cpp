//2012-09-17 22:25:47	Accepted	4288	1640MS	16496K	1823 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 100000+5;
int N, num[MAXN], r[MAXN];
int Tcnt[MAXN<<2];
long long Tsum[5][MAXN<<2];
char ope[MAXN][10];
map<int, int> mp;
bool cmp(const int a, const int b)
{
    return num[a] < num[b];
}
void Build(int idx, int L, int R)
{
    for (int i = 0; i < 5; i++)
        Tsum[i][idx] = 0;
    Tcnt[idx] = 0;
    if (L == R)
        return;
    int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
    Build(left, L, mid);
    Build(right, mid+1, R);
}
void Update(int idx, int L, int R, int x, int c)
{
    if (x <= L && R <= x)
    {
        Tsum[0][idx] += c*num[r[x]];
        Tcnt[idx] += c;
        return;
    }
    int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
    if (x <= mid)
        Update(left, L, mid, x, c);
    else
        Update(right, mid+1, R, x, c);
    for (int i = 0; i < 5; i++)
        Tsum[i][idx] = Tsum[i][left]+Tsum[((i-Tcnt[left])%5+5)%5][right];
    Tcnt[idx] = Tcnt[left]+Tcnt[right];
}
int main()
{
    while (scanf("%d", &N) != EOF)
    {
        mp.clear();
        int n = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%s", ope[i]);
            if (ope[i][0] != 's')
            {
                scanf("%d", &num[i]);
                if (ope[i][0] == 'a')
                    r[n++] = i;
            }
        }
        sort(r, r+n, cmp);
        for (int i = 0; i < n; i++)
            mp[num[r[i]]] = i;
        Build(1, 0, n-1);
        for (int i = 0; i < N; i++)
        {
            if (ope[i][0] != 's')
                Update(1, 0, n-1, mp[num[i]], (ope[i][0] == 'a') ? 1 : -1);
            else
                printf("%I64d\n", Tsum[2][1]);
        }
    }
    return 0;
}
