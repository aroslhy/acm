#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int MAXN = 8000+5;
int N, Pos[MAXN];
int T[MAXN<<2], ans[MAXN], idx;
void build(int l, int r, int x)
{
    T[x] = r-l+1;
    if (l < r)
    {
        int mid = (l+r)>>1;
        build(l, mid, x<<1);
        build(mid+1, r, (x<<1)^1);
    }
}
void update(int l, int r, int p, int x)
{
    T[x]--;
    if (l == r)
    {
        idx = l;
        return;
    }
    int mid = (l+r)>>1;
    if (T[x<<1] > p)
        update(l, mid, p, x<<1);
    else
        update(mid+1, r, p-T[x<<1], (x<<1)^1);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    for (int i = 2; i <= N; i++)
        scanf("%d", &Pos[i]);
    Pos[1] = 0;
    build(1, N, 1);
    for (int i = N; i >= 1; i--)
    {
        update(1, N, Pos[i], 1);
        ans[i] = idx;
    }
    for (int i = 1; i <= N; i++)
        printf("%d\n", ans[i]);
    return 0;
}
