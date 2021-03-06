/*
求长度为n的字符串中包含至少k个给出的关键字的字符串的个数，结果模MOD。
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

//MAX_NODE = StringNumber*StringLength
const int MAX_NODE = 100+5;
//字符集大小,一般字符形式的题26个
const int MAX_CHD = 26;
//每个节点的儿子,即当前节点的状态转移
int chd[MAX_NODE][MAX_CHD];
//记录题目给的关键数据(点的权值)
int out[MAX_NODE];
//传说中的fail指针
int fail[MAX_NODE];
//字母对应的ID
int ID[1<<8];
//已使用节点个数
int nv;
//队列,用于广度优先计算fail指针
queue<int> Q;

//特定题目需要
const int MAXN = 25+5;
const int MOD = 20090717;
int N, M, K, d[2][MAX_NODE][1<<10];

namespace AC_Automaton
{
	//初始化,计算字母对应的儿子ID,如:'a'->0 ... 'z'->25
	void Initialize()
	{
		fail[0] = 0;
		for (int i = 0; i < MAX_CHD; i++)
			ID[i+'a'] = i;
	}
	//重新建树需先Reset
	void Reset()
	{
		memset(chd[0], 0, sizeof(chd[0]));
		nv = 1;
	}
	//将权值为key的字符串a插入到trie中
	void Insert(char *pat, int key)
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
		out[u] = key;
	}
	//建立AC自动机,确定每个节点的权值以及状态转移
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
					//以下一行代码要根据题目所给out的含义来写
					out[v] |= out[fail[v]];
				}
				else
					v = chd[fail[u]][i];
			}
		}
	}
}

//解题
int solve()
{
	int tot = (1<<M)-1, ans = 0, s = 0, t = 1;
	memset(d[t], 0, sizeof(d[t]));
	d[t][0][0] = 1;
	for (int i = 0; i < N; i++)
	{
		swap(s, t);
		memset(d[t], 0, sizeof(d[t]));
		for (int u = 0; u < nv; u++)
			for (int a = 0; a <= tot; a++) if (d[s][u][a])
				for (int k = 0; k < MAX_CHD; k++)
				{
					int v = chd[u][k], b = (a|out[v]);
					d[t][v][b] = (d[t][v][b]+d[s][u][a])%MOD;
				}
	}
	for (int a = 0; a <= tot; a++)
	{
		int cnt = 0;
		for (int i = 0; i < M; i++)
			if (a&(1<<i))
				cnt++;
		if (cnt >= K)
		{
			for (int u = 0; u < nv; u++)
				ans = (ans+d[t][u][a])%MOD;
		}
	}
	return ans;
}

int main()
{
	AC_Automaton::Initialize();
	while (scanf("%d%d%d", &N, &M, &K) != EOF)
	{
		if (!N && !M && !K)
			break;
		AC_Automaton::Reset();
		for (int i = 0; i < M; i++)
		{
			char temp[11];
			scanf("%s", temp);
			AC_Automaton::Insert(temp, 1<<i);
		}
		AC_Automaton::Construct();
		printf("%d\n", solve());
	}
	return 0;
}
