// 2013-08-13 19:03:07	Accepted	4669	546MS	440K	1138 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 50000+5, MAXK = 200+5;
int N, K, a[MAXN], mul[1005];
unsigned d[2][MAXK];
int main()
{
	for (int i = 1; i <= 9; i++)
		mul[i] = 10;
	for (int i = 10; i <= 99; i++)
		mul[i] = 100;
	for (int i = 100; i <= 999; i++)
		mul[i] = 1000;
	mul[1000] = 10000;
	while (scanf("%d%d", &N, &K) != EOF)
	{
		int tmp = 0, mod = 1, s = 0, t = 1;
		unsigned ans = 0;
		fill(d[t], d[t]+K, 0);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &a[i+1]);
			swap(s, t);
			fill(d[t], d[t]+K, 0);
			d[t][a[i+1]%K] = 1;
			for (int j = 0; j < K; j++)
				d[t][(j*mul[a[i+1]]+a[i+1])%K] += d[s][j];
			tmp = (tmp*mul[a[i+1]]+a[i+1])%K;
			ans += d[t][0];
			mod = (mod*mul[a[i+1]])%K;
		}
		int n = N*2-1;
		for (int i = N; i < n; i++)
		{
			swap(s, t);
			fill(d[t], d[t]+K, 0);
			for (int j = 0; j < K; j++)
				d[t][(j*mul[a[i+1-N]]+a[i+1-N])%K] += d[s][j];
			tmp = (tmp*mul[a[i+1-N]]+a[i+1-N])%K;
			d[t][tmp]--;
			tmp = ((tmp-a[i+1-N]*mod)%K+K)%K;
			ans += d[t][0];
		}
		printf("%u\n", ans);
	}
	return 0;
}
