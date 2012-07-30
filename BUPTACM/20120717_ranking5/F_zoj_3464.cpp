#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5, MAXM = 20+5;
const int INF = 0x3f3f3f3f;
int RP, N, T, L, V[MAXN];
bool cmp(const int a, const int b)
{
    return a > b;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &RP);
    while (RP--)
    {
        scanf("%d%d%d", &N, &T, &L);
        for (int i = 0; i < N; i++)
            scanf("%d", &V[i]);
        sort(V, V+N, cmp);
        int l = 0;
        double t = 0;
        for (int i = 0; i < N; i++)
        {
            l += V[i]*T;
            t += T;
            if (l >= L)
            {
                t -= (double)(l-L)/V[i];
                break;
            }
        }
        if (l < L)
            printf("-1\n");
        else
            printf("%.2lf\n", t);
    }
    return 0;
}
