//2012-10-05 09:50:40	Accepted	4125	2031MS	23476K	2167 B	C++	Aros
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 600000+5, MAXM = 2400000+5, MAXL = 7000+5;
int T, N;
int hole[MAXN], r[MAXN];
int Tr[MAXN<<2];
int fail[MAXL], len;
char seq[MAXM], pat[MAXL];
bool cmp(const int a, const int b)
{
	return hole[a] < hole[b];
}
void get_fail(char *pat)
{
	int len2 = strlen(pat);
	fail[0] = -1;
	for (int i = 1, j = -1; i < len2; i++)
	{
		while (j != -1 && pat[j+1] != pat[i])
			j = fail[j];
		if (pat[j+1] == pat[i])
			j++;
		fail[i] = j;
	}
}
int kmp(char *str, char *pat)
{
	int len1 = strlen(str), len2 = strlen(pat);
	int p = 0, q = 0;
	int cnt = 0;
	while (p < len1)
	{
		if (str[p] == pat[q])
			p++, q++;
		else if (q == 0)
			p++; //pat[0]匹配失败,从 str 下个字符开始
		else
			q = fail[q-1]+1; //pat[p]匹配失败,右移 pat 串
		if (q == len2)
			cnt++; //记录子串匹配次数
	}
	return cnt;
}
void Build(int idx, int L, int R)
{
	if (L == R)
	{
		Tr[idx] = r[R];
		return;
	}
	int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
	Build(left, L, mid);
	Build(right, mid+1, R);
	Tr[idx] = min(Tr[left], Tr[right]);
}
int Query(int idx, int L, int R, int l, int r)
{
	if (l <= L && R <= r)
		return Tr[idx];
	int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
	int res = N+1;
	if (l <= mid)
		res = min(res, Query(left, L, mid, l, r));
	if (mid < r)
		res = min(res, Query(right, mid+1, R, l, r));
	return res;
}
void dfs(int x, int y)
{
	int mid = Query(1, 1, N, x, y);
	if (hole[mid] > x)
	{
		seq[len++] = '0'+(hole[mid]&1);
		dfs(x, hole[mid]-1);
	}
	seq[len++] = '0'+(hole[mid]&1);
	if (hole[mid] < y)
	{
		dfs(hole[mid]+1, y);
		seq[len++] = '0'+(hole[mid]&1);
	}
}
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &hole[i]);
			r[i] = i;
		}
		sort(r+1, r+1+N, cmp);
		Build(1, 1, N);
		len = 0;
		dfs(1, N);
		seq[len] = 0;
		scanf("%s", pat);
		get_fail(pat);
		printf("Case #%d: %d\n", cas, kmp(seq, pat));
	}
	return 0;
}
