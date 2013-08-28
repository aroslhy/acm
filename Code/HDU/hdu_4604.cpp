// 2013-08-28 17:34:08	Accepted	4604	593MS	1764K	1137 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
int T, N, a[MAXN], f[MAXN], g[MAXN], d[MAXN];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			scanf("%d", &a[i]);
		int maxi = 0, ans = 0;
		for (int i = N; i >= 1; i--)
		{
			int x = upper_bound(d+1, d+1+maxi, a[i])-d;
			maxi = max(maxi, x);
			d[x] = a[i];
			f[i] = x;
			a[i] = -a[i];
		}
		maxi = 0;
		for (int i = N; i >= 1; i--)
		{
			ans = max(ans, f[i]+lower_bound(d+1, d+1+maxi, a[i])-d-1);
			int x = upper_bound(d+1, d+1+maxi, a[i])-d;
			maxi = max(maxi, x);
			d[x] = a[i];
			g[i] = x;
		}
		maxi = 0;
		for (int i = N; i >= 1; i--)
		{
			int x = upper_bound(d+1, d+1+maxi, a[i])-d;
			maxi = max(maxi, x);
			d[x] = a[i];
			f[i] = x;
			a[i] = -a[i];
		}
		maxi = 0;
		for (int i = N; i >= 1; i--)
		{
			ans = max(ans, f[i]+lower_bound(d+1, d+1+maxi, a[i])-d-1);
			int x = upper_bound(d+1, d+1+maxi, a[i])-d;
			maxi = max(maxi, x);
			d[x] = a[i];
			g[i] = x;
		}
		printf("%d\n", ans);
	}
	return 0;
}
