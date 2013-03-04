//1449 	Accepted 	110ms 	924kb 	G++	1058B	2013-03-04 19:42:34 	bigoceanlhy
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 50000;
const int MAXN = 50000+5;
int T, N, f[MAXN];
int e, v[MAXN], next[MAXN], head[MAXN];
void addedge(int x, int y)
{
	v[e] = y;
	next[e] = head[x]; head[x] = e++;
}
int main()
{
	e = 0;
	memset(head, -1, sizeof(head));
	for (int i = 1; i <= MAX; i++)
	{
		int x = 1, r = sqrt(i);
		for (int j = 2; j <= r; j++) if (!(i%j))
		{
			if (j*j == i)
				x += j;
			else
				x += j+i/j;
		}
		if (x < i)
			addedge(x, i);
	}
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		int ans = 0;
		for (int u = N; u > 0; u--)
		{
			int maxi[2] = {};
			for (int i = head[u]; i != -1; i = next[i]) if (v[i] <= N)
			{
				if (f[v[i]]+1 > maxi[0])
				{
					maxi[1] = maxi[0];
					maxi[0] = f[v[i]]+1;
				}
				else if (f[v[i]]+1 > maxi[1])
					maxi[1] = f[v[i]]+1;
			}
			ans = max(ans, maxi[0]+maxi[1]);
			f[u] = maxi[0];
		}
		printf("%d\n", ans);
	}
	return 0;
}
