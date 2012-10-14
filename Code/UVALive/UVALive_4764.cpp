//4764 	Bing it 	Accepted 	C++ 	0.144 	2012-10-11 11:52:31
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
int N, a[MAXN];
int p[MAXN], d[MAXN];
int main()
{
	while (scanf("%d", &N) && N)
	{
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
			d[i] = d[i-1];
			if (p[a[i]])
				d[i] = max(d[i], d[p[a[i]]]+(a[i] == 999 ? 3 : 1));
			p[a[i]] = i;
		}
		printf("%d\n", d[N]);
	}
	return 0;
}
