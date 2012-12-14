//10163 	Storage Keepers 	Accepted 	C++ 	0.236 	2012-12-14 03:23:11
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5, MAXM = 30+5, MAXP = 1000+5;
const int INF = 0x3f3f3f3f;
int N, M, P[MAXM];
int d[MAXM][MAXN][MAXP];
int main()
{
	while (scanf("%d%d", &N, &M))
	{
		if (!N && !M)
			break;
		for (int i = 1; i <= M; i++)
			scanf("%d", &P[i]);
		for (int i = 0; i <= M; i++)
			for (int j = 0; j <= N; j++)
				for (int k = 1; k <= 1000; k++)
					d[i][j][k] = INF;
		for (int i = 0; i < M; i++)
			for (int j = 0; j <= N; j++)
				for (int k = 0; k <= 1000; k++) if (d[i][j][k] < INF)
				{
					d[i+1][j][k] = min(d[i+1][j][k], d[i][j][k]);
					for (int l = 1; j+l <= N; l++)
					{
						if (j)
							d[i+1][j+l][min(k, P[i+1]/l)] = min(d[i+1][j+l][min(k, P[i+1]/l)], d[i][j][k]+P[i+1]);
						else
							d[i+1][j+l][P[i+1]/l]= min(d[i+1][j+l][P[i+1]/l], d[i][j][k]+P[i+1]);
					}
				}
		for (int k = 1000; k >= 0; k--)
			if (d[M][N][k] < INF)
			{
				printf("%d %d\n", k, d[M][N][k]);
				break;
			}
	}
	return 0;
}
