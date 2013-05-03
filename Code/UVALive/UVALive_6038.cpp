// 6038	Grandpa's Walk	Accepted	C++	0.025	2013-05-03 02:25:18
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 50+5;
int T, N, M, A[MAXN][MAXN], d[MAXN][MAXN];
int D(int x, int y)
{
	if (d[x][y] != -1)
		return d[x][y];
	d[x][y] = 0;
	bool flag = 0;
	if (A[x-1][y] && A[x][y] > A[x-1][y])
		d[x][y] += D(x-1, y), flag = 1;
	if (A[x+1][y] && A[x][y] > A[x+1][y])
		d[x][y] += D(x+1, y), flag = 1;
	if (A[x][y-1] && A[x][y] > A[x][y-1])
		d[x][y] += D(x, y-1), flag = 1;
	if (A[x][y+1] && A[x][y] > A[x][y+1])
		d[x][y] += D(x, y+1), flag = 1;
	if (!flag)
		return d[x][y] = 1;
	return d[x][y];
}
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d", &N, &M);
		memset(A, 0, sizeof(A));
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				scanf("%d", &A[i][j]);
		memset(d, -1, sizeof(d));
		int ans = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
			{
				D(i, j);
				if (A[i][j] >= A[i-1][j] && A[i][j] >= A[i+1][j] && A[i][j] >= A[i][j-1] && A[i][j] >= A[i][j+1])
					ans += D(i, j);
			}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
