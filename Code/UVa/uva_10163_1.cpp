//10163 	Storage Keepers 	Accepted 	C++ 	0.012 	2012-12-14 03:21:21
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5, MAXM = 30+5, MAXP = 1000+5;
const int INF = 0x3f3f3f3f;
int N, M, P[MAXM];
int d[MAXM][MAXN], f[MAXM][MAXN];
int main()
{
	for (int i = 0; i <= 30; i++)
		d[i][0] = INF;
	while (scanf("%d%d", &N, &M))
	{
		if (!N && !M)
			break;
		for (int i = 1; i <= M; i++)
			scanf("%d", &P[i]);
		for (int i = 1; i <= M; i++)
			for (int j = 1; j <= N; j++)
			{
				d[i][j] = d[i-1][j];
				for (int k = 1; k <= j; k++)
					d[i][j] = max(d[i][j], min(d[i-1][j-k], P[i]/k));
			}
		for (int i = 0; i <= M; i++)
			for (int j = 1; j <= N; j++)
				f[i][j] = INF;
		for (int i = 1; i <= M; i++)
			for (int j = 1; j <= N; j++)
			{
				f[i][j] = f[i-1][j];
				for (int k = 1; k <= j; k++)
					if (P[i]/k >= d[M][N])
						f[i][j] = min(f[i][j], f[i-1][j-k]+P[i]);
			}
		printf("%d %d\n", d[M][N], d[M][N] ? f[M][N] : 0);
	}
	return 0;
}
