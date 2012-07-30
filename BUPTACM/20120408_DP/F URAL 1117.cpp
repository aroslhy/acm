#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 31+5, MAXM = MAXN;
const int INF = 0x3f3f3f3f;
int d[MAXN];
int D(int x)
{
    if (x == 1)
        return 0;
    int rt = 1<<30;
    while (!(rt&x))
        rt = rt>>1;
    int lr = 0;
    while (!(rt&(1<<lr)))
        lr++;
    if (x == rt)
        return d[lr-1]+lr-1;
    else
        return d[lr-1]+((lr-1)<<1)+D(x^rt);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    memset(d, 0, sizeof(d));
    int a, b;
    scanf("%d%d", &a, &b);
    if (a > b) swap(a, b);
    int root = 1<<30;
    while (!(root&b))
        root = root>>1;
    int layer = 0;
    while (!(root&(1<<layer)))
        layer++;
    for (int i = 1; i <= layer; i++)
        d[i] = (d[i-1]+i-1)<<1;
    printf("%d\n", D(b)-D(a));
    return 0;
}
