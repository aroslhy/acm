//Oct 16, 2012 6:37:59 PM 	bigoceanlhy 	234F - Fence 	GNU C++ 	Accepted 	156 ms 	64300 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 200+5, MAXM = 40000+5;
const int INF = 0x3f3f3f3f;
int N, a, b, h[MAXN];
int sum[MAXN], d[MAXN][MAXM][2];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &N, &a, &b);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &h[i]);
		sum[i] = sum[i-1]+h[i];
	}
	memset(d, 0x3f, sizeof(d));
	d[0][0][0] = d[0][0][1] = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= sum[i]; j++)
		{
			if (j+h[i+1] <= a)
				d[i+1][j+h[i+1]][0] = min(d[i+1][j+h[i+1]][0], d[i][j][0]);
			if (sum[i+1]-j <= b)
				d[i+1][j][1] = min(d[i+1][j][1], d[i][j][0]+min(h[i], h[i+1]));
			if (j+h[i+1] <= a)
				d[i+1][j+h[i+1]][0] = min(d[i+1][j+h[i+1]][0], d[i][j][1]+min(h[i], h[i+1]));
			if (sum[i+1]-j <= b)
				d[i+1][j][1] = min(d[i+1][j][1], d[i][j][1]);
		}
	int ans = INF;
	for (int j = 0; j <= sum[N]; j++)
		for (int k = 0; k < 2; k++)
			ans = min(ans, d[N][j][k]);
	if (ans < INF)
		printf("%d\n", ans);
	else
		printf("-1\n");
	return 0;
}
