// 2013-09-18 22:29:41	Accepted	4733	171MS	3428K	2085 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
const int MOD = 1000000007;
int T, f[MAXN][2], n;
bool g[MAXN][2];
char GP[2][MAXN];
void print_pre(int p)
{
	if (p > 1)
		print_pre(p-1);
	if (f[p][0])
		printf(f[p-1][0] ? "0" : "1");
	else
		printf(f[p-1][0] ? "1" : "0");
}
void print_ans(int p, int a)
{
	print_pre(p-1);
	printf("%d", a);
	if (p+1 <= n)
		printf("1");
	for (int i = p+2; i <= n; i++)
		printf("0");
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%s%s", GP[0]+1, GP[1]+1);
		n = 0;
		f[0][0] = 1, f[0][1] = 0;
		for (int i = 1; GP[1][i]; i++, n++)
		{
			if (GP[0][i] == '?' && GP[1][i] == '?')
				f[i][0] = f[i][1] = (f[i-1][0]+f[i-1][1])%MOD;
			else if (GP[0][i]+GP[1][i] == '0'+'1')
				f[i][0] = f[i][1] = 0;
			else if (GP[0][i] == '0' || GP[1][i] == '0')
				f[i][0] = f[i-1][0], f[i][1] = f[i-1][1];
			else
				f[i][0] = f[i-1][1], f[i][1] = f[i-1][0];
		}
		g[n+1][0] = 1, g[n+1][1] = 1;
		for (int i = n; i >= 1; i--)
		{
			if (GP[0][i] == '?' && GP[1][i] == '?')
				g[i][0] = g[i][1] = g[i+1][0];
			else if (GP[0][i]+GP[1][i] == '0'+'1')
				g[i][0] = g[i][1] = 0;
			else if (GP[0][i] == '0' || GP[1][i] == '0')
				g[i][0] = g[i+1][0], g[i][1] = 0;
			else
				g[i][0] = 0, g[i][1] = g[i+1][0];
		}
		int ans = 0, p, a;
		for (int i = 1; i <= n; i++)
		{
			if (GP[0][i] == GP[1][i] && GP[1][i] != '?')
				continue;
			if ((GP[0][i] == '0' || GP[0][i] == '?') && (GP[1][i] == '1' || GP[1][i] == '?') && g[i+1][1] && f[i-1][0])
			{
				ans = (ans+f[i-1][0])%MOD;
				p = i, a = 0;
			}
			if ((GP[0][i] == '1' || GP[0][i] == '?') && (GP[1][i] == '0' || GP[1][i] == '?') && g[i+1][1] && f[i-1][1])
			{
				ans = (ans+f[i-1][1])%MOD;
				p = i, a = 1;
			}
		}
		printf("Case #%d:\n", cas);
		if (ans == 1)
		{
			print_ans(p, a);
			print_ans(p, 1-a);
		}
		else if (ans)
			printf("Ambiguous %d\n", ans);
		else
			printf("Impossible\n");
	}
	return 0;
}
