//10534 	Wavio Sequence 	Accepted 	C++ 	0.096 	2012-11-14 10:34:30
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5;
int N, a[MAXN];
int d[2][MAXN], f[MAXN];
int main()
{
	while (scanf("%d", &N) != EOF)
	{
		int maxi = 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
			int x = lower_bound(f+1, f+1+maxi, a[i])-f;
			maxi = max(maxi, x);
			f[x] = a[i];
			d[0][i] = x;
		}
		maxi = 0;
		for (int i = N; i >= 1; i--)
		{
			int x = lower_bound(f+1, f+1+maxi, a[i])-f;
			maxi = max(maxi, x);
			f[x] = a[i];
			d[1][i] = x;
		}
		int ans = 0;
		for (int i = 1; i <= N; i++)
			ans = max(ans, min(d[0][i], d[1][i])*2-1);
		printf("%d\n", ans);
	}
	return 0;
}
