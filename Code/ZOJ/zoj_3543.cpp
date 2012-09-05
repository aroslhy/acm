//2012-09-03 17:47:34 	Accepted 	3543 	C++ 	600 	4124 	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5;
const int MOD = 1000000007;
int sum[MAXN][MAXN];
char sig[MAXN];
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    sum[1][1] = 1;
    while (scanf("%s", sig+2) != EOF)
    {
        int n = strlen(sig+2)+1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i; j++)
            {
                if (sig[i] == 'I')
                    sum[i][j] = ((sum[i][j-1]+sum[i-1][j-1])%MOD+MOD)%MOD;
                else if (sig[i] == 'D')
                    sum[i][j] = ((sum[i][j-1]+sum[i-1][i-1]-sum[i-1][j-1])%MOD+MOD)%MOD;
                else
                    sum[i][j] = ((sum[i][j-1]+sum[i-1][i-1])%MOD+MOD)%MOD;
//                printf("%d,%d:%d\n", i, j, d);
            }
        printf("%d\n", sum[n][n]);
    }
    return 0;
}
