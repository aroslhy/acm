#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, ans;
int t[1111][2];
int ord[1111];
int st[1111];
bool vis[1111];

int main()
{
	int i, j, k;
	while (~scanf("%d", &N))
	{
		memset(vis, 0, sizeof(vis));
		for (i = 0; i < N; ++i)
			scanf("%d%d", &t[i][0], &t[i][1]);
		int head = 0, tail = N-1;
		int min, hmr, mdk;
		for (i = 0; i < N; ++i)
		{
			min = 0x11111111;
			for (j = 0; j < N; ++j)
			{
				if (vis[j]) continue;
				for (k = 0; k < 2; ++k)
					if (t[j][k]<min)
					{
						min = t[j][k];
						hmr = j;
						mdk = k;
					}
			}
			vis[hmr] = 1;
			if (mdk == 0)
				ord[head++] = hmr;
			else
				ord[tail--] = hmr;
		}
		st[0] = 0;
		for (i = 0; i < N; ++i)
			st[i+1] = st[i]+t[ord[i]][0];
		ans = 0;
		for (i = 0; i < N; ++i)
		{
			j = ord[i];
			if (ans > st[i+1]) ans += t[j][1];
			else ans = st[i+1]+t[j][1];
		}
		printf("%d\n", ans);
	}
	return 0;
}
