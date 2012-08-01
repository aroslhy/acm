/*
ID: bigocea1
PROG: kimbits
LANG: C++
*/
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 31+5;
int N, L;
long long I, f[MAXN][MAXN];
int main()
{
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    scanf("%d%d%lld", &N, &L, &I);
    for (int j = 0; j <= L; j++)
        f[0][j] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= L; j++)
            f[i][j] = f[i-1][j]+f[i-1][j-1];
    while (N)
    {
        if (I <= f[N-1][L])
            printf("0");
        else
        {
            printf("1");
            I -= f[N-1][L];
            L--;
        }
        N--;
    }
    printf("\n");
    return 0;
}
