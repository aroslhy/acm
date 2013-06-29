// Jun 29, 2013 11:08:31 AM	bigoceanlhy	 321B - Ciel and Duel	 GNU C++	Accepted	 15 ms	 300 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 200+5, MAXM = 20400+5;
const int INF = 0x3f3f3f3f;
int N, M, stgJ[MAXN], stgC[MAXN];
char posJ[MAXN][5];
int e, s, t, n;
int v[MAXM], next[MAXM], head[MAXN];
int cap[MAXM], f;
int cost[MAXM], d[MAXN], c;
int pv[MAXN], pe[MAXN];
bool inq[MAXN];
queue<int> Q;
void addedge(int u_, int v_, int c_, int w_)
{
	v[e] = v_; cap[e] = c_; cost[e] = w_;
	next[e] = head[u_]; head[u_] = e++;
	v[e] = u_; cap[e] = 0; cost[e] = -w_;
	next[e] = head[v_]; head[v_] = e++;
}
void mincostflow(int &ans)
{
	f = 0; c = 0;
	for (;;)
	{
		memset(inq, 0, sizeof(inq));
		for (int i = 1; i <= n; i++)
			d[i] = (i == s ? 0 : INF);
		Q.push(s); inq[s] = 1;
		while (!Q.empty())
		{
			int u = Q.front(); Q.pop();
			inq[u] = 0;
			for (int e = head[u]; e != -1; e = next[e])
				if(cap[e] && d[v[e]] > d[u]+cost[e])
				{
					d[v[e]] = d[u]+cost[e];
					if (!inq[v[e]])
						Q.push(v[e]), inq[v[e]] = 1;
					pv[v[e]] = u; pe[v[e]] = e;
				}
		}
		if (d[t] == INF) break;
		int a = INF;
		for (int v = t; v != s; v = pv[v])
			a = min(a, cap[pe[v]]);
		for (int v = t; v != s; v = pv[v])
		{
			cap[pe[v]] -= a;
			cap[pe[v]^1] += a;
		}
		f += a;
		c += d[t]*a;
		ans = max(ans, -c);
	}
}
int main()
{
	memset(head, -1, sizeof(head));
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%s%d", posJ[i], &stgJ[i]);
	for (int i = 1; i <= M; i++)
		scanf("%d", &stgC[i]);
	n = N+M, s = ++n, t = ++n;
	for (int i = 1; i <= M; i++)
	{
		addedge(s, i, 1, 0);
		for (int j = 1; j <= N; j++)
		{
			if (posJ[j][0] == 'A' && stgC[i] >= stgJ[j])
				addedge(i, M+j, 1, stgJ[j]-stgC[i]);
			else if (posJ[j][0] == 'D' && stgC[i] > stgJ[j])
				addedge(i, M+j, 1, 0);
		}
	}
	for (int i = 1; i <= N; i++)
		addedge(M+i, t, 1, 0);
	int tmp = 0;
	mincostflow(tmp);
	int ans = tmp;
	if (M > N && f == N)
	{
		int x = ++n;
		for (int u = 1; u < n; u++)
			for (int i = head[u]; i != -1; i = next[i]) if (!(i&1) && !cap[i])
				swap(cap[i], cap[i^1]);
		for (int i = 1; i <= M; i++)
			addedge(i, x, 1, -stgC[i]);
		addedge(x, t, M-N, 0);
		mincostflow(tmp);
		ans = max(ans, -c);
	}
	printf("%d\n", ans);
	return 0;
}
