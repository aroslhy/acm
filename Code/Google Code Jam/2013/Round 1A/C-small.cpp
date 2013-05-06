#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int T, R, N, M, K;
int a[8], b[12], res;
bool flag, done;
set<int> st;
void dfs2(int n)
{
	if (n == N)
	{
		st.insert(res);
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		if (i)
			res *= a[n];
		dfs2(n+1);
		if (i)
			res /= a[n];
	}
}
void dfs(int n)
{
	if (n == N)
	{
		st.clear();
		res = 1;
		dfs2(0);
		bool flag = 1;
		for (int i = 0; i < K && flag; i++) if (st.find(b[i]) == st.end())
			flag = 0;
		if (flag && !done)
		{
			for (int i = 0; i < N; i++)
				printf("%d", a[i]);
			printf("\n");
			done = 1;
		}
		return;
	}
	for (int i = 2; i <= M; i++)
	{
		a[n] = i;
		dfs(n+1);
	}
}
int main()
{
	freopen("put.in", "r", stdin);
	freopen("put.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d%d%d", &R, &N, &M, &K);
		printf("Case #%d:\n", cas);
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < K; j++)
				scanf("%d", &b[j]);
			done = 0;
			dfs(0);
		}
	}
	return 0;
}
