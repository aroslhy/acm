//10635 	Prince and Princess 	Accepted 	C++ 	0.048 	2012-12-05 13:04:01
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 62500+5;
int T, N, p, q, a;
int map[MAXN], f[MAXN];
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		memset(map, 0, sizeof(map));
		scanf("%d%d%d", &N, &p, &q);
		for (int i = 0; i <= p; i++)
		{
			scanf("%d", &a);
			map[a] = i+1;
		}
		int maxi = 0;
		for (int i = 0; i <= q; i++)
		{
			scanf("%d", &a);
			if (map[a])
			{
				int x = lower_bound(f+1, f+1+maxi, map[a])-f;
				maxi = max(maxi, x);
				f[x] = map[a];
			}
		}
		printf("Case %d: %d\n", cas, maxi);
	}
	return 0;
}
