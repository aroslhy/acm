// Jun 23, 2013 5:09:47 PM	bigoceanlhy	 320A - Magic Numbers	 GNU C++	Accepted	 15 ms	 0 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N;
char s[20];
int main()
{
	scanf("%s", s);
	int len = strlen(s);
	bool flag = 1;
	for (int i = 0; s[i] && flag; )
	{
		if (!strncmp(s+i, "144", 3))
			i += 3;
		else if (!strncmp(s+i, "14", 2))
			i += 2;
		else if (!strncmp(s+i, "1", 1))
			i += 1;
		else
			flag = 0;
	}
	printf(flag ? "YES\n" : "NO\n");
	return 0;
}
