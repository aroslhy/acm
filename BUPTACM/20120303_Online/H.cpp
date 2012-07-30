#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 3000+5, MAXM = 10000;
const int INF = 0x3f3f3f3f;
int T;
int n, a[MAXN];
int find(int l, int r, int x)
{
    if (l == r)
    {
        if (x > a[l])
            return l+1;
        else
            return l;
    }
    int mid = (l+r)>>1;
    if (x > a[mid])
        return find(mid+1, r, x);
    else
        return find(l, mid, x);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n-1; j++)
            {
                int m = find(j+1, n-1, a[i]+a[j]);
                ans += m-j-1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
