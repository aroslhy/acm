// aroslhy	UESTC 1711	Accepted	2524 KB	672 ms	G++	1130 B	2013-07-23 17:21:57
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 200000+5;
int T, N, a, x;
long long f[MAXN];
bool g[MAXN];
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d", &N);
		memset(f, 0, sizeof(f));
		int maxi = 0, mini = 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d%d", &a, &x);
			f[a] += x;
			maxi = max(maxi, a);
		}
		g[0] = 0;
		for (int i = 1; ; i++)
		{
			long long c = f[i-1]/2;
			if (i > maxi && !c)
			{
				maxi = i-1;
				break;
			}
			if (c)
			{
				f[i-1] -= c<<1;
				f[i] += c;
				g[i] = 1;
			}
			else
				g[i] = 0;
			if (!f[i-1] && mini == i-1)
				mini++;
		}
		for (int i = maxi; i >= 0; i--)
		{
			if (f[i] && !g[i])
				break;
			maxi--;
		}
		printf("Case #%d: ", cas);
		if (maxi >= 0)
		{
			bool flag = 0;
			for (int i = maxi; i >= 0; i--)
			{
				if (i > mini)
				{
					if (flag)
						printf("%d", f[i] ? 0 : 1);
					else if (!f[i])
					{
						printf("%d", f[i] ? 0 : 1);
						flag = 1;
					}
				}
				else
					printf("%d", f[i] ? 1 : 0);
			}
			printf("\n");
		}
		else
			printf("0\n");
	}
	return 0;
}
