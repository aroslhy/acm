/*
题意：求至少经过K条边，到达终点的最短路（K<=50）。
思路：因为K<=500，所以每个节点最多扩展成50个节点，最后一个节点表示到达该节点时经过的边数（收集到的木材/10）已经满足K值对应的要求。然后spfa，每个节点表示为(编号,经过的边数)。
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 5000+5, MAXM = 200000+5, MAXK = 50+5;
const int INF = 0x3f3f3f3f;
int N, M, A, B, C, S, T, K, mk;
int e, head[MAXN], next[MAXM], v[MAXM];
int d[MAXN][MAXK], w[MAXM];
bool inq[MAXN][MAXK];
queue<pair<int, int> > Q;
void addedge(int x, int y, int z)
{
	v[e] = y; w[e] = z;
	next[e] = head[x]; head[x] = e++;
}
void spfa(int s)
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= mk; j++)
			d[i][j] = INF;
	Q.push(make_pair(s, 0));
	while (!Q.empty())
	{
		int u = Q.front().first, k = Q.front().second;
		Q.pop();
		inq[u][k] = 0;
		for (int i = head[u]; i != -1; i = next[i])
		{
			int l = k+(k < mk ? 1 : 0);
			if (d[u][k]+w[i] < d[v[i]][l])
			{
				d[v[i]][l] = d[u][k]+w[i];
				if (!inq[v[i]][l])
				{
					Q.push(make_pair(v[i], l));
					inq[v[i]][l] = 1;
				}
			}
		}
	}
}
void init()
{
	e = 0;
	memset(head, -1, sizeof(head));
}
int main()
{
	while (scanf("%d%d", &N, &M) != EOF)
	{
		init();
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d", &A, &B, &C);
			addedge(A, B, C);
			addedge(B, A, C);
		}
		scanf("%d%d%d", &S, &T, &K);
		mk = (K-1)/10+1;
		spfa(S);
		printf("%d\n", d[T][mk] < INF ? d[T][mk] : -1);
	}
	return 0;
}
