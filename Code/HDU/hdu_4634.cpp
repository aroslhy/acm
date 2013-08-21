// 2013-08-21 12:52:44	Accepted	4634	171MS	20932K	2182 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>
using namespace std;
const int MAXN = 200+5;
const int MAX = 7, dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int N, M;
char mat[MAXN][MAXN], key[MAXN][MAXN], vis[MAXN][MAXN][1<<MAX][4];
struct Node
{
	int x, y, state, dir, step;
	Node(int _x, int _y, int _state, int _dir, int _step) : x(_x), y(_y), state(_state), dir(_dir), step(_step) {}
};
int main()
{
	for (int cas = 1; scanf("%d%d", &N, &M) != EOF; cas++)
	{
		int cnt = 0;
		deque<Node> Q;
		for (int i = 1; i <= N; i++)
		{
			scanf("%s", mat[i]+1);
			for (int j = 1; j <= M; j++)
			{
				if (mat[i][j] == 'S')
				{
					for (int k = 0; k < 4; k++)
						Q.push_front(Node(i, j, 0, k, 1));
				}
				else if (mat[i][j] == 'K')
				{
					key[i][j] = 1<<cnt;
					cnt++;
				}
			}
		}
		int ans = -1;
		while (!Q.empty())
		{
			Node u = Q.front();
			Q.pop_front();
			if (vis[u.x][u.y][u.state][u.dir] == cas)
				continue;
			vis[u.x][u.y][u.state][u.dir] = cas;
			if (mat[u.x][u.y] == 'E' && u.state == (1<<cnt)-1)
			{
				ans = u.step;
				break;
			}
			Node v = u;
			v.x += dir[v.dir][0], v.y += dir[v.dir][1];
			if (1 <= v.x && v.x <= N && 1 <= v.y && v.y <= M)
			{
				if (mat[v.x][v.y] == 'E' && v.state == (1<<cnt)-1)
					Q.push_front(v);
				else if (mat[v.x][v.y] == 'K')
				{
					v.state |= key[v.x][v.y];
					Q.push_front(v);
				}
				else if (mat[v.x][v.y] == 'R')
				{
					v.dir = 0;
					Q.push_front(v);
				}
				else if (mat[v.x][v.y] == 'D')
				{
					v.dir = 1;
					Q.push_front(v);
				}
				else if (mat[v.x][v.y] == 'L')
				{
					v.dir = 2;
					Q.push_front(v);
				}
				else if (mat[v.x][v.y] == 'U')
				{
					v.dir = 3;
					Q.push_front(v);
				}
				else if (mat[v.x][v.y] == '#')
				{
					u.step++;
					if (mat[u.x][u.y] != 'R' && mat[u.x][u.y] != 'D' && mat[u.x][u.y] != 'L' && mat[u.x][u.y] != 'U')
					{
						for (int k = 0; k < 4; k++)
						{
							u.dir = k;
							Q.push_back(u);
						}
					}
				}
				else
					Q.push_front(v);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
