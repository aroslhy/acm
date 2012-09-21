//2012-09-21 18:33:06	Accepted	4089	656MS	22948K	1109 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2000+5;
int N, M, K;
double p1, p2, p3, p4, a, powa[MAXN], b[MAXN], d[MAXN][MAXN];
int main()
{
    while (scanf("%d%d%d", &N, &M, &K) != EOF)
    {
        scanf("%lf%lf%lf%lf", &p1, &p2, &p3, &p4);
        if (p4 == 0)
        {
            printf("0.00000\n");
            continue;
        }
        a = p2/(1-p1);
        powa[0] = 1;
        for (int i = 1; i <= N; i++)
            powa[i] = powa[i-1]*a;
        b[1] = p4/(1-p1);
        for (int i = 1; i <= N; i++)
        {
            for (int j = 2; j <= K && j <= i; j++)
                b[j] = (p4+p3*d[i-1][j-1])/(1-p1);
            for (int j = K+1; j <= i; j++)
                b[j] = p3*d[i-1][j-1]/(1-p1);
            d[i][1] = b[1];
            for (int j = 2; j <= i; j++)
                d[i][1] += powa[i+1-j]*b[j];
            d[i][1] /= 1-powa[i];
            for (int j = 2; j <= i; j++)
                d[i][j] = a*d[i][j-1]+b[j];
        }
        printf("%.5lf\n", d[N][M]);
    }
    return 0;
}
