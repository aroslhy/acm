#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 20+5;
const int INF = 0x3f3f3f3f;
const double g = 9.8, eps = 1e-8;
double H, Vx, Vy, t, V1, V2, V3;
char kind[10];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%lf%s", &H, kind) != EOF)
    {
        if (kind[0] == 'R')
        {
            scanf("%lf%lf", &Vx, &Vy);
            double T = (Vy+sqrt(Vy*Vy+2*g*H))/g;
            double L = Vx*T;
            printf("%.3lf\n", L);
        }
        else if (kind[0] == 'Y')
        {
            scanf("%lf%lf%lf", &Vx, &Vy, &t);
            double T = (Vy+sqrt(Vy*Vy+2*g*H))/g;
            if (t+eps < T)
            {
                double L = Vx*t;
                double Vx2 = 2*Vx;
                double Vy2 = 2*(Vy-g*t);
                double H2 = H+Vy*t-g*t*t/2;
                double T2 = (Vy2+sqrt(Vy2*Vy2+2*g*H2))/g;
                L += Vx2*T2;
                printf("%.3lf\n", L);
            }
            else
            {
                double L = Vx*T;
                printf("%.3lf\n", L);
            }
        }
        else
        {
            scanf("%lf%lf%lf%lf%lf%lf", &Vx, &Vy, &t, &V1, &V2, &V3);
            double T = (Vy+sqrt(Vy*Vy+2*g*H))/g;
            if (t+eps < T)
            {
                double L1 = Vx*t+V1*(T-t);
                double L2 = Vx*t+V2*(T-t);
                double L3 = Vx*t+V3*(T-t);
                printf("%.3lf %.3lf %.3lf\n", L1, L2, L3);
            }
            else
            {
                double L = Vx*T;
                printf("%.3lf\n", L);
            }
        }
    }
    return 0;
}
