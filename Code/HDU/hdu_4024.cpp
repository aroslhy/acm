//2012-08-29 16:08:03	Accepted	4024	15MS	236K	1413 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps = 1e-8, INF = 1e+9;
double X1, Y1, X2, Y2, Lx, Ly, vD, vB, L, T;
double t, a, b, c, x;
double solve(double a, double b, double c)
{
    double x1 = (-b-sqrt(pow(b, 2)-4*a*c))/(2*a), x2 = (-b+sqrt(pow(b, 2)-4*a*c))/(2*a), res = INF;
//    printf("a = %lf, b = %lf, c = %lf\nx1 = %.9lf, x2 = %.9lf\n", a, b, c, x1, x2);
    if (x1 > -eps)
        res = min(res, x1);
    if (x2 > -eps)
        res = min(res, x2);
    return res;
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf", &X1, &Y1, &X2, &Y2, &Lx, &Ly, &vD, &vB, &L))
    {
        if (!X1 && !Y1 && !X2 && !Y2 && !Lx && !Ly && !vD && !vB && !L)
            break;
        t = L/vB;
        a = pow(Lx, 2)+pow(Ly, 2)-pow(vD, 2);
        c = (X2-X1)*((X2-X1)-Lx*t)+(Y2-Y1)*((Y2-Y1)-Ly*t)+t*(Lx*(Lx*t-(X2-X1))+Ly*(Ly*t-(Y2-Y1)))-pow(L, 2);
        T = INF;
        b = 2*(Lx*(Lx*t-(X2-X1))+Ly*(Ly*t-(Y2-Y1))+L*vD);
        if (pow(b, 2)-4*a*c > -eps)
            T = min(T, solve(a, b, c));
        b = 2*(Lx*(Lx*t-(X2-X1))+Ly*(Ly*t-(Y2-Y1))-L*vD);
        if (pow(b, 2)-4*a*c > -eps)
            T = min(T, solve(a, b, c));
        T += L/vB;
        printf("%.3lf %.3lf\n", L, T);
    }
    return 0;
}
