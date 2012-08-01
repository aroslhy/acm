/*
ID: bigocea1
PROG: ratios
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 3, MAXM = 100+5;
int s, X[MAXN], A[MAXN][MAXN], B[MAXN];
int N = 3;
inline int mod(int x, int y)
{
    return (x%y+y)%y;
}
int gcd(int x, int y)
{
    return y ? gcd(y, x%y) : x;
}
int lcm(int x, int y)
{
    return x/gcd(x, y)*y;
}
void showmat() //打印伴随矩阵
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", A[i][j]);
        printf("%2d\n", B[i]);
    }
    printf("\n");
}
void gauss() //高斯消元
{
    for (int i = 0; i < N; i++)
    {
        int tp = i;
        for (int j = i+1; j < N; j++)
            if (A[j][i] > A[tp][i])
                tp = j;
        if (tp != i)
        {
            for (int j = 0; j < N; j++)
                swap(A[tp][j], A[i][j]);
            swap(B[tp], B[i]);
        }
//        showmat();
        if (A[i][i])
            for (int j = i+1; j < N; j++) if (A[j][i])
            {
                int g = gcd(A[i][i], A[j][i]);
                int c = A[j][i]/g;
                int d = A[i][i]/g;
                for (int k = i; k < N; k++)
                    A[j][k] = d*A[j][k]-c*A[i][k];
                B[j] = d*B[j]-c*B[i];
            }
//        showmat();
    }
}
bool solve(int m) //求解方程组
{
    for (int i = N-1; i >= 0; i--)
    {
        int s = m*B[i];
        for (int j = i+1; j < N; j++)
            s = s-A[i][j]*X[j];
        if (!(s%A[i][i]))
            X[i] = s/A[i][i];
        else
            return 0;
    }
    return 1;
}
int main()
{
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
    for (int i = 0; i < N; i++)
        scanf("%d", &B[i]);
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            scanf("%d", &A[i][j]);
//    showmat();
    gauss();
//    showmat();
    for (int i = 1; ; i++)
        if (solve(i))
        {
            if (0 <= X[0] && X[0] < 100 && 0 <= X[1] && X[1] < 100 && 0 <= X[2] && X[2] < 100)
                printf("%d %d %d %d\n", X[0], X[1], X[2], (A[0][0]*X[0]+A[0][1]*X[1]+A[0][2]*X[2])/B[0]);
            else
                printf("NONE\n");
            break;
        }
    return 0;
}
