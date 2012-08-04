#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 50000+5, MAXM = 16;
int N, Q;
int a[MAXN], st[MAXN][MAXM];
int pow2[MAXM];
inline int Most(const int &a, const int &b)
{
    return a > b ? a : b;
}
void InitRMQ(const int &n)
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
                stmax[i][j] = Most(stmax[i][j-1], stmax[i+pow2[j-1]][j-1]);
            else
                break; // st[i][j] = st[i][j-1];
        }
}
int Query(int x, int y) // x, y均为下标:1...n
{
    int k = int(log(double(y-x+1))/log(2.0));
    return Most(stmax[x][k], stmax[y-pow2[k]+1][k]);
}
int main()
{
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    InitRMQ(N);
    while (Q--)
    {
        int A, B;
        scanf("%d%d", &A, &B);
        int ans = Query(A, B);
    }
    return 0;
}
