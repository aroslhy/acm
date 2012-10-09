#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
const int INF = 0x7fffffff;
int N, a[MAXN], f[MAXN];
//int d[MAXN];
int main()
{
	while (scanf("%d", &N) != EOF)
	{
		int maxi = 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
			int x = lower_bound(f+1, f+1+maxi, a[i])-f;
			maxi = max(maxi, x);
			f[x] = a[i];
//			d[i] = x;
		}
		printf("%d\n", maxi);
	}
	return 0;
}
