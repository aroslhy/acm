// 2013-07-25 17:51:41	Accepted	4618	265MS	7760K	1825 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 300+5;
int T, N, M, mat[MAXN][MAXN];
char row[MAXN][MAXN][40], col[MAXN][MAXN][40];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
			{
				scanf("%d", &mat[i][j]);
				for (int k = 1; k <= min(N-i+1, M-j+1); k++)
					row[i][j][k/8] = col[i][j][k/8] &= ~(1<<(k%8));
			}
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
			{
				row[i][j][1/8] |= 1<<(1%8);
				for (int k = 1; 1 <= j-k && j+k <= M; k++)
				{
					if (mat[i][j-k] == mat[i][j+k])
						row[i][j-k][(k*2+1)/8] |= 1<<((k*2+1)%8);
					else
						break;
				}
				for (int k = 1; 1 <= j-k+1 && j+k <= M; k++)
				{
					if (mat[i][j-k+1] == mat[i][j+k])
						row[i][j-k+1][(k*2)/8] |= 1<<((k*2)%8);
					else
						break;
				}
				col[i][j][1/8] |= 1<<(1%8);
				for (int k = 1; 1 <= i-k && i+k <= N; k++)
				{
					if (mat[i-k][j] == mat[i+k][j])
						col[i-k][j][(k*2+1)/8] |= 1<<((k*2+1)%8);
					else
						break;
				}
				for (int k = 1; 1 <= i-k+1 && i+k <= N; k++)
				{
					if (mat[i-k+1][j] == mat[i+k][j])
						col[i-k+1][j][(k*2)/8] |= 1<<((k*2)%8);
					else
						break;
				}
			}
		int ans = 1;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				for (int k = min(N-i+1, M-j+1); k >= ans; k--)
				{
					bool flag = 1;
					for (int p = 0; p < k && flag; p++) if (!(row[i+p][j][k/8]&(1<<(k%8))) || !(col[i][j+p][k/8]&(1<<(k%8))))
						flag = 0;
					if (flag)
					{
						ans = max(ans, k);
						break;
					}
				}
		printf("%d\n", ans);
	}
	return 0;
}
