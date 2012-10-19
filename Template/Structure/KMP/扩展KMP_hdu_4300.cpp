/*
这道题问的就是将1个串如何变为stringA+stringB的形式，使得stringA是stringB经过映射得到相同的串。映射那步其实没有什么价值，假设str为原串s经过映射后得到的串，我们可以以str为模式串，以s为原串做一次扩展KMP，得到extend数组，extend[i]表示原串以第i开始与模式串的前缀的最长匹配。经过O(n)的枚举，我们可以得到,若extend[i]+i=len且i>=extend[i]时，表示stringB即为该点之前的串，stringA即为该点之前的str串，最后输出即可。
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 50+5;
const int INF = 0x3f3f3f3f;
int T, extend[MAXN], next[MAXN];
char S[MAXM], tex1[MAXN], tex2[MAXN], match[1<<8];
void get_next(char *pat)
{
	int len2 = strlen(pat), k = 0;
	next[0] = len2;
	while (k+1 < len2 && pat[k] == pat[k+1])
		k++;
	next[1] = k;
	for(int id = 1, i = 2; i < len2; i++)
	{
		int u = i-id;
		if (next[u]+i >= next[id]+id)
		{
			int j = next[id]+id-i;
			if (j < 0)
				j = 0;
			while (j+i < len2 && pat[j] == pat[j+i])
				j++;
			next[i] = j;
			id = i;
		}
		else
			next[i] = next[u];
	}
}
void ext_kmp(char *str, char *pat)
{
	get_next(pat);
	int len1 = strlen(str), len2 = strlen(pat), k = 0;
	while (k < len1 && k < len2 && str[k] == pat[k])
		k++;
	extend[0] = k;
	for (int id = 0, i = 1; i < len1; i++)
	{
		int u = i-id;
		if (i+next[u] < extend[id]+id)
			extend[i] = next[u];
		else
		{
			int j = extend[id]+id-i;
			if (j < 0)
				j = 0;
			while (j+i < len1 && str[j+i] == pat[j])
				j++;
			extend[i] = j;
			id = i;
		}
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s%s", S, tex1);
		int lenS = strlen(S);
		for (int i = 0; i < lenS; i++)
			match[(int)S[i]] = 'a'+i;
		int len = strlen(tex1);
		for (int i = 0; i < len; i++)
			tex2[i] = match[(int)tex1[i]];
		tex2[len] = 0;
		ext_kmp(tex1, tex2);
		for (int i = 0; i <= len; i++)
		{
			if ((i+extend[i] == len && i*2 >= len) || i == len)
			{
				for (int j = 0; j < i; j++)
					printf("%c", tex1[j]);
				for (int j = 0; j < i; j++)
					printf("%c", tex2[j]);
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
