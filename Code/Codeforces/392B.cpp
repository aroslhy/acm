#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 40+5;
int N, t[3][3];
long long d[MAXN][3][3];
int main()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &t[i][j]);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int a = 0; a < 3; a++)
			for (int b = 0; b < 3; b++) if (b != a)
			{
				int c = 3-a-b;
				d[i][a][b] = min(d[i-1][a][c]+t[a][b]+d[i-1][c][b], d[i-1][a][b]+t[a][c]+d[i-1][b][a]+t[c][b]+d[i-1][a][b]);
			}
	printf("%I64d\n", d[N][0][2]);
	return 0;
}
