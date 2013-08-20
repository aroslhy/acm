// 2013-08-20 17:11:18	Accepted	4678	171MS	21152K	1644 B	C++	Aros
#pragma comment(linker,"/STACK:102400000,102400000")
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5, MAXM = 1000000+5;
const int dir[][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
int T, N, M, K, X, Y;
int cnt, mat[MAXN][MAXN], clr[MAXN][MAXN], sum[MAXM];
void dfs(int x, int y)
{
	if (clr[x][y] != -1)
		return;
	if (mat[x][y] == 0)
	{
		clr[x][y] = cnt;
		for (int k = 0; k < 8; k++)
		{
			int xx = x+dir[k][0], yy = y+dir[k][1];
			if (0 <= xx && xx < N && 0 <= yy && yy < M)
				dfs(xx, yy);
		}
	}
	else
	{
		clr[x][y] = cnt;
		sum[cnt]++;
	}
}
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d%d", &N, &M, &K);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				mat[i][j] = 0;
				clr[i][j] = -1;
			}
		for (int i = 1; i <= K; i++)
		{
			scanf("%d%d", &X, &Y);
			mat[X][Y] = -1;
			for (int k = 0; k < 8; k++)
			{
				int x = X+dir[k][0], y = Y+dir[k][1];
				if (0 <= x && x < N && 0 <= y && y < M && mat[x][y] != -1)
					mat[x][y]++;
			}
		}
		cnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) if (clr[i][j] == -1 && mat[i][j] == 0)
			{
				sum[++cnt] = 1;
				dfs(i, j);
			}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) if (clr[i][j] == -1 && mat[i][j] != -1)
			{
				sum[++cnt] = 0;
				dfs(i, j);
			}
		int sg = 0;
		for (int i = 1; i <= cnt; i++)
		{
			if (sum[i]%2)
				sg ^= 1;
			else
				sg ^= 2;
		}
		printf("Case #%d: %s\n", cas, sg ? "Xiemao" : "Fanglaoshi");
	}
	return 0;
}
