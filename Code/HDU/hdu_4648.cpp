// 2013-08-08 18:51:18	Accepted	4648	390MS	668K	647 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 10000+5;
int N, M, a;
int sum[MAXN], pos1[MAXM], pos2[MAXM];
int main()
{
	while (scanf("%d%d", &N, &M) != EOF)
	{
		fill(pos1, pos1+M, N+1);
		fill(pos2, pos2+M, 0);
		pos1[0] = 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &a);
			sum[i] = ((sum[i-1]+a)%M+M)%M;
			pos1[sum[i]] = min(pos1[sum[i]], i);
			pos2[sum[i]] = max(pos2[sum[i]], i);
		}
		int ans = 0;
		for (int i = 0; i < M; i++) if (pos1[i] <= N && pos2[i] >= 1)
			ans = max(ans, pos2[i]-pos1[i]);
		printf("%d\n", ans);
	}
	return 0;
}
