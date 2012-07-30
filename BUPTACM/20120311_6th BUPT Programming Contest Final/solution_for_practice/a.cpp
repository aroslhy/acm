#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct sp
{
	int r, c, h;
	sp() {}
	sp(int x, int y, int z): r(x), c(y), h(z) {}
	bool operator<(const sp &rhs) const
	{
		return h > rhs.h;
	}
};

int R, C;
int h[110][110];
bool vis[110][110];
int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};
int ans, curh;
priority_queue<sp> heap;

void dfs(int r, int c)
{
	if (r<0||r>=R||c<0||c>=C) return;
	if (vis[r][c]) return;
	vis[r][c] = 1;
	heap.push(sp(r, c, h[r][c]));
	if (curh >= h[r][c])
		ans += curh-h[r][c];
	else
		return;
	for (int i = 0; i < 4; ++i)
		dfs(r+dr[i], c+dc[i]);
}

int main()
{
	int i, j, k, r, c;
	while (~scanf("%d%d", &R, &C))
	{
		memset(vis, 0, sizeof(vis));
		for (r = 0; r < R; ++r)
			for (c = 0; c < C; ++c)
				scanf("%d", &h[r][c]);
		for (r = 0; r < R; ++r)
		{
			heap.push(sp(r, 0, h[r][0]));
			vis[r][0] = 1;
			heap.push(sp(r, C-1, h[r][C-1]));
			vis[r][C-1] = 1;
		}
		for (c = 1; c < C-1; ++c)
		{
			heap.push(sp(0, c, h[0][c]));
			vis[0][c] = 1;
			heap.push(sp(R-1, c, h[R-1][c]));
			vis[R-1][c] = 1;
		}
		ans = 0;
		sp cur;
		while (!heap.empty())
		{
			cur = heap.top(); heap.pop();
			curh = cur.h;
			for (i = 0; i < 4; ++i)
				dfs(cur.r+dr[i], cur.c+dc[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
