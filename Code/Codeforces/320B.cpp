// Jun 23, 2013 6:01:29 PM	bigoceanlhy	 320B - Ping-Pong (Easy Version)	 GNU C++	Accepted	 15 ms	 100 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100+5, MAXM = 10000+5;
const int INF = 0x3f3f3f3f;
int N, cmd, A, B, a[MAXN], b[MAXN], fa[MAXN];
int e, head[MAXN], next[MAXM], v[MAXM], d[MAXN];
bool inq[MAXN];
queue<int> Q;
void addedge(int x, int y)
{
	v[e] = y;
	next[e] = head[x]; head[x] = e++;
}
void spfa(int s, int n)
{
	for (int i = 1; i <= n; i++)
		d[i] = (i == s ? 0 : INF);
	memset(inq, 0, sizeof(inq));
	Q.push(s);
	inq[s] = 1;
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		inq[u] = 0;
		for(int e = head[u]; e != -1; e = next[e])
			if(d[v[e]] > d[u])
			{
				d[v[e]] = d[u];
				if(!inq[v[e]])
				{
					Q.push(v[e]);
					inq[v[e]] = 1;
				}
			}
	}
}
int main()
{
	memset(head, -1, sizeof(head));
	scanf("%d", &N);
	int n = 0;
	while (N--)
	{
		scanf("%d%d%d", &cmd, &A, &B);
		if (cmd == 1)
		{
			n++;
			a[n] = A, b[n] = B;
			for (int i = 1; i < n; i++)
			{
				if ((a[i] < A && A < b[i]) || (a[i] < B && B < b[i]))
					addedge(n, i);
				if ((A < a[i] && a[i] < B) || (A < b[i] && b[i] < B))
					addedge(i, n);
			}
		}
		else
		{
			spfa(A, n);
			printf("%s\n", d[B] < INF ? "YES" : "NO");
		}
	}
	return 0;
}
