#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int MAXN = 200000+5;
int N, Pos[MAXN], Val[MAXN];
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
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 1; i <= N; i++)
            scanf("%d%d", &Pos[i], &Val[i]);
        build(1, N, 1);
        for (int i = N; i >= 1; i--)
        {
            update(1, N, Pos[i], 1);
            ans[idx] = Val[i];
        }
        for (int i = 1; i <= N; i++)
        {
            if (i != 1)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
