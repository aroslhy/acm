//2012-10-06 16:24:19	Accepted	3757	2859MS	28028K	1364 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 4000+5;
const long long INF = 1LL<<60;
int T, N, M, x[2][MAXN];
long long d[2][MAXN];
short r[2][MAXN], p[MAXN][MAXN], ans[MAXN];
bool cmp0(const int a, const int b)
{
	return x[0][a] < x[0][b];
}
bool cmp1(const int a, const int b)
{
	return x[1][a] < x[1][b];
}
int make_ans(int x, int y)
{
	if (x > 1)
		make_ans(x-1, p[x][y]);
	ans[r[0][x]] = r[1][y];
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &x[0][i]);
			r[0][i] = i;
		}
		sort(r[0]+1, r[0]+1+N, cmp0);
		scanf("%d", &M);
		for (int i = 1; i <= M; i++)
		{
			scanf("%d", &x[1][i]);
			r[1][i] = i;
		}
		sort(r[1]+1, r[1]+1+M, cmp1);
		int s = 0, t = 1;
		for (int i = 1; i <= N; i++)
		{
			swap(s, t);
			for (int j = 1; j <= i && j <= M; j++)
			{
				d[t][j] = (j > 1 ? d[s][j-1] : (i > 1 ? INF : 0));
				p[i][j] = j-1;
				if (i > j && d[s][j] < d[t][j])
				{
					d[t][j] = d[s][j];
					p[i][j] = j;
				}
				d[t][j] += abs(x[0][r[0][i]]-x[1][r[1][j]]);
			}
		}
		printf("%I64d\n", d[t][M]);
		make_ans(N, M);
		for (int i = 1; i <= N; i++)
		{
			if (i > 1)
				printf(" ");
			printf("%hd", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
