#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
int M, L, R;
int sum[3][MAXN], num[3];
char s[MAXN];
int main()
{
	scanf("%s", s+1);
	int n = strlen(s+1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
			sum[j][i] = sum[j][i-1];
		sum[s[i]-'x'][i]++;
//		printf("%d %d %d\n", sum[0][i], sum[1][i], sum[2][i]);
	}
	scanf("%d", &M);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d%d", &L, &R);
		int mini = n, maxi = 0;
		for (int j = 0; j < 3; j++)
		{
			num[j] = sum[j][R]-sum[j][L-1];
			mini = min(mini, num[j]);
		}
		for (int j = 0; j < 3; j++)
		{
			num[j] -= mini;
			maxi = max(maxi, num[j]);
		}
		if (R-L < 2 || maxi <= 1)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

