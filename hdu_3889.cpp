#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5, MAXM = 200000+5;
int p, n;
double x[2][MAXN], SDp, SDs, SE, Ms, Mp, Mx, My, SDx, SDy, r, a, b;
void read(int l)
{
    for (int i = 1; i <= n; i++)
        scanf("%lf", &x[l][i]);
}
double mean(int l)
{
    double res = 0;
    for (int i = 1; i <= n; i++)
        res += x[l][i];
    res /= n;
    return res;
}
double standard_deviation(int l, char c, double M)
{
    double res = 0;
    for (int i = 1; i <= n; i++)
        res += (x[l][i]-M)*(x[l][i]-M);
    res = (c == 'p') ? sqrt(res/n) : sqrt(res/(n-1));
    return res;
}
double correlation()
{
    Mx = mean(0);
    My = mean(1);
    SDx = standard_deviation(0, 'p', Mx);
    SDy = standard_deviation(1, 'p', My);
    double res = 0;
    for (int i = 1; i <= n; i++)
        res += (x[0][i]-Mx)*(x[1][i]-My);
    res = res/SDx/SDy/n;
    return res;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &p, &n) != EOF)
    {
        if (p == 1)
        {
            read(0);
            Mp = mean(0);
            SDp = standard_deviation(0, 'p', Mp);
            for (int i = 1; i <= n; i++)
            {
                printf("%.2lf", (x[0][i]-Mp)/SDp);
                printf((i < n) ? " " : "\n");
            }
        }
        else if (p == 2)
        {
            scanf("%lf", &Mp);
            read(0);
            Ms = mean(0);
            SDs = standard_deviation(0, 's', Ms);
            SE = SDs/sqrt((double)n);
            printf("%.2lf\n", (Ms-Mp)/SE);
        }
        else if (p == 3)
        {
            read(0); read(1);
            printf("%.2lf\n", correlation());
        }
        else
        {
            read(0); read(1);
            r = correlation();
            b = r*SDy/SDx;
            a = My-b*Mx;
            printf("%.2lf %.2lf\n", a, b);
        }
    }
    return 0;
}
