//4255 	Guess 	Accepted 	C++ 	0.012 	2013-01-21 12:49:03
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 10+5, MAXM = 100+5;
int T, N, g[MAXN][MAXN], ind[MAXN], B[MAXN];
char str[MAXM];
bool vis[MAXN];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%s", &N, str);
		memset(g, 0, sizeof(g));
		memset(ind, 0, sizeof(ind));
		for (int p = 0, i = 1; i <= N; i++)
			for (int j = i; j <= N; j++, p++)
			{
				if (str[p] == '+')
				{
					g[i-1][j] = 1;
					ind[j]++;
				}
				else if (str[p] == '-')
				{
					g[j][i-1] = 1;
					ind[i-1]++;
				}
			}
		memset(vis, 0, sizeof(vis));
		vector<pair<int, int> > V;
		queue<int> Q;
		int c;
		for (int i = 0; ; i++)
		{
			for (int j = 0; j <= N; j++) if (!vis[j] && !ind[j])
			{
				vis[j] = 1;
				Q.push(j);
				if (!j)
					c = i;
				V.push_back(make_pair(j, i));
			}
			if (Q.empty())
				break;
			while (!Q.empty())
			{
				int u = Q.front(); Q.pop();
				for (int v = 0; v <= N; v++) if (g[u][v])
					ind[v]--;
			}
		}
		for (int i = 0; i <= N; i++)
			B[V[i].first] = V[i].second-c;
		for (int i = 1; i <= N; i++)
		{
			if (i > 1)
				printf(" ");
			printf("%d", B[i]-B[i-1]);
		}
		printf("\n");
	}
	return 0;
}
