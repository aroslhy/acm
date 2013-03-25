// aroslhy	SPOJ BTCODE_G	Accepted	6451 KB	3530 ms	C++ (g++ 4.0.0-8)	936 B	2013-03-25 18:13:01
#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN = 100000+5, MAXM = 200000+5;
using namespace std;
int N, Q, X, Y, cmd, p[MAXN], c[MAXN];
int e, head[MAXN], v[MAXM], next[MAXM];
void addedge(int x, int y)
{
	v[e] = y;
	next[e] = head[x]; head[x] = e++;
}
int find(int x)
{
	if (x == p[x])
		return x;
	else
		return p[x] = find(p[x]);
}
int main()
{
	e = 0;
	memset(head, -1, sizeof(head));
	scanf("%d", &N);
	for (int i = 1; i < N; i++)
	{
		scanf("%d%d", &X, &Y);
		addedge(X, Y);
		addedge(Y, X);
	}
	for (int i = 0; i < N; i++)
		p[i] = i;
	scanf("%d", &Q);
	memset(c, 0,sizeof(c));
	while (Q--)
	{
		scanf("%d%d%d", &cmd, &X, &Y);
		if (cmd == 1)
		{
			c[X] = Y;
			for (int i = head[X]; i != -1; i = next[i])
			{
				int f = find(v[i]);
				if (c[f] == Y)
					p[f] = X;
			}
		}
		else
		{
			int u = find(X), v = find(Y);
			if (u == v)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
