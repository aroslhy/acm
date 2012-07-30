#include <cstdio>

int main()
{
	freopen("data.in", "w", stdout);
	for (int n = 1; n <= 18; n++)
		for(int m = 1; m <= 9; m++)
			for (int k = 1; k <= n * m; k++)
				printf("%d %d %d\n", n, m, k);
	return 0;
}
