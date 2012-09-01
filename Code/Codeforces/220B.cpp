//Sep 1, 2012 6:14:56 AM 	bigoceanlhy 	220B - Little Elephant and Array 	GNU C++ 	Accepted 	200 ms 	8500 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 100000+5;
int N, M, a[MAXN], s[MAXN], t[MAXN], r[MAXN], ans[MAXN];
int Tr[MAXN<<2], mark[MAXN<<2];
vector<int> pos[MAXN];
bool cmp(const int a, const int b)
{
    return t[a] < t[b];
}
void PushDown(int idx)
{
    int left = idx<<1, right = (idx<<1)^1;
    Tr[left] += mark[idx];
    mark[left] += mark[idx];
    Tr[right] += mark[idx];
    mark[right] += mark[idx];
    mark[idx] = 0;
}
void Update(int idx, int L, int R, int l, int r, int c)
{
    if (l <= L && R <= r)
    {
        Tr[idx] += c;
        mark[idx] += c;
        return;
    }
    if (mark[idx])
        PushDown(idx);
    int mid = (L+R)>>1, left = idx<<1, right = (idx<<1)^1;
    if (l <= mid)
        Update(left, L, mid, l, r, c);
    if (mid < r)
        Update(right, mid+1, R, l, r, c);
}
int Query(int idx, int L, int R, int x)
{
    if (x == L & R == x)
        return Tr[idx];
    if (mark[idx])
        PushDown(idx);
    int mid = (L+R)>>1, left = idx<<1, right = (idx<<1)^1;
    if (x <= mid)
        return Query(left, L, mid, x);
    else
        return Query(right, mid+1, R, x);
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] <= N && !pos[a[i]].size())
            pos[a[i]].push_back(0);
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &s[i], &t[i]);
        r[i] = i;
    }
    sort(r, r+M, cmp);
    for (int i = 1, j = 0; i <= N && j < M; i++)
    {
        if (a[i] <= N)
        {
            pos[a[i]].push_back(i);
            if (pos[a[i]].size() > a[i])
                Update(1, 1, N, pos[a[i]][pos[a[i]].size()-a[i]-1]+1, pos[a[i]][pos[a[i]].size()-a[i]], 1);
            if (pos[a[i]].size() > a[i]+1)
                Update(1, 1, N, pos[a[i]][pos[a[i]].size()-a[i]-2]+1, pos[a[i]][pos[a[i]].size()-a[i]-1], -1);
        }
        for (; t[r[j]] == i && j < M; j++)
            ans[r[j]] = Query(1, 1, N, s[r[j]]);
    }
    for (int i = 0; i < M; i++)
        printf("%d\n", ans[i]);
    return 0;
}
