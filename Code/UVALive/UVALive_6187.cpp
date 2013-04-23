// 6187	Never Wait for Weights	Accepted	C++	0.622	2013-04-23 09:15:04
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
int N, M, a, b, w, p[MAXN];
long long f[MAXN];
char cmd[5];
int find(int x)
{
	if (p[x] == x)
		return x;
	else
	{
		int y = find(p[x]);
		f[x] += f[p[x]];
		return p[x] = y;
	}
}
int main()
{
	while (scanf("%d%d", &N, &M))
	{
		if (!N && !M)
			break;
		for (int i = 1; i <= N; i++)
			p[i] = i, f[i] = 0;
		while (M--)
		{
			scanf("%s%d%d", cmd, &a, &b);
			if (cmd[0] == '!')
			{
				scanf("%d", &w);
				int x = find(a), y = find(b);
				if (x == y)
					continue;
				p[x] = y;
				f[x] = w+f[b]-f[a];
			}
			else
			{
				int x = find(a), y = find(b);
				if (x == y)
					printf("%lld\n", f[a]-f[b]);
				else
					printf("UNKNOWN\n");
			}
		}
	}
	return 0;
}
