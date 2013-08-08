// 2013-08-08 18:46:25	Accepted	4647	265MS	996K	534 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
int N, M, u, v, w;
double val[MAXN];
int main()
{
	while (scanf("%d%d", &N, &M) != EOF)
	{
		for (int i = 1; i <= N; i++)
			scanf("%lf", &val[i]);
		for (int i = 1; i <= M; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			val[u] += w/2.0;
			val[v] += w/2.0;
		}
		sort(val+1, val+1+N);
		double ans = 0;
		for (int i = N; i >= 1; i -= 2)
			ans += val[i]-val[i-1];
		printf("%.0lf\n", ans);
	}
	return 0;
}
