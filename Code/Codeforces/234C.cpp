//Oct 16, 2012 11:41:05 AM 	bigoceanlhy 	234C - Weather 	GNU C++ 	Accepted 	62 ms 	1300 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 100000+5;
const int INF = 0x3f3f3f3f;
int N, t[MAXN], f[MAXN], g[MAXN];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &t[i]);
		f[i] = f[i-1]+(t[i] >= 0 ? 1 : 0);
	}
	int ans = INF;
	for (int i = N; i > 1; i--)
	{
		g[i] = g[i+1]+(t[i] <= 0 ? 1 : 0);
		ans = min(ans, f[i-1]+g[i]);
	}
	printf("%d\n", ans);
	return 0;
}
