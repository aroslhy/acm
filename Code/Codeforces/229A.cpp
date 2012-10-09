//Oct 1, 2012 10:49:36 PM 	bigoceanlhy 	229A - Shifts 	GNU C++ 	Accepted 	46 ms 	5100 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5, MAXM = 10000+5;
const int INF = 0x3f3f3f3f;
int N, M, d[MAXN][MAXM];
char mat[MAXN][MAXM];
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%s", mat[i]+1);
	fill(d[0]+1, d[0]+1+M, 0);
	bool flag = 1;
	for (int i = 1; i <= N; i++)
	{
		flag = 0;
		for (int j = 1; j <= M; j++)
		{
			d[i][j] = INF;
			if (mat[i][j] == '1')
				flag = 1;
		}
		if (!flag)
			break;
		int nst;
		for (int j = 1; j <= M; j++)
			if (mat[i][j] == '1')
				nst = j;
		nst -= M;
		for (int j = 1; j <= M; j++)
		{
			if (mat[i][j] == '1')
				nst = j;
			d[i][j] = min(d[i][j], d[i-1][j]+j-nst);
		}
		for (int j = M; j >= 1; j--)
			if (mat[i][j] == '1')
				nst = j;
		nst += M;
		for (int j = M; j >= 1; j--)
		{
			if (mat[i][j] == '1')
				nst = j;
			d[i][j] = min(d[i][j], d[i-1][j]+nst-j);
		}
	}
	int ans = INF;
	for (int j = 1; j <= M; j++)
		ans = min(ans, d[N][j]);
	if (flag)
		printf("%d\n", ans);
	else
		printf("-1\n");
	return 0;
}
