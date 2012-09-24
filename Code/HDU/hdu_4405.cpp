//2012-09-22 17:18:09	Accepted	4405	31MS	1316K	784 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100006+5, MAXM = 1000+5;
int N, M, X, Y, fly[MAXN];
double d[MAXN];
int main()
{
    while (scanf("%d%d", &N, &M))
    {
        if (!N && !M)
            break;
        memset(fly, 0, sizeof(fly));
        for (int i = 1; i <= M; i++)
        {
            scanf("%d%d", &X, &Y);
            fly[X] = Y;
        }
        for (int i = 0; i < 6; i++)
            d[N+i] = 0;
        double sum = 0;
        for (int i = N-1; i >= 0; i--)
        {
            if (fly[i])
                d[i] = d[fly[i]];
            else
                d[i] = (sum+6)/6;
            sum = sum+d[i]-d[i+6];
        }
        printf("%.4lf\n", d[0]);
    }
    return 0;
}
