// 2013-08-08 17:32:56	Accepted	4655	765MS	19040K	855 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000000+5;
const long long MOD = 1000000007;
int T, N;
long long f[MAXN], g[MAXN], a[MAXN], tmp[MAXN];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			scanf("%I64d", &a[i]);
			tmp[i] = a[i];
		}
		sort(tmp+1, tmp+1+N);
		for (int i = 1, p = 1, q = N; p <= q; )
		{
			a[i++] = tmp[p++];
			a[i++] = tmp[q--];
		}
		g[0] = 1;
		f[1] = g[1] = a[1];
		for (int i = 2; i <= N; i++)
		{
			if (a[i-1] <= a[i])
				f[i] = ((f[i-1]*a[i])%MOD+((g[i-2]*a[i-1])%MOD*(a[i]-1))%MOD)%MOD;
			else
				f[i] = ((f[i-1]*a[i])%MOD+(g[i-2]*((a[i]*(a[i]-1))%MOD+((a[i-1]-a[i])*a[i])%MOD))%MOD)%MOD;
			g[i] = (g[i-1]*a[i])%MOD;
		}
		printf("%I64d\n", (f[N]+MOD)%MOD);
	}
	return 0;
}
