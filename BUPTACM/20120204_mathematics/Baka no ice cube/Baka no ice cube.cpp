#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

int main()
{
	int n, m, k;
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	while (scanf("%d%d%d", &n, &m, &k) != EOF)
	{
		double ans = 0;
		if (k < m)
		{
			printf("%.4lf\n", ans);
			continue;
		}
		for (int i = 0; i <= (int)((k - m) / n); i++)
		{
			double tmp = (double)m;
			for (int j = 1; j <= k - i * n - 1; j++)
				tmp *= j;
			for (int j = 1; j <= i; j++)
				tmp /= j;
			for (int j = 1; j <= m - i; j++)
				tmp /= j;
			for (int j = 1; j <= k - i * n - m; j++)
				tmp /= j;
			ans += (1 - 2 * (i % 2)) * tmp;
		}
		for (int i = 1; i <= m; i++)
			ans /= n;
		printf("%.4lf\n", ans);
	}
	
	return 0;
}
