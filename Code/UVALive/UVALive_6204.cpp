// 6204	Poker End Games	Accepted	C++	0.009	2013-04-23 09:15:28
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 300+5;
int T, A, B;
bool vis[MAXN][MAXN];
void solve(int aa, int bb, double &x, double &y)
{
	if (aa == bb)
	{
		x = 0.5, y = 1;
		return;
	}
	int a = aa, b = bb;
	double p[2] = {0, 1}, q[2] = {0, 1};
	for (; ; )
	{
		int c = min(a, b);
		p[1] *= 2, p[0] *= 2;
		if (b == c)
			b += c, a -= c, p[0] -= 1;
		else
			a += c, b -= c;
		q[0] -= 1;
		q[1] *= 2, q[0] *= 2;
		if (a == aa)
		{
			x = p[0]/(1-p[1]), y = q[0]/(1-q[1]);
			return;
		}
	}
}
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &A, &B);
		int a = A, b = B, p[2] = {0, 1}, q[2] = {0, 1};
		double x, y;
		vis[a][b] = 1;
		for (; ; )
		{
			if (a == b)
			{
				solve(a, b, x, y);
				break;
			}
			int c = min(a, b);
			if (b == c)
				b += c, a -= c;
			else
				a += c, b -= c;
			if (vis[a][b])
			{
				solve(a, b, x, y);
				break;
			}
			vis[a][b] = 1;
		}
		for (; ; )
		{
			if (A == a)
			{
				double ans_p = (x-p[0])/p[1], ans_l = (y-q[0])/q[1];
				printf("Case %d: %.6lf %.6lf\n", cas, ans_l, ans_p);
				break;
			}
			int c = min(A, B);
			p[1] *= 2, p[0] *= 2;
			if (B == c)
				B += c, A -= c, p[0] -= 1;
			else
				A += c, B -= c;
			q[0] -= 1;
			q[1] *= 2, q[0] *= 2;
		}
	}
	return 0;
}
