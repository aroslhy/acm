//Oct 16, 2012 1:55:18 PM 	bigoceanlhy 	234D - Cinema 	GNU C++ 	Accepted 	31 ms 	100 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 100+5, MAXM = 10+5;;
const int INF = 0x3f3f3f3f;
int M, K, N, a, d, b;
int mini[MAXN], maxi[MAXN], S[MAXN];
char s[MAXM];
bool fav[MAXN];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &M, &K);
	for (int i = 1; i <= K; i++)
	{
		scanf("%d", &a);
		fav[a] = 1;
	}
	scanf("%d", &N);
	int p = 0, q = 0;
	for (int i = 1; i <= N; i++)
	{
		scanf("%s%d", s, &d);
		int zero = 0;
		for (int j = 1; j <= d; j++)
		{
			scanf("%d", &b);
			if (!b)
				zero++;
			else if (fav[b])
				mini[i]++;
		}
		maxi[i] = mini[i]+min(zero, K-mini[i]);
		mini[i] = max(mini[i], mini[i]+K-mini[i]+zero-(M-(d-zero)));
		if (!p || mini[i] > mini[p])
			p = i;
		if (!q || maxi[i] > maxi[q])
			q = i;
	}
	fill(S+1, S+1+N, 2);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) if (i != j)
			if (maxi[i] < mini[j])
				S[i] = 1;
	for (int i = 1; i <= N; i++)
	{
		bool flag = 1;
		for (int j = 1; j <= N; j++) if (i != j)
			if (mini[i] < maxi[j])
				flag = 0;
		if (flag)
			S[i] = 0;
	}
//	printf("%d %d\n", mini[p], maxi[q]);
	for (int i = 1; i <= N; i++)
	{
//		printf("%d,%d\n", mini[i], maxi[i]);
		printf("%d\n", S[i]);
	}
	return 0;
}
