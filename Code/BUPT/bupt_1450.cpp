//1450 	Accepted 	196ms 	168kb 	G++	841B	2013-03-04 19:58:31 	bigoceanlhy
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 3000+5;
int T, N, M, s[MAXN], que[MAXN];
bool no[MAXN];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++)
			scanf("%d", &s[i]);
		memset(no, 0, sizeof(no));
		for (int k = 1; k <= N; k++) if (!no[k])
		{
			int sum = 0, rear = 0;
			bool flag = 1;
			for (int i = 0; i < N && flag; i++)
			{
				if (i >= k)
					sum -= que[i-k];
				int q = (s[i]+sum)%M;
				if (i+k-1 < N)
				{
					que[rear++] = M-q;
					sum += M-q;
				}
				else if (q)
					flag = 0;
			}
			if (!flag)
			{
				for (int x = k; x <= N; x += k)
					no[x] = 1;
			}
		}
		int ans = 0;
		for (int k = 1; k <= N; k++) if (!no[k])
			ans++;
		printf("%d\n", ans);
	}
	return 0;
}
