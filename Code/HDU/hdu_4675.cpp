// 2013-08-18 21:19:53	Accepted	4675	1359MS	7248K	1301 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 300000, MAXN = MAX+5;
const int MOD = 1000000007;
int N, M, K, a[MAXN];
int vis[MAXN], cnt[MAXN], fac[MAXN], inv[MAXN], ans[MAXN];
int pow(int x, int k)
{
	int res = 1, b = x;
	while (k)
	{
		if (k&1)
			res = ((long long)res*b)%MOD;
		b = ((long long)b*b)%MOD;
		k >>= 1;
	}
	return res;
}
int main()
{
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= MAX; i++)
	{
		fac[i] = ((long long)fac[i-1]*i)%MOD;
		inv[i] = pow(fac[i], MOD-2);
	}
	while (scanf("%d%d%d", &N, &M, &K) != EOF)
	{
		fill(vis+1, vis+1+M, 0);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
			vis[a[i]]++;
		}
		for (int i = 1; i <= M; i++)
		{
			cnt[i] = 0;
			for (int j = i; j <= M; j += i)
				cnt[i] += vis[j];
		}
		for (int i = M; i >= 1; i--)
		{
			if (cnt[i] < N-K)
			{
				ans[i] = 0;
				continue;
			}
			ans[i] = (long long)fac[cnt[i]]*inv[cnt[i]-N+K]%MOD*inv[N-K]%MOD*pow(M/i-1, cnt[i]-N+K)%MOD*pow(M/i, N-cnt[i])%MOD;
			for (int j = i+i; j <= M; j += i)
				ans[i] = (ans[i]-ans[j])%MOD;
			ans[i] = (ans[i]+MOD)%MOD;
		}
		for (int i = 1; i <= M; i++)
		{
			if (i > 1)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
