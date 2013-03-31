// 2013-03-31 21:42:16	Accepted	4530	15MS	216K	434 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T, Q, cmd;
double x, t;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf%d", &x, &Q);
		while (Q--)
		{
			scanf("%d%lf", &cmd, &t);
			if (cmd == 1)
				printf("%.2lf\n", 60*t*(60-x)/60);
			else if (cmd == 2)
				printf("%.2lf\n", 60*t*60/(60-x));
			else
				printf("%.2lf\n", 60*60*12*60/x*t);
		}
	}
	return 0;
}
