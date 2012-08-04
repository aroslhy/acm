#include<cstdio>
#include<cmath>
using namespace std;
double n, p, k;
int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (scanf("%lf%lf", &n, &p) != EOF)
    {
        //printf("%lf %lf ", n, p);
        printf("%.0lf\n", pow(p, 1/n));
    }
    return 0;
}
