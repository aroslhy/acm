//2012-10-15 21:57:04 	Accepted 	3657 	C++ 	10 	180 	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 5+5;
const int MAX = (1<<10);
int N, W[MAXN];
int main()
{
	while (scanf("%d", &N) != EOF)
	{
		for (int i = 1; i <= N; i++)
			scanf("%d", &W[i]);
		int ans = 0;
		for (int i = 1; i <= 5; i++)
			for (int j = i+1; j <= 5; j++)
			{
				int giv = 0, tot = 0;
				for (int k = 1; k <= 5; k++)
				{
					if (k != i && k != j)
						giv += W[k];
					else
						tot += W[k];
				}
				for (int k = 1; k <= 5; k++)
					if (k != i && k != j && k > N)
					{
						giv = 0;
						break;
					}
				if (tot)
					tot = (tot-1)%MAX+1;
				for (int k = 1; k <= 5; k++)
					if ((k == i || k == j) && k > N)
					{
						tot = MAX;
						break;
					}
				if (!(giv%MAX))
					ans = max(ans, tot);
			}
		printf("%d\n", ans);
	}
	return 0;
}
