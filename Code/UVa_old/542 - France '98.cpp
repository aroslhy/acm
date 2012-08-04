#include<cstdio>
#include<cmath>
using namespace std;
char country[16][20];
double p[16][16], f[16][4+1];
double F(int x, int y)
{
    double &res = f[x][y];
    if (res) return res;
    int a = (int)pow(2.0, y-1);
    if (x%(2*a) < a)
    {
        for (int i = (x/a+1)*a; i < (x/a+2)*a; i++)
            res += p[x][i]*F(i, y-1);
        return res *= F(x, y-1);
    }
    else
    {
        for (int i = (x/a-1)*a; i < (x/a)*a; i++)
            res += p[x][i]*F(i, y-1);
        return res *= F(x, y-1);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	for (int i = 0; i < 16; i++)
        scanf("%s", country[i]), f[i][0] = 1;
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++)
            scanf("%lf", &p[i][j]), p[i][j] /= 100;
    for (int i = 0; i < 16; i++)
        printf("%-10s p=%.2lf%s\n", country[i], F(i, 4)*100, "%");
	return 0;
}
