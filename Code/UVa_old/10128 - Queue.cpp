#include<cstdio>
using namespace std;
const int MAXN = 13+5;
int T, N, P, R;
long long f[MAXN][MAXN][MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
	    scanf("%d%d%d", &N, &P, &R);
	    f[1][1][1] = 1;
	    for (int i = 2; i <= N; i++)
            for (int j = 1; j <= P; j++)
                for (int k = 1; k <= R; k++)
                    f[i][j][k] = f[i-1][j-1][k]+f[i-1][j][k-1]+(i-2)*f[i-1][j][k];
        printf("%lld\n", f[N][P][R]);
	}
	return 0;
}
