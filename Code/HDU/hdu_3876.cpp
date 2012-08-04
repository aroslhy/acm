#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 50000+5, MAXM = 200000+5, MAXP = 1000000+5;
const double eps = 1e-8;
int T;
double a, b, c;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf%lf%lf", &a, &b, &c);
        double delta = b*b-4*a*c;
        if (fabs(delta) < eps)
        {
            double x = -b/(2*a);
            printf("%.2lf\n", x);
        }
        else if (delta > eps)
        {
            double x1 = (-b+sqrt(delta))/(2*a);
            double x2 = (-b-sqrt(delta))/(2*a);
            if (x1-x2 > eps)
                swap(x1, x2);
            printf("%.2lf %.2lf\n", x1, x2);
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
