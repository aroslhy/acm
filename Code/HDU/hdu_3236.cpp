//2012-10-18 18:29:37	Accepted	3236	2062MS	644K	1394 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 300+5, MAX1 = 500+5, MAX2 = 50+5;
int N, V[2], P[MAXN], H[MAXN], S[MAXN];
int d[2][MAX1][MAX2][2];
inline void setzero(int x)
{
	for (int j = 0; j <= V[0]; j++)
		for (int k = 0; k <= V[1]; k++)
			for (int l = 0; l < 2; l++)
				d[x][j][k][l] = -1;
}
int main()
{
	for (int cas = 1; scanf("%d%d%d", &V[0], &V[1], &N); cas++)
	{
		if (!V[0] && !V[1] && !N)
			break;
		for (int i = 1; i <= N; i++)
			scanf("%d%d%d", &P[i], &H[i], &S[i]);
		int s = 0, t = 1;
		setzero(t);
		d[t][0][0][0] = 0;
		for (int i = 0; i < N; i++)
		{
			swap(s, t);
			setzero(t);
			for (int j = 0; j <= V[0]; j++)
				for (int k = 0; k <= V[1]; k++)
					for (int l = 0; l < 2; l++) if (d[s][j][k][l] != -1)
					{
						if (P[i+1]+j <= V[0])
							d[t][j+P[i+1]][k][l] = max(d[t][j+P[i+1]][k][l], d[s][j][k][l]+H[i+1]);
						if (P[i+1]+k <= V[1])
							d[t][j][k+P[i+1]][l] = max(d[t][j][k+P[i+1]][l], d[s][j][k][l]+H[i+1]);
						if (!l)
							d[t][j][k][1] = max(d[t][j][k][1], d[s][j][k][l]+H[i+1]);
						if (!S[i+1])
							d[t][j][k][l] = max(d[t][j][k][l], d[s][j][k][l]);
					}
		}
		int ans = -1;
		for (int j = 0; j <= V[0]; j++)
			for (int k = 0; k <= V[1]; k++)
				ans = max(ans, d[t][j][k][1]);
		printf("Case %d: %d\n\n", cas, ans);
	}
	return 0;
}
