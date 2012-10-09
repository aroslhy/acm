#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 200000+5;
int T, N, x[MAXM], y[MAXM], id[MAXM];
int f[MAXN], g[MAXN];
bool cmp (const int &a, const int &b)
{
	if (x[a] != x[b])
		return x[a] < x[b];
	else
		return y[a] > y[b];
}
int LIS(int n)
{
	int maxi = 0;
	for (int i = 0; i < n; i++)
	{
		if (!(id[i]&1))
			g[id[i]>>1] = lower_bound(f+1, f+1+maxi, y[id[i]])-f;
		else
		{
			if (g[id[i]>>1] > maxi)
				f[++maxi] = y[id[i]];
			else
				f[g[id[i]>>1]] = min(f[g[id[i]>>1]], y[id[i]]);
		}
	}
	return maxi;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d%d%d%d", &x[i<<1], &y[i<<1], &x[i<<1|1], &y[i<<1|1]);
			id[i<<1] = i<<1;
			id[i<<1|1] = i<<1|1;
		}
		int n = N<<1;
		sort(id, id+n, cmp);
		printf("%d\n", LIS(n));
	}
	return 0;
}
