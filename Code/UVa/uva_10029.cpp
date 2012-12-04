//10029 	Edit Step Ladders 	Accepted 	C++ 	1.020 	2012-12-04 13:10:59
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 25000+5, MAXM = 16+5;
const int MAXHASH = 100003;
int e, head[MAXHASH], next[MAXN], w[MAXN];
char word[MAXM], tmp[MAXM], v[MAXN][MAXM];
unsigned int elfhash(char *url)
{
	unsigned int h = 0, g;
	for (; *url; url++)
	{
		h = (h<<4)+*url;
		g = h&0xf0000000;
		if (g)
			h ^= g>>24;
		h &= ~g;
	}
	return h%MAXHASH;
}
void add(char *x, int y)
{
	int h = elfhash(x);
	strcpy(v[e], x); w[e] = y;
	next[e] = head[h]; head[h] = e++;
}
int find(char *s)
{
	int h = elfhash(s);
	for (int i = head[h]; i != -1; i = next[i])
		if (!strcmp(s, v[i]))
			return w[i];
	return 0;
}
int main()
{
	memset(head, -1, sizeof(head));
	int ans = 0;
	while (scanf("%s", word) != EOF)
	{
		int maxi = 1, len = strlen(word);
		for (int i = 0; i <= len; i++)
			for (char j = 'a'; j <= 'z'; j++)
			{
				for (int k = 0; k <= len; k++)
				{
					if (k < i)
						tmp[k] = word[k];
					else if (k == i)
						tmp[k] = j;
					else
						tmp[k] = word[k-1];
				}
				tmp[len+1] = 0;
				maxi = max(maxi, find(tmp)+1);
			}
		for (int i = 0; i < len; i++)
			for (char j = 'a'; j <= 'z'; j++)
			{
				for (int k = 0; k < len; k++)
				{
					if (k == i)
						tmp[k] = j;
					else
						tmp[k] = word[k];
				}
				tmp[len] = 0;
				maxi = max(maxi, find(tmp)+1);
			}
		for (int i = 0; i < len; i++)
		{
			for (int k = 0; k < len-1; k++)
			{
				if (k < i)
					tmp[k] = word[k];
				else if (k >= i)
					tmp[k] = word[k+1];
			}
			tmp[len-1] = 0;
			maxi = max(maxi, find(tmp)+1);
		}
		add(word, maxi);
		ans = max(ans, maxi);
	}
	printf("%d\n", ans);
	return 0;
}
