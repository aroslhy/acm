// Jun 29, 2013 11:20:13 AM	bigoceanlhy	 321A - Ciel and Robot	 GNU C++	Accepted	 31 ms	 0 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5;
int a, b, Dx[MAXN], Dy[MAXN];
char s[MAXN];
int main()
{
	while (scanf("%d%d%s", &a, &b, s) != EOF)
	{
		int x = 0, y = 0, len = strlen(s);
		for (int i = 0; i < len; i++)
		{
			if (s[i] == 'U')
				y++;
			else if (s[i] == 'D')
				y--;
			else if (s[i] == 'L')
				x--;
			else if (s[i] == 'R')
				x++;
			Dx[i+1] = x, Dy[i+1] = y;
		}
		bool flag = 0;
		for (int i = 0; i <= len && !flag; i++)
		{
			if (Dx[len] && Dy[len] && !((a-Dx[i])%Dx[len]) && !((b-Dy[i])%Dy[len]) && (a-Dx[i])/Dx[len] == (b-Dy[i])/Dy[len] && (b-Dy[i])/Dy[len] >= 0)
			{
				printf("Yes\n");
				flag = 1;
			}
			else if (Dx[len] && !Dy[len] && !((a-Dx[i])%Dx[len]) && !(b-Dy[i]) && (a-Dx[i])/Dx[len] >= 0)
			{
				printf("Yes\n");
				flag = 1;
			}
			else if (!Dx[len] && Dy[len] && !(a-Dx[i]) && !((b-Dy[i])%Dy[len]) && (b-Dy[i])/Dy[len] >= 0)
			{
				printf("Yes\n");
				flag = 1;
			}
			else if (!Dx[len] && !Dy[len] && Dx[i] == a && Dy[i] == b)
			{
				printf("Yes\n");
				flag = 1;
			}
		}
		if (!flag)
			printf("No\n");
	}
	return 0;
}
