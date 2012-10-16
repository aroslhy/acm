//2012-10-16 13:37:54 	Accepted 	3659 	C++ 	1260 	7212 	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 200000+5;
int N, a, b, c;
int u[MAXN], v[MAXN], r[MAXN];
int fa[MAXN], num[MAXN];
long long w[MAXN], pft[MAXN];
bool cmp(const int &a, const int &b)
{
	return w[a] > w[b];
}
int find(int x)
{
	return (fa[x] == x ? x : fa[x] = find(fa[x]));
}
int main()
{
	while (scanf("%d", &N) != EOF)
	{
		for (int i = 1; i < N; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			u[i] = a;
			v[i] = b;
			w[i] = c;
			r[i] = i;
		}
		for (int i = 1; i <= N; i++)
		{
			fa[i] = i;
			num[i] = 1;
			pft[i] = 0;
		}
		sort(r+1, r+N, cmp);
		for (int i = 1; i < N; i++)
		{
			int x = find(u[r[i]]), y = find(v[r[i]]);
			pft[y] = max(pft[x]+w[r[i]]*num[y], pft[y]+w[r[i]]*num[x]);
			num[y] = num[x]+num[y];
			fa[x] = y;
		}
		printf("%lld\n", pft[find(1)]);
	}
	return 0;
}
