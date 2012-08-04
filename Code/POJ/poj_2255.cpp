#include<cstdio>
#include<cstring>
using namespace std;
char tree[3][30]; int len;
void Build(int n, char *s1, char *s2, char *s)
{
	if (n <= 0)
		return;
	int p = strchr(s2, s1[0]) - s2;
	Build(p, s1+1, s2, s);
	Build(n-p-1, s1+p+1, s2+p+1, s+p);
	s[n-1] = s1[0];
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (scanf("%s", tree[0]) != EOF)
	{
		scanf("%s", tree[1]);
		len = strlen(tree[0]);
		Build(len, tree[0], tree[1], tree[2]);
		tree[2][len] = '\0';
		printf("%s\n", tree[2]);
	}
	return 0;
}
