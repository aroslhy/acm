//Oct 2, 2012 10:30:39 AM 	bigoceanlhy 	229B - Planets 	GNU C++ 	Accepted 	296 ms 	13000 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int MAXN = 100000+5, MAXM = 200000+5;
const int INF = 0x3f3f3f3f;
int N, M, a, b, c, k, t[MAXN];
int e, head[MAXN], next[MAXM], v[MAXM];
int w[MAXM], d[MAXN];
bool inq[MAXN];
queue<int> Q;
map<int, int> wait[MAXN];
void addedge(int x, int y, int z)
{
	v[e] = y; w[e] = z;
	next[e] = head[x]; head[x] = e++;
}
void spfa(int s)
{
	for (int u = 1; u <= N; u++)
		d[u] = (u == s ? 0 : INF);
	Q.push(s);
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		inq[u] = 0;
		for (int i = head[u]; i != -1; i = next[i])
		{
			int x = d[u]+wait[u][d[u]]+w[i];
			if (x < d[v[i]])
			{
				d[v[i]] = x;
				if (!inq[v[i]])
				{
					Q.push(v[i]);
					inq[v[i]] = 1;
				}
			}
		}
	}
}
int main()
{
	memset(head, -1, sizeof(head));
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		addedge(a, b, c);
		addedge(b, a, c);
	}
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &k);
		for (int j = 1; j <= k; j++)
			scanf("%d", &t[j]);
		int last = 1;
		for (int j = k; j >= 1; j--)
		{
			if (j < k && t[j]+1 == t[j+1])
				wait[i][t[j]] = ++last;
			else
				wait[i][t[j]] = (last = 1);
		}
	}
	spfa(1);
	printf("%d\n", d[N] < INF ? d[N] : -1);
	return 0;
}
