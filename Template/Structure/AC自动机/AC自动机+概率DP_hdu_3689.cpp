/*
字符集中有一些字符，给出每个字符的出现概率（它们的和保证为1），再给出一个串S，问任给一个长度为N的字符串A（只能包含字符集中的字符），使得S是A的子串的概率。
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1000+5, MAXM = 10+5;
const int INF = 0x3f3f3f3f;
const int MAX_NODE = MAXN, MAX_CHD = 26;
int N, M;
int chd[MAX_NODE][MAX_CHD], fail[MAX_NODE], out[MAX_NODE];
int ID[1<<8], nv;
double P[MAX_CHD], d[MAXN][MAX_NODE];
char ch[5], word[MAXM];
queue<int> Q;
namespace AC_Automaton
{
	void Initialize()
	{
		fail[0] = 0;
		for (int i = 0; i < MAX_CHD; i++)
			ID[i+'a'] = i;
	}
	void Reset()
	{
		memset(chd[0], 0, sizeof(chd[0]));
		nv = 1;
	}
	void Insert(char *pat)
	{
		int u = 0;
		for (int i = 0; pat[i]; i++)
		{
			int c = ID[pat[i]];
			if (!chd[u][c])
			{
				memset(chd[nv], 0, sizeof(chd[nv]));
				out[nv] = 0;
				chd[u][c] = nv++;
			}
			u = chd[u][c];
		}
		out[u]++;
	}
	void Construct()
	{
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
				}
				else
					v = chd[fail[u]][i];
			}
		}
	}
}
int main()
{
	AC_Automaton::Initialize();
	while (scanf("%d%d", &N, &M))
	{
		if (!N && !M)
			break;
		memset(P, 0, sizeof(P));
		memset(d, 0, sizeof(d));
		AC_Automaton::Reset();
		for (int i = 0; i < N; i++)
		{
			scanf("%s", ch);
			scanf("%lf", &P[ID[ch[0]]]);
		}
		scanf("%s", word);
		AC_Automaton::Insert(word);
		AC_Automaton::Construct();
		d[0][0] = 1;
		for (int i = 0; i < M; i++)
			for (int u = 0; u < nv; u++) if (d[i][u] && !out[u])
				for (int j = 0; j < MAX_CHD; j++)
					d[i+1][chd[u][j]] += d[i][u]*P[j];
		int len = strlen(word);
		double ans = 0;
		for (int i = len; i <= M; i++)
			ans += d[i][len];
		printf("%.2lf%s\n", ans*100, "\%");
	}
	return 0;
}
