// aroslhy	URAL 1917	Accepted	8017 KB	31 ms	G++ 4.7.2	702 B	2013-05-09 09:56:32
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 1000000+5;
const int MAXN = MAX+5;
int N, P, a, cnt[MAXN], sum[MAXN];
int main()
{
	scanf("%d%d", &N, &P);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a);
		cnt[a]++;
	}
	for (int i = 1; i <= MAX; i++)
		sum[i] = sum[i-1]+cnt[i];
	int maxi = 0, mini = 0, last = 0, cur = 0, i;
	for (i = 1; i <= MAX; )
	{
		if (i*(sum[i]-sum[last]) <= P)
			cur = i++;
		else
		{
			if (sum[cur] > sum[last])
			{
				maxi += sum[cur]-sum[last];
				mini++;
				last = cur;
			}
			else
				break;
		}
	}
	if (sum[cur] > sum[last])
	{
		maxi += sum[cur]-sum[last];
		mini++;
	}
	printf("%d %d\n", maxi, mini);
	return 0;
}
