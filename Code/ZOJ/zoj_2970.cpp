// 2013-03-20 20:14:09	 Accepted	2970	C++	0	180	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T, N, x;
char s[100];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s%d%d", s, &N, &x);
		int ans = x;
		for (int i = 1; i < N; i++)
		{
			scanf("%d", &x);
			if (s[0] == 'F')
				ans = min(ans, x);
			else
				ans = max(ans, x);
		}
		printf("%d\n", ans);
	}
	return 0;
}
