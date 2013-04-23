// 2013-04-23 16:55:54	 Accepted	3689	C++	540	292	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 3000+5, MAXM = 10000+5;
int N, T, t[MAXN], s[MAXN], r[MAXN], d[2][MAXM];
bool cmp(const int &a, const int &b)
{
	return s[a]*t[b] < s[b]*t[a];
}
int main()
{
	while (scanf("%d%d", &N, &T) != EOF)
	{
		for (int i = 1; i <= N; i++)
		{
			scanf("%d%d", &t[i], &s[i]);
			r[i] = i;
		}
		sort(r+1, r+1+N, cmp);
		int a = 1, b = 0;
		memset(d[b], 0, sizeof(d[b]));
		for (int i = 1; i <= N; i++)
		{
			swap(a, b);
			for (int j = 1; j <= T; j++)
			{
				d[b][j] = d[a][j];
				if (j >= t[r[i]])
					d[b][j] = max(d[b][j], d[a][j-t[r[i]]]+j*s[r[i]]);
			}
		}
		printf("%d\n", d[b][T]);
	}
	return 0;
}
