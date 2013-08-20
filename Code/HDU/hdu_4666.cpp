// 2013-08-14 10:26:48	Accepted	4666	4453MS	13840K	1169 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN = 60000+5;
const int MAX = 5;
int N, M, od, p, x[MAXN][MAX];
multiset<int, greater<int> > st[1<<MAX];
int main()
{
	while (scanf("%d%d", &N, &M) != EOF)
	{
		int tot = (1<<M)-1;
		for (int u = 0; u <= tot; u++)
			st[u].clear();
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &od);
			if (od)
			{
				scanf("%d", &p);
				for (int u = 0; u <= tot; u++)
				{
					int tmp = 0;
					for (int j = 0; j < M; j++)
					{
						if (u&(1<<j))
							tmp -= x[p][j];
						else
							tmp += x[p][j];
					}
					st[u].erase(st[u].find(tmp));
				}
			}
			else
			{
				for (int j = 0; j < M; j++)
					scanf("%d", &x[i][j]);
				for (int u = 0; u <= tot; u++)
				{
					int tmp = 0;
					for (int j = 0; j < M; j++)
					{
						if (u&(1<<j))
							tmp -= x[i][j];
						else
							tmp += x[i][j];
					}
					st[u].insert(tmp);
				}
			}
			int q = 0;
			for (int u = 0; u <= tot>>1; u++) if (st[u].size())
				q = max(q, *st[u].begin()+*st[u^tot].begin());
			printf("%d\n", q);
		}
	}
	return 0;
}
