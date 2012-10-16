//Oct 16, 2012 12:16:15 PM 	bigoceanlhy 	234A - Lefthanders and Righthanders 	GNU C++ 	Accepted 	31 ms 	100 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 100+5;
const int INF = 0x3f3f3f3f;
int N;
char s[MAXN];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%s", &N, s+1);
	int n = (N>>1);
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == 'R' && s[i+n] == 'L')
			printf("%d %d\n", i+n, i);
		else
			printf("%d %d\n", i, i+n);
	}
	return 0;
}
