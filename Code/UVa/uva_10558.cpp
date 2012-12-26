//10558 	A Brief Gerrymander 	Accepted 	C++ 	0.160 	2012-12-26 11:39:46
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 100, MAXM = MAX+5;
const int INF = 0x3f3f3f3f;
int N, S, A, X, Y;
int d[MAXM][MAXM], f[MAXM][MAXM], p[MAXM][MAXM];
bool grid[MAXM][MAXM], stre[MAXM], vis[MAXM];
void print_ans(int i, int j)
{
	if (j > 1)
		print_ans(i-1, p[i][j]);
	printf(" %d", j);
}
int main()
{
	freopen("put.in", "r", stdin);
	while (scanf("%d", &N) && N != -1)
	{
		memset(grid, 0, sizeof(grid));
		for (int i = 1; i <= N; i++)
		{
			scanf("%d%d", &X, &Y);
			grid[X][Y] = 1;
		}
		memset(stre, 0, sizeof(stre));
		scanf("%d", &S);
		for (int i = 1; i <= S; i++)
		{
			scanf("%d", &X);
			stre[X] = 1;
		}
		for (int i = 1; i < MAX; i++)
		{
			memset(vis, 0, sizeof(vis));
			for (int j = i+1; j <= MAX; j++)
			{
				int cnt = 0;
				for (int k = 1, l = 0; k < MAX; k++)
				{
					if (stre[k])
						l++;
					if (grid[k][j-1] && !vis[l])
					{
						cnt++;
						vis[l] = 1;
					}
				}
				f[i][j] = f[i][j-1]+cnt;
			}
		}
		scanf("%d", &A);
		for (int i = 2; i <= A; i++)
			for (int j = i; j <= MAX; j++)
			{
				d[i][j] = -INF;
				for (int k = i-1; k < j; k++)
					if (d[i-1][k]+f[k][j] > d[i][j])
					{
						d[i][j] = d[i-1][k]+f[k][j];
						p[i][j] = k;
					}
			}
		printf("%d", A);
		print_ans(A, MAX);
		printf("\n");
	}
	return 0;
}
