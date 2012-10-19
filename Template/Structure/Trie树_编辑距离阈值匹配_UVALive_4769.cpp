/*
求字典中存在前缀与查询串编辑距离小于阈值的词的个数
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <iostream>
using namespace std;
const int MAXM = 10+5;
const int MAX_NODE = 3000000+5, MAX_CHD = 26;
int N, M, edth;
int nv, chd[MAX_NODE][MAX_CHD], out[MAX_NODE], ID[1<<8];
int vis[MAX_NODE], mark[MAX_NODE];
char word[MAXM];
namespace Trie
{
	void Initialize()
	{
		for (int k = 0; k < MAX_CHD; k++)
			ID[k+'a'] = k;
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
			out[u]++;
		}
	}
}
void dfs(int u, char *p, int d, int c)
{
	vis[u] = c;
	if (!(*p))
		mark[u] = c;
	if (mark[u] == c)
		return;
	if (chd[u][ID[*p]])
		dfs(chd[u][ID[*p]], p+1, d, c);
	if (d)
	{
		for (int i = 0; i < MAX_CHD; i++) if (chd[u][i])
			dfs(chd[u][i], p, d-1, c);
		for (int i = 0; i < MAX_CHD; i++) if (chd[u][i])
			dfs(chd[u][i], p+1, d-1, c);
		dfs(u, p+1, d-1, c);
	}
}
int calc(int u, int c)
{
	if (vis[u] != c)
		return 0;
	if (mark[u] == c)
		return out[u];
	int res = 0;
	for (int i = 0; i < MAX_CHD; i++) if (chd[u][i])
		res += calc(chd[u][i], c);
	return res;
}
int main()
{
	scanf("%d", &N);
	Trie::Initialize();
	Trie::Reset();
	for (int i = 1; i <= N; i++)
	{
		scanf("%s", word);
		Trie::Insert(word);
	}
	scanf("%d", &M);
	for (int i = 1; i <= M; i++)
	{
		scanf("%s%d", word, &edth);
		dfs(0, word, edth, i);
		printf("%d\n", calc(0, i));
	}
	return 0;
}
