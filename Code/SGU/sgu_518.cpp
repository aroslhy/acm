//bigoceanlhy	SGU 518	Accepted	1151 KB	46 ms	GNU CPP (MinGW, GCC 4)	888 B	2012-10-05 18:45:47
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 200+5;
const int INF = 0x3f3f3f3f;
int N, K, l[MAXN][MAXN], r[MAXN];
char d[MAXN][MAXN];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &l[i][j]);
	scanf("%d", &K);
	for (int i = 1; i <= K; i++)
		scanf("%d", &r[i]);
	d[0][1] = 1;
	for (int i = 0; i < K; i++)
		for (int j = 1; j <= N; j++) if (d[i][j])
			for (int k = 1; k <= N; k++) if (l[j][k] == r[i+1])
				d[i+1][k] = 1;
	vector<int> ans;
	for (int i = 1; i <= N; i++)
		if (d[K][i])
			ans.push_back(i);
	if (ans.size())
	{
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < (int)ans.size(); i++)
		{
			if (i)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	else
		printf("0\n");
	return 0;
}
