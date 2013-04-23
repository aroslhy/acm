// aroslhy	URAL 1804	Accepted	189 KB	31 ms	G++ 4.7.2	786 B	2013-04-23 17:01:57
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T, x, y;
char s[10];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		gets(s);
		scanf("The Machinegunners played %s game, scored %d goals, and conceded %d goals.", s, &x, &y);
		if (s[0] == 'h')
		{
			for (int i = 0; i <= 30; i++) if ((i+x == y && i >= y) || (i+x > y))
			{
				printf("%d ", i);
				break;
			}
			for (int i = 30; i >= 0; i--) if ((i+x == y+30 && i <= y) || i+x < y+30)
			{
				printf("%d\n", i);
				break;
			}
		}
		else
		{
			for (int i = 0; i <= 30; i++) if ((i+x == y && x >= 0) || (i+x > y))
			{
				printf("%d ", i);
				break;
			}
			for (int i = 30; i >= 0; i--) if ((i+x == y+30 && x <= 30) || i+x < y+30)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
