// 2013-03-20 20:15:10	 Accepted	2975	C++	90	244	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 250+5;
int T, N, M;
char mat[MAXN][MAXN];// B J H Y N
int id(char x)
{
	if (x == 'B')
		return 0;
	else if (x == 'J')
		return 1;
	else if (x == 'H')
		return 2;
	else if (x == 'Y')
		return 3;
	return 4;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++)
			scanf("%s", mat[i]);
		int ans = 0;
		for (int i = 0; i < N; i++)
			for (int j = i+1; j < N; j++)
			{
				int cnt[5] = {};
				for (int k = 0; k < M; k++)
					if (mat[i][k] == mat[j][k])
						cnt[id(mat[j][k])]++;
				for (int c = 0; c < 5; c++)
					ans += cnt[c]*(cnt[c]-1)/2;
			}
		printf("%d\n", ans);
	}
	return 0;
}
