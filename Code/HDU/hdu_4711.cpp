// 2013-09-19 22:25:42	Accepted	4711	281MS	1656K	1329 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN = 1000+5, MAXM = 100+5;
const double eps = 1e-8, inf = 1e8;
int T, N, M, W, w[MAXN], p[MAXN][MAXM];
double pp[MAXM][MAXM], pw[MAXM][MAXM], d[MAXN][MAXM];
void print_ans(int i, int j)
{
	if (i > 1)
	{
		print_ans(i-1, p[i][j]);
		printf(" ");
	}
	printf("%d", j);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &N, &M, &W);
		for (int i = 1; i <= N; i++)
			scanf("%d", &w[i]);
		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++)
			{
				scanf("%lf", &pp[i][j]);
				pp[i][j] = log(pp[i][j]);
			}
		for (int i = 0; i < M; i++)
			for (int j = 0; j < W; j++)
			{
				scanf("%lf", &pw[i][j]);
				pw[i][j] = log(pw[i][j]);
			}
		d[0][0] = 0;
		fill(d[0]+1, d[0]+N, -inf);
		for (int i = 0; i < N; i++)
		{
			fill(d[i+1], d[i+1]+M, -inf);
			for (int j = 0; j < M; j++)
				for (int k = 0; k < M; k++)
				{
					double x = d[i][j]+pp[j][k]+pw[k][w[i+1]];
					if (x > d[i+1][k]+eps)
					{
						d[i+1][k] = x;
						p[i+1][k] = j;
					}
				}
		}
		double tmp = -inf;
		int end;
		for (int i = 0; i < M; i++) if (d[N][i] > tmp+eps)
		{
			tmp = d[N][i];
			end = i;
		}
		print_ans(N, end);
		printf("\n");
	}
	return 0;
}
