/*
斯坦纳树
最后的答案可能是一个森林，所以我们要先求出斯坦纳树后进行DP。转移的时候要注意一点，只有人的个数和房子的个数相等的时候才算合法状态，所以我们要加一个check()函数进行检查。
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 50+5, MAXM = 2000+5;
const int MAX = 10;
const int INF = 0x3f3f3f3f;
int T, N, M, K, X, Y, Z;
int bit[MAXN], head[MAXN], e, next[MAXM], v[MAXM], w[MAXM];
int inq[MAXN][1<<MAX], d[MAXN][1<<MAX], dp[1<<MAX];
queue<int> Q;
void addedge(int x, int y, int z)
{
	v[e] = y; w[e] = z;
	next[e] = head[x]; head[x] = e++;
}
void init()
{
	e = 0;
	memset(head, -1, sizeof(head));
	memset(d, 0x3f, sizeof(d));
	memset(bit, 0, sizeof(bit));
	memset(inq, 0, sizeof(inq));
	memset(dp, 0x3f, sizeof(dp));
}
void spfa()
{
	while (!Q.empty())
	{
		int u = Q.front()&((1<<MAX)-1), st = Q.front()>>MAX;
		Q.pop();
		inq[u][st] = 0;
		for (int i = head[u]; i != -1; i = next[i])
		{
			int nst = st|bit[v[i]];
			if (d[u][st]+w[i] < d[v[i]][nst])
			{
				d[v[i]][nst] = d[u][st]+w[i];
				if (nst == st && !inq[v[i]][nst])
				{
					Q.push(nst<<MAX|v[i]);
					inq[v[i]][nst] = 1;
				}
			}
		}
	}
}
bool check(int st)
{
	int res = 0;
	for (int i = 0; i < K; i++)
	{
		if (st&(1<<i))
			res++;
		if (st&(1<<(K+i)))
			res--;
	}
	return !res;
}
int main()
{
	freopen("put.in", "r", stdin);
	scanf("%d", &T);
	while (T--)
	{
		init();
		scanf("%d%d%d", &N, &M, &K);
		for(int i = 0; i < M; i++)
		{
			scanf("%d%d%d", &X, &Y, &Z);
			addedge(X, Y, Z);
			addedge(Y, X, Z);
		}
		int tot = (1<<(K<<1))-1;
		for (int i = 1; i <= K; i++)
		{
			bit[i] = 1<<(i-1);
			d[i][bit[i]] = 0;
			bit[N-K+i] = 1<<(K+i-1);
			d[N-K+i][bit[N-K+i]] = 0;
		}
		for (int i = 0; i <= tot; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				for (int k = (i-1)&i; k; k = (k-1)&i)	//枚举i的所有子集
					d[j][i] = min(d[j][i], d[j][k|bit[j]]+d[j][(i-k)|bit[j]]);
				if (d[j][i] < INF)
				{
					Q.push(i<<MAX|j);
					inq[j][i] = 1;
				}
			}
			spfa();
		}
		for (int i = 0; i <= tot; i++)
			for (int j = 1; j <= N; j++)
				dp[i] = min(dp[i], d[j][i]);
		for (int i = 0; i <= tot; i++) if (check(i))
			for (int j = (i-1)&i; j; j = (j-1)&i) if (check(j))
				dp[i] = min(dp[i], dp[j]+dp[i-j]);
		if (dp[tot] < INF)
			printf("%d\n", dp[tot]);
		else
			printf("No solution\n");
	}
	return 0;
}
