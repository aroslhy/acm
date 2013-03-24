// aroslhy	SPOJ CATTACK	Accepted	5018 KB	1680 ms	C++ (g++ 4.0.0-8)	688 B	2013-03-24 16:41:33
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
int T, N, l[2], s[2], dp[2][MAXN], dd[2][MAXN];
int d[MAXN][2];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d%d", &N, &l[0], &l[1], &s[0], &s[1]);
		for (int j = 0; j < 2; j++)
		{
			for (int i = 1; i < N; i++)
				scanf("%d", &dp[j][i]);
			for (int i = 1; i < N; i++)
				scanf("%d", &dd[j][i]);
		}
		d[1][0] = l[0]; d[1][1] = l[1];
		for (int i = 2; i <= N; i++)
		{
			d[i][0] = min(d[i-1][0]+dd[0][i-1], d[i-1][1]+dp[1][i-1]);
			d[i][1] = min(d[i-1][1]+dd[1][i-1], d[i-1][0]+dp[0][i-1]);
		}
		printf("%d\n", min(d[N][0]+s[0], d[N][1]+s[1]));
	}
	return 0;
}
