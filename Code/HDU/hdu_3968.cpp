#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 50000+5, MAXM = 200000+5, MAXP = 1000000+5;
const double eps = 1e-8, g = 9.80;
int T;
double X0, Y0, X1, Y1, t;
double calc(double a, double b, double c, double x)
{
    return (2*a*x+b)*sqrt(a*x*x+b*x+c)/(4*a)+(4*a*c-b*b)*log(fabs(2*a*x+b+2*sqrt(a)*sqrt(a*x*x+b*x+c)))/(8*sqrt(a*a*a));
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf%lf%lf%lf%lf", &X0, &Y0, &X1, &Y1, &t);
        if (t > eps)
        {
            double vx = (X1-X0)/t, vy = (Y1-Y0+g*t*t/2)/t;
            double ans = calc(g*g, -2*g*vy, vx*vx+vy*vy, t)-calc(g*g, -2*g*vy, vx*vx+vy*vy, 0);
            printf("%.3lf\n", ans);
        }
        else
            printf("Impossible.\n");
    }
    return 0;
}
