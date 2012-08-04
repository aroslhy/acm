#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 1000+5, MAXM = 12*16+5;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
double S;
double r, l, h, V;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%lf", &S) != EOF)
    {
        r = sqrt(S/PI)/2;
        l = S/(PI*r)-r;
        h = sqrt(l*l-r*r);
        V = PI*r*r*h/3;
        printf("%.2lf\n%.2lf\n%.2lf\n", V, h, r);
    }
    return 0;
}
