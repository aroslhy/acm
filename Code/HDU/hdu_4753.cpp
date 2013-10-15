// 2013-10-08 16:43:42	Accepted	4753	46MS	276K	1553 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int T, N, A, B;
int d[1<<12], sqa[9], edg[12];
int main()
{
	map<pair<int, int>, int> mp;
	for (int i = 0; i < 12; i++)
	{
		int k = i/4+i%4*4, l = i;
		mp.insert(make_pair(make_pair(k, k+1), 1<<i));
		mp.insert(make_pair(make_pair(l, l+4), 1<<(i+12)));
	}
	for (int i = 0; i < 9; i++)
	{
		int j = i/3*4+i%3, k = 12+i%3*4+i/3;
		sqa[i] = (1<<j)|(1<<(j+1))|(1<<k)|(1<<(k+1));
	}
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d", &N);
		int x = 0, alice = 0, bob = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%d%d", &A, &B);
			A--, B--;
			if (A > B)
				swap(A, B);
			int y = x;
			x |= mp.find(make_pair(A, B))->second;
			for (int j = 0; j < 9; j++) if ((y&sqa[j]) != sqa[j] && (x&sqa[j]) == sqa[j])
			{
				if (i&1)
					bob++;
				else
					alice++;
			}
		}
		int n = 0;
		for (int i = 0; i < 24; i++) if (!(x&(1<<i)))
			edg[n++] = i;
		for (int u = (1<<n)-1; u >= 0; u--)
		{
			d[u] = 0;
			for (int i = 0; i < n; i++) if (!(u&(1<<i)))
			{
				int v = u|(1<<i), a = x, tot = 9;
				for (int k = 0; k < n; k++) if (u&(1<<k))
					a |= 1<<edg[k];
				for (int j = 0; j < 9; j++) if ((a&sqa[j]) == sqa[j])
					tot--;
				d[u] = max(d[u], tot-d[v]);
			}
		}
		if (N&1)
			bob += d[0], alice = 9-bob;
		else
			alice += d[0], bob = 9-alice;
		if (alice > bob)
			printf("Case #%d: Tom200\n", cas);
		else
			printf("Case #%d: Jerry404\n", cas);
	}
	return 0;
}
