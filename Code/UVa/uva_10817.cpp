//10817 	Headmaster's Headache 	Accepted 	C++ 	0.312 	2012-12-13 11:14:13
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 16;
const int MAXN = 120+5;
const int INF = 0x3f3f3f3f;
int S, M, N, C[MAXN];
int d[MAXN][1<<MAX];
char line[1<<10];
void add(int &u, int pos)
{
	if (((u&(3<<(pos<<1)))>>(pos<<1)) < 3)
		u += (1<<(pos<<1));
}
int main()
{
	while (scanf("%d%d%d", &S, &M, &N) && S)
	{
		gets(line);
		int s = 0, tot = (1<<(S<<1)), sta = 0, fin = 0, ans = INF;
		vector<int> list[MAXN];
		for (int i = 1; i <= M+N; i++)
		{
			gets(line);
			int p = 0, x;
			while (*(line+p) == ' ')
				p++;
			sscanf(line+p, "%d", &C[i]);
			while (isgraph(*(line+p)))
				p++;
			while (*(line+p) == ' ')
				p++;
			while (sscanf(line+p, "%d", &x) != EOF)
			{
				list[i].push_back(x-1);
				while (isgraph(*(line+p)))
					p++;
				while (*(line+p) == ' ')
					p++;
			}
			if (i <= M)
			{
				for (vector<int>::iterator it = list[i].begin(); it != list[i].end(); it++)
					add(s, *it);
				sta += C[i];
			}
		}
		fill(d[M], d[M]+tot, INF);
		d[M][s] = sta;
		for (int i = M; i < M+N; i++)
		{
			fill(d[i+1], d[i+1]+tot, INF);
			for (int u = s; u < tot; u++) if (d[i][u] < INF)
			{
				d[i+1][u] = min(d[i+1][u], d[i][u]);
				int v = u;
				for (vector<int>::iterator it = list[i+1].begin(); it != list[i+1].end(); it++)
					add(v, *it);
				d[i+1][v] = min(d[i+1][v], d[i][u]+C[i+1]);
			}
		}
		for (int i = 0; i < S; i++)
			fin |= (1<<((i<<1)+1));
		for (int u = s; u < tot; u++)
			if ((u&fin) == fin)
				ans = min(ans, d[M+N][u]);
		printf("%d\n", ans);
	}
	return 0;
}
