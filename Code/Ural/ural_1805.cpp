// aroslhy	URAL 1805	Accepted	197 KB	31 ms	G++ 4.7.2	1438 B	2013-04-23 16:59:37
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10+5;
const long long INF = 1LL<<60;
int N, mark[MAXN][MAXN], cnt[MAXN];
long long K;
int main()
{
	scanf("%d%I64d", &N, &K);
	int n = N*N, m = n/4;
	for (int k = 0, i = 1; i <= N/2; i++)
		for (int j = 1; j<= N/2; j++)
			mark[i][j] = ++k;
	for (int k = 0, j = N; j > N/2; j--)
		for (int i = 1; i <= N/2; i++)
			mark[i][j] = ++k;
	for (int k = 0, i = N; i > N/2; i--)
		for (int j = N; j > N/2; j--)
			mark[i][j] = ++k;
	for (int k = 0, j = 1; j <= N/2; j++)
		for (int i = N; i > N/2; i--)
			mark[i][j] = ++k;
	long long sum = 1;
	for (int i = 1; i <= m; i++)
	{
		cnt[i] = 4;
		sum *= cnt[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (cnt[mark[i][j]])
			{
				long long tmp = sum/cnt[mark[i][j]];
				if (cnt[mark[i][j]]-1)
					tmp *= cnt[mark[i][j]]-1;
				if (tmp == 1 && cnt[mark[i][j]] == 1)
				{
					bool flag = 1;
					for (int k = 1; k <= m && flag; k++) if (k != mark[i][j] && cnt[k])
						flag = 0;
					if (flag)
						tmp = 0;
				}
				if (K > tmp)
				{
					printf("1");
					K -= tmp;
					sum /= cnt[mark[i][j]];
					cnt[mark[i][j]] = 0;
				}
				else if (cnt[mark[i][j]] == 1)
				{
					printf("1");
					cnt[mark[i][j]] = 0;
				}
				else
				{
					printf("0");
					sum = tmp;
					cnt[mark[i][j]]--;
				}
			}
			else
				printf("0");
		}
		printf("\n");
	}
	return 0;
}
