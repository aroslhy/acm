// 2013-09-17 11:02:04	Accepted	4740	31MS	5212K	1533 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1000+5;
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int N, R, C, D;
bool vis[MAXN][MAXN];
int main()
{
	while (scanf("%d", &N) && N)
	{
		vector<pair<int, int> > step[2];
		for (int i = 0; i < 2; i++)
		{
			scanf("%d%d%d", &R, &C, &D);
			memset(vis, 0, sizeof(vis));
			int x = R, y = C;
			step[i].push_back(make_pair(x, y));
			vis[x][y] = 1;
			for (; ; )
			{
				int tx = x+dir[D][0], ty = y+dir[D][1];
				if (0 <= tx && tx < N && 0 <= ty && ty < N && !vis[tx][ty])
				{
					x = tx, y = ty;
					step[i].push_back(make_pair(x, y));
					vis[x][y] = 1;
				}
				else
				{
					if (!i)
						D = (D+1)%4;
					else
						D = (D+3)%4;
					tx = x+dir[D][0], ty = y+dir[D][1];
					if (0 <= tx && tx < N && 0 <= ty && ty < N && !vis[tx][ty])
					{
						x = tx, y = ty;
						step[i].push_back(make_pair(x, y));
						vis[x][y] = 1;
					}
					else
						break;
				}
			}
		}
		int n = max(step[0].size(), step[1].size());
		int px[2], py[2], ans = -1;
		for (int i = 0; i < n; i++)
		{
			if (i < step[0].size())
				px[0] = step[0][i].first, py[0] = step[0][i].second;
			if (i < step[1].size())
				px[1] = step[1][i].first, py[1] = step[1][i].second;
			if (px[0] == px[1] && py[0] == py[1])
			{
				ans = i;
				break;
			}
		}
		if (ans != -1)
			printf("%d %d\n", px[1], py[1]);
		else
			printf("-1\n");
	}
	return 0;
}
