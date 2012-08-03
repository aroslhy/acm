#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100000+5, MAXM = 640000+5;
const long long INF = 0x7fffffffffffffffLL;
int T, n, rx[MAXN], ry[MAXN];
long long X, Y, dxl[MAXN], dxr[MAXN], dyu[MAXN], dyd[MAXN];
struct Node
{
    long long x, y;
} P[MAXN];
bool cmpx(const int a, const int b)
{
    return P[a].x < P[b].x;
}
bool cmpy(const int a, const int b)
{
    return P[a].y < P[b].y;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%I64d%I64d", &X, &Y);
//            cin>>X>>Y;
            P[i].x = X+Y; P[i].y = X-Y;
            rx[i] = i; ry[i] = i;
        }
        sort(rx+1, rx+n+1, cmpx);
        sort(ry+1, ry+n+1, cmpy);
        dxl[rx[1]] = 0; dyd[ry[1]] = 0;
        dxr[rx[n]] = 0; dyu[ry[n]] = 0;
        for (int i = 2, j = n-1; i <= n; i++, j--)
        {
            dxl[rx[i]] = dxl[rx[i-1]]+(i-1)*(P[rx[i]].x-P[rx[i-1]].x);
            dyd[ry[i]] = dyd[ry[i-1]]+(i-1)*(P[ry[i]].y-P[ry[i-1]].y);
            dxr[rx[j]] = dxr[rx[j+1]]+(n-j)*(P[rx[j+1]].x-P[rx[j]].x);
            dyu[ry[j]] = dyu[ry[j+1]]+(n-j)*(P[ry[j+1]].y-P[ry[j]].y);
        }
        long long ans = INF;
        for (int i = 1; i <= n; i++)
        {
            ans = min(ans, (dxl[i]+dxr[i]+dyd[i]+dyu[i])/2);
//            printf("%d,%d:%lld\n", P[i].x, P[i].y, dxl[i]+dxr[i]+dyd[i]+dyu[i]);
        }
        printf("%I64d\n", ans);
//        cout<<ans<<endl;
    }
    return 0;
}
