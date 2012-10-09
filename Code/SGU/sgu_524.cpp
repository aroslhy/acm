//bigoceanlhy	SGU 524	Accepted	895 KB	93 ms	GNU CPP (MinGW, GCC 4)	884 B	2012-10-05 18:46:26
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 400+5;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
int N, x[MAXN];
double newx[MAXN], ans[MAXN];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &x[i]);
	sort(x, x+N);
	double mini = INF;
	for (int j = 0; j < N; j++)
		for (int i = 0; i < j; i++)
		{
			double dis = (double)(x[j]-x[i])/(j-i), pos = (double)x[i]-i*dis, cost = 0;
			for (int k = 0; k < N; k++)
			{
				newx[k] = pos;
				cost += abs((double)x[k]-newx[k]);
				pos += dis;
			}
			if (cost+eps < mini)
			{
				mini = cost;
				for (int k = 0; k < N; k++)
					ans[k] = newx[k];
			}
		}
	printf("%.4lf\n", mini);
	for (int k = 0; k < N; k++)
	{
		if (k)
			printf(" ");
		printf("%.7lf", ans[k]);
	}
	printf("\n");
	return 0;
}
