//bigoceanlhy	3903	Accepted	976K	63MS	G++	478B	2012-10-06 16:59:48
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
const int INF = 0x7fffffff;
int N, a[MAXN], f[MAXN];
//int d[MAXN];
int main()
{
	while (scanf("%d", &N) != EOF)
	{
		f[0] = -INF;
		int maxi = 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
			int x = lower_bound(f, f+1+maxi, a[i])-f;
			maxi = max(maxi, x);
			f[x] = a[i];
//			d[i] = x;
		}
		printf("%d\n", maxi);
	}
	return 0;
}
