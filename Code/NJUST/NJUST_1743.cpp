// 1743	aroslhy(Aros)	Accepted	 2424ms	 1724KB	 GPP	 1930 B	 2013-05-19 12:51
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 8, MAXN = MAX+5, MAXM = 1<<(MAX+1);
int T, N, e, head[MAXN][1<<MAX], next[MAXM], cnt[1<<16];
unsigned long long a[MAXN], v[MAXM];
void Addedge(int n, int t, unsigned long long mov)
{
	v[e] = mov;
	next[e] = head[n][t]; head[n][t] = e++;
}
void Select(int N, unsigned long long &mat, unsigned long long &mov, int x, int y)
{
	mov ^= 1ULL<<(N*x+y);
	mat ^= 1ULL<<(N*x+y);
	if (x > 0)
		mat ^= 1ULL<<(N*(x-1)+y);
	if (x+1 < N)
		mat ^= 1ULL<<(N*(x+1)+y);
	if (y > 0)
		mat ^= 1ULL<<(N*x+y-1);
	if (y+1 < N)
		mat ^= 1ULL<<(N*x+y+1);
}
int Count(unsigned long long x)
{
	int pat = (1<<16)-1, res = 0;
	for (int i = 0; i < 4; i++)
		res += cnt[(x>>(i*16))&pat];
	return res;
}
int main()
{
	memset(head, -1, sizeof(head));
	for (int n = 1; n <= 8; n++)
	{
		int tot = 1<<n;
		for (int s = 0; s < tot; s++)
		{
			unsigned long long mat = 0, mov = 0;
			for (int j = 0; j < n; j++) if (s&(1<<j))
				Select(n, mat, mov, 0, j);
			for (int i = 1; i < n; i++)
				for (int j = 0; j < n; j++) if (mat&(1ULL<<(n*(i-1)+j)))
					Select(n, mat, mov, i, j);
			int t = mat>>((n-1)*n);
			Addedge(n, t, mov);
		}
	}
	int tot = 1<<16;
	for (int i = 0; i < tot; i++)
		for (int j = 0; j < 16; j++) if (i&(1<<j))
			cnt[i]++;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		unsigned long long mat = 0, mov = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%llu", &a[i]);
			for (int j = 0; j < N; j++)
				mat ^= ((a[i]>>(N-j-1))&1)<<(N*i+j);
		}
		for (int i = 1; i < N; i++)
			for (int j = 0; j < N; j++) if (mat&(1ULL<<(N*(i-1)+j)))
				Select(N, mat, mov, i, j);
		int fin = mat>>((N-1)*N), ans = -1;
		for (int i = head[N][fin]; i != -1; i = next[i])
			ans = (ans != -1) ? min(ans, Count(mov^v[i])) : Count(mov^v[i]);
		printf("%d\n", ans);
	}
	return 0;
}
