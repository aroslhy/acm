#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 50000+5, MAXM = 16;
int N, Q, h[MAXN];
int a[MAXN], pow2[MAXM];
int stmax[MAXN][MAXM], stmin[MAXN][MAXM];
inline int MostMax(const int &a, const int &b)
{
    return a > b ? a : b;
}
inline int MostMin(const int &a, const int &b)
{
    return a < b ? a : b;
}
void InitRMaxQ(const int &n)
{
    pow2[0] = 1;
    for (int i = 1; i <= MAXM; i++)
        pow2[i] = pow2[i-1]<<1; //预处理2的i次方，最大次幂要大于MAXN
    for (int i = 1; i <= n; i++)
        stmax[i][0] = a[i];
    int k = int(log(double(n))/log(2.0))+1;
    for (int j = 1; j < k; j++)
        for (int i = 1; i <= n; i++)
        {
            if (i+pow2[j-1]-1 <= n)
                stmax[i][j] = MostMax(stmax[i][j-1], stmax[i+pow2[j-1]][j-1]);
            else
                break; // st[i][j] = st[i][j-1];
        }
}
int QueryMax(int x, int y) // x, y均为下标:1...n
{
    int k = int(log(double(y-x+1))/log(2.0));
    return MostMax(stmax[x][k], stmax[y-pow2[k]+1][k]);
}
void InitRMinQ(const int &n)
{
    pow2[0] = 1;
    for (int i = 1; i <= 16; i++)
        pow2[i] = 2*pow2[i-1]; //预处理2的i次方，最大次幂要大于MAXN
    for (int i = 1; i <= n; i++)
        stmin[i][0] = a[i];
    int k = int(log(double(n))/log(2.0))+1;
    for (int j = 1; j < k; j++)
        for (int i = 1; i <= n; i++)
        {
            if (i+pow2[j-1]-1 <= n)
                stmin[i][j] = MostMin(stmin[i][j-1], stmin[i+pow2[j-1]][j-1]);
            else
                break; // st[i][j] = st[i][j-1];
        }
}
int QueryMin(int x, int y) // x, y均为下标:1...n
{
    int k = int(log(double(y-x+1))/log(2.0));
    return MostMin(stmin[x][k], stmin[y-pow2[k]+1][k]);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    InitRMaxQ(N);
    InitRMinQ(N);
    while (Q--)
    {
        int A, B;
        scanf("%d%d", &A, &B);
//        printf("%d\n", QueryMax(A, B));
//        printf("%d\n", QueryMin(A, B));
        printf("%d\n", QueryMax(A, B)-QueryMin(A, B));
    }
    return 0;
}
