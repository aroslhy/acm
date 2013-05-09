// 2013-05-09 10:00:34	Accepted	4534	718MS	2608K	2850 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100+5;
const int MAX_NODE = 1600+5, MAX_CHD = 26;
const int INF = 0x3f3f3f3f;
int T, N, G, cnt, d[2][MAX_NODE][1<<8], f[2][MAX_NODE][1<<8];
int chd[MAX_NODE][MAX_CHD], fail[MAX_NODE], out[MAX_NODE], mark[MAX_NODE], id[1<<7], nv;
bool del[MAX_NODE];
char str[MAXN];
void Initialize()
{
	fail[0] = 0;
	for (int i = 0; i < MAX_CHD; i++)
		id[i+'a'] = i;
}
void Reset()
{
	memset(chd[0], 0, sizeof(chd[0]));
	nv = 1;
}
void Insert(char *pat, int val)
{
	int u = 0;
	for (int i = 0; pat[i]; i++)
	{
		int c = id[pat[i]];
		if (!chd[u][c])
		{
			memset(chd[nv], 0, sizeof(chd[nv]));
			out[nv] = 0, mark[nv] = 0, del[nv] = 0;
			chd[u][c] = nv++;
		}
		u = chd[u][c];
	}
	if (val == 999)
		mark[u] = 1<<cnt, cnt++;
	else if (val == -999)
		del[u] = 1;
	else
		out[u] = val;
}
void Construct()
{
	queue<int> Q;
	for (int i = 0; i < MAX_CHD; i++)
		if (chd[0][i])
		{
			fail[chd[0][i]] = 0;
			Q.push(chd[0][i]);
		}
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		for (int i = 0; i < MAX_CHD; i++)
		{
			int &v = chd[u][i];
			if (v)
			{
				Q.push(v);
				fail[v] = chd[fail[u]][i];
				out[v] += out[fail[v]];
				mark[v] |= mark[fail[v]];
				del[v] |= del[fail[v]];
			}
			else
				v = chd[fail[u]][i];
		}
	}
}
int main()
{
	Initialize();
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		Reset();
		scanf("%d", &N);
		cnt = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%s%d", str, &G);
			Insert(str, G);
		}
		Construct();
		scanf("%s", str);
		int tot = (1<<cnt)-1, len = strlen(str), s = 1, t = 0;
		for (int u = 0; u < nv; u++)
			for (int a = 0; a <= tot; a++)
			{
				d[t][u][a] = INF;
				f[t][u][a] = -INF;
			}
		d[t][0][0] = f[t][0][0] = 0;
		for (int i = 0; i < len; i++)
		{
			swap(s, t);
			for (int u = 0; u < nv; u++)
				for (int a = 0; a <= tot; a++)
				{
					d[t][u][a] = d[s][u][a]+1;
					f[t][u][a] = f[s][u][a];
				}
			for (int u = 0; u < nv; u++)
				for (int a = 0; a <= tot; a++)
				{
					int v = chd[u][id[str[i]]], b = a|mark[v];
					if (!del[v])
					{
						if (d[s][u][a] < d[t][v][b])
						{
							d[t][v][b] = d[s][u][a];
							f[t][v][b] = f[s][u][a]+out[v];
						}
						else if (d[s][u][a] == d[t][v][b])
							f[t][v][b] = max(f[t][v][b], f[s][u][a]+out[v]);
					}
				}
		}
		int mini = INF, maxi = -INF;
		for (int u = 0; u < nv; u++)
		{
			if (d[t][u][tot] < mini)
			{
				mini = d[t][u][tot];
				maxi = f[t][u][tot];
			}
			else if (d[t][u][tot] == mini)
				maxi = max(maxi, f[t][u][tot]);
		}
		if (mini < INF)
			printf("Case %d: %d %d\n", cas, mini, maxi);
		else
			printf("Case %d: Banned\n", cas);
	}
	return 0;
}
