/*
正向、反向分别求LIS，再枚举每个点……
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 100000+5;
int N, x[MAXN], y[MAXN], id[MAXN];
int Y[MAXN], f[MAXN], d[2][MAXN], cnt[MAXN];
bool mark[MAXN];
bool cmp (const int &a, const int &b)
{
	if (x[a] != x[b])
		return x[a] < x[b];
	else
		return y[a] > y[b];
}
int LIS(int x)
{
	int maxi = 0;
	for (int i = 1; i <= N; i++)
	{
		int j = lower_bound(f+1, f+1+maxi, Y[i])-f;
		maxi = max(maxi, j);
		f[j] = Y[i];
		d[x][i] = j;
	}
	return maxi;
}
int main()
{
	while (scanf("%d", &N) != EOF)
	{
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= N; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
			id[i] = i;
		}
		sort(id+1, id+1+N, cmp);
		for (int i = 1; i <= N; i++)
			Y[i] = y[id[i]];
		int maxlen = LIS(0);
		for (int i = 1; i <= N; i++)
			Y[i] = -y[id[N-i+1]];
		LIS(1);
		vector<int> ans[2];
		for (int i = 1; i <= N; i++)
		{
			mark[i] = (d[0][i]+d[1][N-i+1] == maxlen+1);
			if (mark[i])
			{
				cnt[d[0][i]]++;
				ans[0].push_back(id[i]);
			}
		}
		for (int i = 1; i <= N; i++)
			if (mark[i] && cnt[d[0][i]] == 1)
				ans[1].push_back(id[i]);
		for (int i = 0; i < 2; i++)
		{
			sort(ans[i].begin(), ans[i].end());
			printf("%u", ans[i].size());
			for (vector<int>::iterator it = ans[i].begin(); it != ans[i].end(); it++)
				printf(" %d", *it);
			printf("\n");
		}
	}
	return 0;
}
