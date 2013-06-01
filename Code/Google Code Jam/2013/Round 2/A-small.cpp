#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100+5, MAXM = 2000000+5;
const int INF = 0x3f3f3f3f;

int T, M;
long long N, O, E, P;

int e, s, t, n;
int v[MAXM], next[MAXM], head[MAXN];
long long cap[MAXM], f;
long long cost[MAXM], d[MAXN], c;
int pv[MAXN], pe[MAXN];
bool inq[MAXN];
queue<int> Q;
void addedge(int u_, int v_, int c_, int w_)
{
	v[e] = v_; cap[e] = c_; cost[e] = w_;
	next[e] = head[u_]; head[u_] = e;
	e++;
	v[e] = u_; cap[e] = 0; cost[e] = -w_;
	next[e] = head[v_]; head[v_] = e;
	e++;
}
void mincostflow()
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
		long long a = INF;
		for (int v = t; v != s; v = pv[v])
			a = min(a, cap[pe[v]]);
		for (int v = t; v != s; v = pv[v])
		{
			cap[pe[v]] -= a;
			cap[pe[v]^1] += a;
		}
		f += a;
		c += d[t]*a;
	}
}
int main()
{
	freopen("put.in", "r", stdin);
	freopen("put.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		memset(cap, 0, sizeof(cap));
		memset(cost, 0, sizeof(cost));
		memset(head, -1, sizeof(head));
		e = 0;
		scanf("%lld%d", &N, &M);
		s = N+1, t = n = N+2;
		long long sum = 0;
		for (int i = 0; i < M; i++)
		{
			scanf("%lld%lld%lld", &O, &E, &P);
			long long x = E-O;
			sum += (2*N+1-x)*x/2*P;
			addedge(s, O, P, 0);
			addedge(E, t, P, 0);
		}
		for (int i = 1; i < N; i++)
			for (int j = i+1; j <= N; j++)
			{
				long long x = j-i;
				addedge(i, j, INF, (2*N+1-x)*x/2);
			}
		mincostflow();
//		printf("%d %d\n", c, f);
		printf("Case #%d: %lld\n", cas, sum-c);
	}
	return 0;
}
