// aroslhy	Accepted	256kB	0ms	795 B	G++	13.10.11
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 15+5, MAXM = 50+5, MAXP = 100+5;
const int INF = 0x3f3f3f3f;
int T, N, M, P, a[MAXN], s[MAXP], t[MAXP];
int d[MAXP][MAXM], sum[MAXP];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &N, &M, &P);
		for (int i = 1; i < N; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= P; i++)
		{
			scanf("%d%d", &s[i], &t[i]);
			for (int j = s[i]; j < N; j++)
				t[i] += a[j];
		}
		sort(t+1, t+1+P);
		for (int i = 1; i <= P; i++)
		{
			sum[i] = sum[i-1]+t[i];
			d[i][0] = INF;
			for (int j = 1; j <= M; j++)
			{
				d[i][j] = INF;
				for (int k = 1; k <= i; k++)
					d[i][j] = min(d[i][j], d[k-1][j-1]+t[i]*(i-k+1)-(sum[i]-sum[k-1]));
			}
		}
		printf("%d\n", d[P][M]);
	}
	return 0;
}
