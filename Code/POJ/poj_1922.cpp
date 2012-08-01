#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5, MAXM = 75+5;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
int N;
double V, T;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &N) && N)
    {
        double ans = INF;
        for (int i = 1; i <= N; i++)
        {
            scanf("%lf%lf", &V, &T);
//            printf("%lf  ", 4.5/V*3600);
//            printf("[%lf,%lf]\n", T, T+4.5/V*3600);
            if (T+eps > 0)
                ans = min(ans, T+4.5/V*3600);
        }
        printf("%.0lf\n", ceil(ans-eps));
    }
    return 0;
}
