#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
const int INF = 0x3f3f3f3f;
int T, N, a, s, t;
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d", &N);
		int sum = 0, mini = 0, maxi = -INF, p = 1;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &a);
			sum += a;
			if (sum-mini > maxi)
			{
				maxi = sum-mini;
				s = p;
				t = i;
			}
			if (sum < mini)
			{
				mini = sum;
				p = i+1;
			}
		}
		if (cas > 1)
			printf("\n");
		printf("Case %d:\n", cas);
		printf("%d %d %d\n", maxi, s, t);
	}
	return 0;
}
