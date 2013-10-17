// aroslhy	Accepted	260kB	10ms	647 B	G++	13.10.15
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
const int MOD = 1000000007;
int T, N, M, K, U, V;
char s[MAXN];
bool rem[MAXN];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%s", &N, &M, &K, s);
		fill(rem, rem+N, 0);
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d", &U, &V);
			rem[U] = rem[V] = 1;
		}
		long long ans = 1, x = K, y = 0;
		for (int i = 0; i < N; i++)
		{
			if (s[i] == 'I')
			{
				ans = (ans*x--)%MOD;
				if (!rem[i+1])
					y++;
			}
			else
			{
				if (!rem[i+1])
					ans = (ans*y--)%MOD;
				x++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
