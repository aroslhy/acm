#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 750, MAXN = MAX+5, MAXM = MAX*4+5;
int T, N, X, Y, num[MAXN];
double ans, c[MAXM][MAXN];
int main()
{
	freopen("put.in", "r", stdin);
	freopen("put.out", "w", stdout);
	for (int i = 1; i <= MAX; i++)
		num[i] = num[i-1]+4*i-3;
	c[0][0] = 1;
	for (int i = 1; i <= MAX*4; i++)
		c[i][0] = c[i-1][0]/2;
	for (int i = 0; i <= MAX*4; i++)
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i-1][j]+c[i-1][j-1])/2;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d%d", &N, &X, &Y);
		int l = lower_bound(num+1, num+MAX, N)-num;
		int n = num[l]-num[l-1], m = N-num[l-1];
		if (abs(X)+abs(Y) <= 2*(l-1)-2)
			ans = 1;
		else if (abs(X)+abs(Y) > 2*l-2)
			ans = 0;
		else
		{
			if (m-(2*l-2) > Y)
				ans = 1;
			else if (min(m, 2*l-2) <= Y)
				ans = 0;
			else
			{
				int y = Y+1;
				if (m > 2*l-2)
				{
					y -= m-(2*l-2);
					m -= (m-(2*l-2))*2;
				}
				ans = 0;
				for (int i = y; i <= min(m, 2*l-2); i++)
					ans += c[m][i];
			}
		}
		printf("Case #%d: %.6lf\n", cas, ans);
	}
	return 0;
}
