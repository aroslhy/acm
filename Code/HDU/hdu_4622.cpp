// 2013-07-31 19:47:52	Accepted	4622	1062MS	824K	1962 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2000+5, MAXM = 10000+5;
const int MAX_NODE = 4000+5, MAX_CHD = 26;
int T, Q, A[MAXM], B[MAXM], r[MAXM], q[MAXM], cnt[MAX_NODE];
int nv, chd[MAX_NODE][MAX_CHD], ml[MAX_NODE], fa[MAX_NODE], id[1<<8];
char s[MAXN];
void Initialize()
{
	for (int i = 0; i < MAX_CHD; i++)
		id['a'+i] = i;
}
void Add(int u, int _ml, int _fa, int v = -1)
{
	ml[u] = _ml; fa[u] = _fa;
	if (v == -1)
		memset(chd[u], -1, sizeof(chd[u]));
	else
		memcpy(chd[u], chd[v], sizeof(chd[v]));
}
bool cmp(const int &a, const int &b)
{
	if (A[a] != A[b])
		return A[a] < A[b];
	else
		return B[a] < B[b];
}
int main()
{
	Initialize();
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		scanf("%d", &Q);
		for (int i = 0; i < Q; i++)
		{
			scanf("%d%d", &A[i], &B[i]);
			A[i]--, B[i]--;
			r[i] = i;
		}
		sort(r, r+Q, cmp);
		cnt[0] = 1;
		for (int k = 0, j = 0; s[k] && j < Q; k++)
		{
			if (A[r[j]] != k)
				continue;
			int sum = 0;
			char *str = s+k;
			nv = 1; Add(0, 0, -1);
			int cur = 0;
			for (int i = 0; str[i]; i++)
			{
				int c = id[str[i]], p = cur;
				cur = nv++; Add(cur, i+1, -1);
				cnt[cur] = 0;
				for (; p != -1 && chd[p][c] == -1; p = fa[p])
				{
					chd[p][c] = cur;
					cnt[cur] += cnt[p];
					sum += cnt[p];
				}
				if (p == -1)
					fa[cur] = 0;
				else
				{
					int q = chd[p][c];
					if (ml[q] == ml[p]+1)
						fa[cur] = q;
					else
					{
						int r = nv++; Add(r, ml[q], fa[q], q);
						cnt[r] = 0;
						ml[r] = ml[p]+1; fa[q] = fa[cur] = r;
						for (; p != -1 && chd[p][c] == q; p = fa[p])
						{
							chd[p][c] = r;
							cnt[r] += cnt[p];
							cnt[q] -= cnt[p];
						}
					}
				}
				for (; j < Q && A[r[j]] == k && B[r[j]] == k+i; j++)
					q[r[j]] = sum;
			}
		}
		for (int i = 0; i < Q; i++)
			printf("%d\n", q[i]);
	}
	return 0;
}
