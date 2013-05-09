// aroslhy	URAL 1920	Accepted	213 KB	31 ms	G++ 4.7.2	1299 B	2013-05-09 10:04:30
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5;
int N, L;
bool mat[MAXN][MAXN], vis[MAXN][MAXN];
inline void StepIn(int x, int y)
{
	printf("%d %d\n", x, y);
	vis[x][y] = 1;
}
int main()
{
	freopen("put.in", "r", stdin);
	scanf("%d%d", &N, &L);
	if (N*N < L || L%2)
		printf("Unsuitable device\n");
	else
	{
		printf("Overwhelming power of magic\n");
		for (int i = 1; i <= N && L; i++, L -= 2)
			mat[i][1] = mat[i][2] = 1;
		for (int i = N; i > 1; i -= 2)
			for (int j = 3; j <= N && L; j++, L -= 2)
				mat[i][j] = mat[i-1][j] = 1;
		for (int j = N; j > 3 && L; j -= 2, L -= 2)
			mat[1][j] = mat[1][j-1] = 1;
		int x = 1, y = 1, dx = 1, dy = 0;
		StepIn(x, y);
		for (; ; )
		{
			if (x+dx == 1 && y+dy == 1)
				break;
			if (mat[x+dx][y+dy] && !vis[x+dx][y+dy])
			{
				x += dx, y += dy;
				if (x == 2 && y%2 == 0 && y > 2 && dx == 0 && dy == -1)
				{
					if (mat[x-1][y])
					{
						StepIn(x-1, y+1);
						StepIn(x-1, y);
					}
				}
				StepIn(x, y);
			}
			else if (dx == 1 && dy == 0)
				dx = 0, dy = 1;
			else if (dx == 0 && dy == 1)
			{
				x -= 1;
				StepIn(x, y);
				dx = 0, dy = -1;
			}
			else if (dx == 0 && dy == -1)
			{
				x -= 1;
				StepIn(x, y);
				if (x == 1)
					dx = 0, dy = -1;
				else
					dx = 0, dy = 1;
			}
		}
	}
	return 0;
}
