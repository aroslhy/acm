#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 100+5;
int N, K, a[MAXN], b;
map<int, int> d[MAXN];
void update(int i, int j, int x)
{
	map<int, int>::iterator it = d[i].find(j);
	if (it == d[i].end())
		d[i].insert(make_pair(j, x));
	else
		it->second = max(it->second, x);
}
int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	d[0].insert(make_pair(0, 0));
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &b);
		b = K*b-a[i];
		for (map<int, int>::iterator it = d[i-1].begin(); it != d[i-1].end(); it++)
		{
			update(i, it->first, it->second);
			update(i, it->first+b, it->second+a[i]);
		}
	}
	map<int, int>::iterator it = d[N].find(0);
	if (it->second)
		printf("%d\n", it->second);
	else
		printf("-1\n");
	return 0;
}

