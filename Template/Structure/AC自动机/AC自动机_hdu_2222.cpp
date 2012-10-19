/*
网络流上流传最广的AC自动机模板题，问你目标串中出现了几个模式串
如果一个结点是单词末尾的话out标记为true,在search的时候对于每个结点都向fail指针找，找到out为true的就将其标记为false,且ans+=out
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1000000+5, MAXM = 50+5;
const int MAX_NODE = 500000+5, MAX_CHD = 26;
int T, N;
int chd[MAX_NODE][MAX_CHD], fail[MAX_NODE], out[MAX_NODE];
int ID[1<<8], nv;
char key[MAXM], des[MAXN];
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
				int v = chd[u][i];
				if (v)
				{
					Q.push(v);
					fail[v] = chd[fail[u]][i];
				}
				else
					chd[u][i] = chd[fail[u]][i];
			}
		}
	}
}
int main()
{
	AC_Automaton::Initialize();
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		AC_Automaton::Reset();
		for (int i = 0; i < N; i++)
		{
			scanf("%s", key);
			AC_Automaton::Insert(key);
		}
		AC_Automaton::Construct();
		scanf("%s", des);
		int ans = 0;
		for (int i = 0, u = 0; des[i]; i++)
		{
			u = chd[u][ID[des[i]]];
			for (int t = u; t; )
			{
				ans += out[t];
				out[t] = 0;
				t = fail[t];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
