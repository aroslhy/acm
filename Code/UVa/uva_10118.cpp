//10118 	Free Candies 	Accepted 	C++ 	0.204 	2012-12-07 13:16:00
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 40+5;
int N, X[MAXN][4];
int f[MAXN][MAXN][MAXN][MAXN], cnt[1<<20];
int main()
{
	for (int i = 1; i < (1<<20); i++)
		for (int j = 0; j < 20; j++)
			if (i&(1<<j))
				cnt[i]++;
	while (scanf("%d", &N))
	{
		if (!N)
			break;
		for (int i = 1; i <= N; i++)
			for (int j = 0; j < 4; j++)
			{
				scanf("%d", &X[i][j]);
				X[i][j]--;
			}
		memset(f, -1, sizeof(f));
		f[0][0][0][0] = 0;
		int ans = 0;
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++)
				for (int k = 0; k <= N; k++)
					for (int l = 0; l <= N; l++)
					{
						int &df = f[i][j][k][l], x;
						if (df == -1)
							continue;
						x = df^(1<<X[i+1][0]);
						if (i < N && cnt[x] < 5)
							f[i+1][j][k][l] = x;
						x = df^(1<<X[j+1][1]);
						if (j < N && cnt[x] < 5)
							f[i][j+1][k][l] = x;
						x = df^(1<<X[k+1][2]);
						if (k < N && cnt[x] < 5)
							f[i][j][k+1][l] = x;
						x = df^(1<<X[l+1][3]);
						if (l < N && cnt[x] < 5)
							f[i][j][k][l+1] = x;
						ans = max(ans, i+j+k+l-cnt[df]);
					}
		printf("%d\n", ans/2);
	}
	return 0;
}
