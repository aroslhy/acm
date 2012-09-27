//bigoceanlhy	2774	Accepted	3924K	407MS	G++	1513B	2012-09-27 13:45:46
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 200000+5;
int len, sa[MAXN], height[MAXN], rank[MAXN], tmp[MAXN], top[MAXN];
char str[MAXN];
void makesa()
{
	int lena = len < 256 ? 256 : len;
	memset(top, 0, lena*sizeof(int));
	for (int i = 0; i < len; i++)
		top[rank[i] = str[i]&(-1)]++;
	for (int i = 1; i < lena; i++)
		top[i] += top[i-1];
	for (int i = 0; i < len ; i++)
		sa[--top[rank[i]]] = i;
	for (int k = 1; k < len; k <<= 1)
	{
		for (int i = 0; i < len; i++)
		{
			int j = sa[i]-k;
			if (j < 0)
				j += len;
			tmp[top[rank[j]]++] = j;
		}
		int j = sa[tmp[0]] = top[0] = 0;
		for (int i = 1; i < len; i++)
		{
			if (rank[tmp[i]] != rank[tmp[i-1]] || rank[tmp[i]+k] != rank[tmp[i-1]+k])
				top[++j] = i;
			sa[tmp[i]] = j;
		}
		memcpy(rank, sa , len*sizeof(int));
		memcpy(sa , tmp, len*sizeof(int));
		if (j+1 >= len)
			break;
	}
}
void lcp()
{
	height[0] = 0;
	for (int i = 0, k = 0, j = rank[0]; i+1 < len; i++, k++)
		while (k >= 0 && str[i] != str[sa[j-1]+k])
		{
			height[j] = k--;
			j = rank[sa[j]+1];
		}
}
int main()
{
    scanf("%s", str);
    int mid = len = strlen(str), ans = 0;
    str[len++] = '$';
    scanf("%s", str+len);
    len += strlen(str+len)+1;
    makesa(); lcp();
    for (int i = 1; i < len; i++)
        if ((sa[i-1] < mid && sa[i] > mid) || (sa[i-1] > mid && sa[i] < mid))
            ans = max(ans, height[i]);
    printf("%d\n", ans);
    return 0;
}
