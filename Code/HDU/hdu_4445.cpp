// 2013-04-23 21:46:47	Accepted	4445	15MS	256K	2249 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 200+5;
const double g = 9.8, eps = 1e-8;
int N, r[MAXN<<2], q[MAXN<<2];
double H, L1, R1, L2, R2, V[MAXN];
double x1, x2, x3, x4, x[MAXN<<2], y[MAXN<<2];
bool calc(double V, double s, double &x, double &y)
{
	if ((g*s*s/(V*V)-H)/sqrt(H*H+s*s)+eps < -1 || (g*s*s/(V*V)-H)/sqrt(H*H+s*s) > 1+eps)
		return 0;
	x = atan(s/H)-acos((g*s*s/(V*V)-H)/sqrt(H*H+s*s));
	y = acos((g*s*s/(V*V)-H)/sqrt(H*H+s*s))+atan(s/H);
	return 1;
}
bool cmpx(const int &a, const int &b)
{
	if (abs(x[a]-x[b]) > eps)
		return x[a]+eps < x[b];
	else
		return (a&1) < (b&1);
}
bool cmpy(const int &a, const int &b)
{
	if (abs(y[a]-y[b]) > eps)
		return y[a]+eps < y[b];
	else
		return (a&1) < (b&1);
}
int main()
{
	while (scanf("%d", &N) && N)
	{
		scanf("%lf%lf%lf%lf%lf", &H, &L1, &R1, &L2, &R2);
		int c = 0, e = 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%lf", &V[i]);
			if (calc(V[i], L2, x1, x4))
			{
				if (calc(V[i], R2, x2, x3))
				{
					r[c] = c, x[c++] = x1;
					r[c] = c, x[c++] = x2;
					r[c] = c, x[c++] = x3;
					r[c] = c, x[c++] = x4;
				}
				else
				{
					r[c] = c, x[c++] = x1;
					r[c] = c, x[c++] = x4;
				}
			}
			if (calc(V[i], L1, x1, x4))
			{
				if (calc(V[i], R1, x2, x3))
				{
					q[e] = e, y[e++] = x1;
					q[e] = e, y[e++] = x2;
					q[e] = e, y[e++] = x3;
					q[e] = e, y[e++] = x4;
				}
				else
				{
					q[e] = e, y[e++] = x1;
					q[e] = e, y[e++] = x4;
				}
			}
		}
		sort(r, r+c, cmpx);
		int cur = 0, d = e;
		double p;
		for (int i = 0; i < c; i++)
		{
			if (!(r[i]&1))
			{
				if (cur == 0)
					p = x[r[i]];
				cur++;
			}
			else
			{
				if (cur == 1)
				{
					q[e] = e, y[e++] = p;
					q[e] = e, y[e++] = x[r[i]];
				}
				cur--;
			}
		}
		sort(q, q+e, cmpy);
		bool flag = 1;
		int ans = cur = 0;
		for (int i = 0; i < e; i++)
		{
			if (q[i] >= d)
			{
				if (!(q[i]&1))
					flag = 0;
				else
					flag = 1;
			}
			else
			{
				if (!(q[i]&1))
					cur++;
				else
					cur--;
			}
			if (flag)
				ans = max(ans, cur);
		}
		printf("%d\n", ans);
	}
	return 0;
}
