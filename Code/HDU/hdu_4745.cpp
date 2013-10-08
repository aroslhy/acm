// 2013-09-17 10:54:40	Accepted	4745	593MS	14536K	779 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2000+5;
int N, a[MAXN], d[MAXN][MAXN];
int main()
{
	while (scanf("%d", &N) && N)
	{
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
			a[N+i] = a[i];
			d[i][i] = 1;
			d[N+i][N+i] = 1;
		}
		int n = N<<1;
		for (int len = 2; len <= n; len++)
			for (int i = 1; i <= n; i++)
			{
				int j = i+len-1;
				d[i][j] = max(d[i][j-1], d[i+1][j]);
				if (len > 2)
					d[i][j] = max(d[i][j], d[i+1][j-1]+(a[i] == a[j] ? 2 : 0));
				else
					d[i][j] = max(d[i][j], (a[i] == a[j] ? 2 : 0));
			}
		int ans = d[N+2][n]+1;
		for (int i = 1; i <= N+1; i++)
			ans = max(ans, max(d[i][i+N-1], d[i][i+N-2]+1));
		printf("%d\n", ans);
	}
	return 0;
}
