// 6042	Bee Tower	Accepted	C++	0.025	2013-05-03 02:18:47
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 50+5, MAXM = 500+5;
const int INF = 0x3f3f3f3f;
int T, N, H, W, p[MAXN], h[MAXN], d[MAXN][MAXM];
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d%d", &N, &H, &W);
		int maxh = 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d%d", &p[i], &h[i]);
			maxh = max(maxh, h[i]);
		}
		memset(d, 0x3f, sizeof(d));
		int ans = INF;
		for (int i = 1; i <= N; i++) if (h[i] == maxh)
		{
			d[i][p[i]] = 0;
			for (int j = i; j >= 1; j--)
			{
				if (h[j] <= H)
				{
					for (int k = p[i]-(i-j); k >= p[i]-(i-j)*W && k >= p[1]; k--)
						ans = min(ans, d[j][k]);
				}
				if (j == 1) break;
				if (h[j]-h[j-1] <= H)
				{
					for (int k = p[i]-(i-j); k >= p[i]-(i-j)*W && k >= p[1]; k--)
						for (int l = 1; l <= W && k-l >= p[1]; l++)
							d[j-1][k-l] = min(d[j-1][k-l], d[j][k]+h[j-1]*abs(p[j-1]-(k-l)));
				}
				else break;
			}
			for (int j = i; j <= N; j++)
			{
				if (h[j] <= H)
				{
					for (int k = p[i]+(j-i); k <= p[i]+(j-i)*W && k <= p[N]; k++)
						ans = min(ans, d[j][k]);
				}
				if (j == N) break;
				if (h[j]-h[j+1] <= H)
				{
					for (int k = p[i]+(j-i); k <= p[i]+(j-i)*W && k <= p[N]; k++)
						for (int l = 1; l <= W && k+l <= p[N]; l++)
							d[j+1][k+l] = min(d[j+1][k+l], d[j][k]+h[j+1]*abs(p[j+1]-(k+l)));
				}
				else break;
			}
		}
		printf("Case #%d: %d\n", cas, ans < INF ? ans : -1);
	}
	return 0;
}
