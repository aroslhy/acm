#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
int N, a[MAXN], d[MAXN];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	d[1] = 1, d[2] = 2;
	int ans = min(N, 2);
	for (int i = 3; i <= N; i++)
	{
		if (a[i] == a[i-1]+a[i-2])
			d[i] = d[i-1]+1;
		else
			d[i] = 2;
		ans = max(ans, d[i]);
	}
	printf("%d\n", ans);
	return 0;
}

