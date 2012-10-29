//2012-10-29 21:07:26	Accepted	4433	687MS	4552K	3686 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define MAX 10
#define up(x) (x+1)%MAX
#define down(x) (x+9)%MAX
#define id(x) x-'0'
using namespace std;
const int MAXN = 1000+5;
const int INF = 0x3f3f3f3f;
int g[MAX][MAX][MAX][MAX][MAX][MAX], f[MAXN][MAX][MAX];
char cur[MAXN], pas[MAXN];
bool vis[MAX][MAX][MAX];
struct Node
{
	int p[3];
	Node(){}
	Node(int x, int y, int z)
	{
		p[0] = x; p[1] = y; p[2] = z;
	}
};
int main()
{
	queue<pair<Node, int> > Q;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < MAX; k++)
			{
				memset(vis, 0, sizeof(vis));
				Q.push(make_pair(Node(i, j, k), 0));
				vis[i][j][k] = 1;
				while (!Q.empty())
				{
					Node u = Q.front().first;
					int step = Q.front().second;
					Q.pop();
					g[i][j][k][u.p[0]][u.p[1]][u.p[2]] = step;
					if (!vis[up(u.p[0])][u.p[1]][u.p[2]])
					{
						Q.push(make_pair(Node(up(u.p[0]), u.p[1], u.p[2]), step+1));
						vis[up(u.p[0])][u.p[1]][u.p[2]] = 1;
					}
					if (!vis[u.p[0]][up(u.p[1])][u.p[2]])
					{
						Q.push(make_pair(Node(u.p[0], up(u.p[1]), u.p[2]), step+1));
						vis[u.p[0]][up(u.p[1])][u.p[2]] = 1;
					}
					if (!vis[u.p[0]][u.p[1]][up(u.p[2])])
					{
						Q.push(make_pair(Node(u.p[0], u.p[1], up(u.p[2])), step+1));
						vis[u.p[0]][u.p[1]][up(u.p[2])] = 1;
					}
					if (!vis[up(u.p[0])][up(u.p[1])][u.p[2]])
					{
						Q.push(make_pair(Node(up(u.p[0]), up(u.p[1]), u.p[2]), step+1));
						vis[up(u.p[0])][up(u.p[1])][u.p[2]] = 1;
					}
					if (!vis[u.p[0]][up(u.p[1])][up(u.p[2])])
					{
						Q.push(make_pair(Node(u.p[0], up(u.p[1]), up(u.p[2])), step+1));
						vis[u.p[0]][up(u.p[1])][up(u.p[2])] = 1;
					}
					if (!vis[up(u.p[0])][up(u.p[1])][up(u.p[2])])
					{
						Q.push(make_pair(Node(up(u.p[0]), up(u.p[1]), up(u.p[2])), step+1));
						vis[up(u.p[0])][up(u.p[1])][up(u.p[2])] = 1;
					}
					if (!vis[down(u.p[0])][u.p[1]][u.p[2]])
					{
						Q.push(make_pair(Node(down(u.p[0]), u.p[1], u.p[2]), step+1));
						vis[down(u.p[0])][u.p[1]][u.p[2]] = 1;
					}
					if (!vis[u.p[0]][down(u.p[1])][u.p[2]])
					{
						Q.push(make_pair(Node(u.p[0], down(u.p[1]), u.p[2]), step+1));
						vis[u.p[0]][down(u.p[1])][u.p[2]] = 1;
					}
					if (!vis[u.p[0]][u.p[1]][down(u.p[2])])
					{
						Q.push(make_pair(Node(u.p[0], u.p[1], down(u.p[2])), step+1));
						vis[u.p[0]][u.p[1]][down(u.p[2])] = 1;
					}
					if (!vis[down(u.p[0])][down(u.p[1])][u.p[2]])
					{
						Q.push(make_pair(Node(down(u.p[0]), down(u.p[1]), u.p[2]), step+1));
						vis[down(u.p[0])][down(u.p[1])][u.p[2]] = 1;
					}
					if (!vis[u.p[0]][down(u.p[1])][down(u.p[2])])
					{
						Q.push(make_pair(Node(u.p[0], down(u.p[1]), down(u.p[2])), step+1));
						vis[u.p[0]][down(u.p[1])][down(u.p[2])] = 1;
					}
					if (!vis[down(u.p[0])][down(u.p[1])][down(u.p[2])])
					{
						Q.push(make_pair(Node(down(u.p[0]), down(u.p[1]), down(u.p[2])), step+1));
						vis[down(u.p[0])][down(u.p[1])][down(u.p[2])] = 1;
					}
				}
			}
	while (scanf("%s%s", cur+1, pas+1) != EOF)
	{
		int n = strlen(pas+1);
		strcpy(cur+n+1, "00");
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				f[0][i][j] = g[0][id(cur[1])][id(cur[2])][0][i][j];
		for (int i = 1; i <= n; i++)
			for (int a = 0; a < MAX; a++)
				for (int b = 0; b < MAX; b++)
				{
					f[i][a][b] = INF;
					for (int c = 0; c < MAX; c++)
						for (int d = 0; d < MAX; d++)
							f[i][a][b] = min(f[i][a][b], f[i-1][c][d]+g[c][d][id(cur[i+2])][id(pas[i])][a][b]);
				}
		printf("%d\n", f[n][0][0]);
	}
	return 0;
}
