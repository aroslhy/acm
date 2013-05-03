// 12393	Non-negative Partial Sums	Accepted	C++	0.499	2013-05-03 02:32:59
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2000000+5;
int N, a[MAXN], sum[MAXN], que[MAXN];
int main()
{
	while (scanf("%d", &N) && N)
	{
		int n = N*2, ans = 0, front = 0, rear = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i <= N)
				scanf("%d", &a[i]);
			else
				a[i] = a[i-N];
			sum[i] = sum[i-1]+a[i];
			while (front < rear && sum[i] < sum[que[rear-1]])
				rear--;
			que[rear++] = i;
			if (i <= N)
				continue;
			while (que[front] <= i-N)
				front++;
			if (sum[que[front]]-sum[i-N] >= 0)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
