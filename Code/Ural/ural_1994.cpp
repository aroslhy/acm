// UESTC_DaPangZi	URAL 1994	Accepted	561 KB	109 ms	G++ 4.7.2	756 B	2013-10-31 22:02:04
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 200+5, MAXK = 20+5;
const double eps = 1e-8;
int N, K;
double C[MAXN][MAXN], d[MAXN][MAXK];
int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i <= N; i++)
		C[i][0] = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			C[i][j] = C[i-1][j-1]+C[i-1][j];
	for (int i = 1; i <= N-K; i++)
	{
		d[i][0] = i;
		for (int j = 1; j < i && j <= K; j++)
		{
			d[i][j] = d[i-j][j];
			for (int k = 1; k <= i+j; k++)
			{
				double ex = 0;
				for (int l = 0; l <= k; l++) if (l <= i-j && k-l <= j)
					ex += C[i-j][l]*C[j][k-l]/C[i][k]*d[i-j-l][j-k+l];
				if (ex > d[i][j]+eps)
					d[i][j] = ex;
			}
		}
	}
	printf("%.7lf\n", d[N-K][K]);
	return 0;
}
