//Oct 16, 2012 11:21:40 AM 	bigoceanlhy 	234B - Reading 	GNU C++ 	Accepted 	31 ms 	100 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1000+5;
int N, K, a[MAXN], id[MAXN];
bool cmp(const int &x, const int &y)
{
	return a[x] > a[y];
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
		id[i] = i;
	}
	sort(id+1, id+1+N, cmp);
	printf("%d\n", a[id[K]]);
	for (int i = 1; i <= K; i++)
	{
		if (i > 1)
			printf(" ");
		printf("%d", id[i]);
	}
	printf("\n");
	return 0;
}
