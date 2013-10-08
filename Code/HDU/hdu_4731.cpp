// 2013-09-14 18:25:56	Accepted	4731	0MS	812K	991 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T, N, M;
char table[][10] = {
	"a",
	"ab",
	"aab",
	"aabb",
	"aaaba",
	"aaabab",
	"aaababb",
	"aaababbb"
};
char rest[10] = {"ababba"};
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d", &M, &N);
		printf("Case #%d: ", cas);
		if (M == 1)
		{
			for (int i = 0; i < N; i++)
				printf("a");
			printf("\n");
		}
		else if (M == 2)
		{
			if (N < 9)
			{
				printf("%s\n", table[N-1]);
			}
			else
			{
				printf("aaa");
				int n = (N-3)/6;
				for (int i = 0; i < n; i++)
					printf("ababba");
				n = (N-3)%6;
				if (n <= 3)
				{
					for (int i = 0; i < n; i++)
						printf("a");
				}
				else
				{
					for (int i = 0; i < n; i++)
						printf("%c", rest[i]);
				}
				printf("\n");
			}
		}
		else
		{
			for (int i = 0; i < N; i++)
				printf("%c", 'a'+i%3);
			printf("\n");
		}
	}
	return 0;
}
