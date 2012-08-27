//2012-08-24 11:21:18	Accepted	4395	1187MS	476K	2062 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int A = 200000, M = 10000, MIN = -200000, MAX = 20000;
const int MAXN = 200+5, MAXM = MAX+A+5;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
int T, N, D, DM[MAXN];
bool d[MAXM];
double t;
int DTOI(double x)
{
    if (x > eps)
        return x*M+eps;
    else if (x < eps)
        return x*M-eps;
    else
        return 0;
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        memset(d, 0, sizeof(d));
        scanf("%lf%d", &t, &N);
        D = DTOI(t);
        for (int i = 1; i <= N; i++)
        {
            scanf("%lf", &t);
            DM[i] = DTOI(t);
        }
        sort(DM+1, DM+1+N);
        d[0+A] = 1;
        for (int i = 1; i <= N; i++)
        {
            if (DM[i] > 0)
            {
                for (int j = MAX; j >= MIN; j--)
                {
                    int x = j-DM[i];
                    if (MIN <= x && x <= MAX && d[x+A])
                        d[j+A] = 1;
                }
            }
            else if (DM[i] < 0)
            {
                for (int j = MIN; j <= MAX; j++)
                {
                    int x = j-DM[i];
                    if (MIN <= x && x <= MAX && d[x+A])
                        d[j+A] = 1;
                }
            }
        }
//        for (int i = MIN; i < MAX; i++)
//            if (d[i+A])
//                printf("%d\n", i);
        int ans1 = -INF, ans2 = INF;
        for (int i = D; i >= MIN; i--)
            if (d[i+A])
            {
                ans1 = i;
                break;
            }
        for (int i = D; i < MAX; i++)
            if (d[i+A])
            {
                ans2 = i;
                break;
            }
        int ans = ans2-D < D-ans1 ? ans2 : ans1;
        printf("%.4lf\n", ans*0.0001);
    }
    return 0;
}
