#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 320+5;
int N, M, Q, s, S, K, X, heavy[MAXN], reh[MAXM], inse[MAXN][MAXM];
int e, head[MAXN], next[MAXN], v[MAXN];
long long a[MAXN], add[MAXM], sum[MAXM];
bool vis[MAXM][MAXN];
char ope[5];
void addedge(int x, int y)
{
	v[e] = y;
	next[e] = head[x], head[x] = e++;
}
int main()
{
	freopen("put.in", "r", stdin);
	scanf("%d%d%d", &N, &M, &Q);
	e = 0;
	fill(head+1, head+1+M, -1);
	for (int i = 1; i <= N; i++)
		cin>>a[i];
	int n = sqrt(N), cnt = 0;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d", &s);
		if (s > n)
			reh[heavy[i] = ++cnt] = i;
		for (int j = 1; j <= s; j++)
		{
			scanf("%d", &S);
			if (heavy[i])
			{
				vis[cnt][S] = 1;
				sum[heavy[i]] += a[S];
			}
			addedge(i, S);
		}
	}
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= cnt; j++)
			for (int k = head[i]; k != -1; k = next[k]) if (vis[j][v[k]])
				inse[i][j]++;
	for (int k = 1; k <= Q; k++)
	{
		scanf("%s", ope);
		if (ope[0] == '+')
		{
			scanf("%d%d", &K, &X);
			if (heavy[K])
				add[heavy[K]] += X;
			else
			{
				for (int i = head[K]; i != -1; i = next[i])
					a[v[i]] += X;
				for (int i = 1; i <= cnt; i++)
					sum[i] += X*inse[K][i];
			}
		}
		else
		{
			scanf("%d", &K);
			long long ans = sum[heavy[K]];
			if (!heavy[K])
			{
				for (int i = head[K]; i != -1; i = next[i])
					ans += a[v[i]];
			}
			for (int i = 1; i <= cnt; i++)
				ans += add[i]*inse[K][i];
			cout<<ans<<"\n";
		}
	}
	return 0;
}
