//bigoceanlhy	SGU 520	Accepted	991 KB	78 ms	GNU CPP (MinGW, GCC 4)	953 B	2012-10-05 18:46:16
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1000+5, MAXM = 2000+5;
const int INF = 0x3f3f3f3f;
int N, M, X, Y;
int mark[MAXN];
int e, head[MAXN], next[MAXM], v[MAXM];
queue<int> Q;
void addedge(int x, int y)
{
	v[e] = y;
	next[e] = head[x]; head[x] = e++;
}
bool dfs(int u)
{
	bool flag = 1;
	for (int i = head[u]; i != -1; i = next[i])
		if (mark[v[i]] == mark[u]+1)
			flag &= dfs(v[i]);
	return !flag;
}
int main()
{
	memset(head, -1, sizeof(head));
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d%d", &X, &Y);
		addedge(X, Y);
		addedge(Y, X);
	}
	Q.push(1);
	mark[1] = 1;
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		for (int i = head[u]; i != -1; i = next[i])
			if (!mark[v[i]])
			{
				mark[v[i]] = mark[u]+1;
				Q.push(v[i]);
			}
	}
	printf("%s\n", dfs(1) ? "Vladimir" : "Nikolay");
	return 0;
}
