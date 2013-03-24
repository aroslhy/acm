// 2013-03-24 16:34:04	Accepted	4512	15MS	392K	732 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 200+5;
int T, N, H[MAXN], d[MAXN][MAXN];
int main()
{
	freopen("put.in", "r", stdin);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &H[i]);
			d[i][N+1] = 0;
		}
		H[N+1] = 0;
		for (int i = 1; i <= N; i++)
			for (int j = N; j >= i; j--)
			{
				d[i][j] = d[i-1][j];
				if (H[i] == H[j])
				{
					for (int k = N+1; k > j; k--) if (H[j] > H[k])
						d[i][j] = max(d[i][j], d[i-1][k]+1);
				}
			}
		int ans = 0;
		for (int i = 1; i <= N; i++)
		{
			ans = max(ans, d[i][i]*2-1);
			if (i < N)
				ans = max(ans, d[i][i+1]*2);
		}
		printf("%d\n", ans);
	}
	return 0;
}
