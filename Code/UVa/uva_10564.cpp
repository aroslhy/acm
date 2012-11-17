//10564 	Paths through the Hourglass 	Accepted 	C++ 	0.072 	2012-11-14 01:49:52
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 40+5, MAXM = 400+5;
int N, S, cell[MAXN][MAXN];
long long d[MAXN][MAXN][MAXM];
int main()
{
	while (scanf("%d%d", &N, &S))
	{
		if (!N && !S)
			break;
		int n = 2*N-1;
		memset(d, 0, sizeof(d));
		for (int i = 1; i <= N; i++)
			for (int j = i; j <= N; j++)
				scanf("%d", &cell[i][j]);
		for (int i = N+1; i <= n; i++)
			for (int j = N; j <= i; j++)
				scanf("%d", &cell[i][j]);
		if (S > n*9)
		{
			printf("0\n\n");
			continue;
		}
		for (int j = N; j <= n; j++)
			d[n][j][cell[n][j]] = 1;
		for (int i = n-1; i >= N; i--)
			for (int j = N; j <= i; j++)
				for (int k = cell[i][j]; k <= S; k++)
					d[i][j][k] += d[i+1][j][k-cell[i][j]]+d[i+1][j+1][k-cell[i][j]];
		for (int i = N-1; i >= 1; i--)
			for (int j = i; j <= N; j++)
				for (int k = cell[i][j]; k <= S; k++)
					d[i][j][k] += d[i+1][j][k-cell[i][j]]+d[i+1][j+1][k-cell[i][j]];
		long long ans = 0;
		for (int j = 1; j <= N; j++)
			ans += d[1][j][S];
		printf("%lld\n", ans);
		for (int j = 1; j <= N; j++) if (d[1][j][S])
		{
			printf("%d ", j-1);
			for (int i = 1, k = S; i < n; i++)
			{
				if (d[i+1][j][k-cell[i][j]])
				{
					printf("L");
					k -= cell[i][j];
				}
				else
				{
					printf("R");
					k -= cell[i][j];
					j = j+1;
				}
			}
			break;
		}
		printf("\n");
	}
	return 0;
}
