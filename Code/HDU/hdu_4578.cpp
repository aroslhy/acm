// 2013-08-18 14:11:59	Accepted	4578	2343MS	5352K	3304 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
const long long MOD = 10007;
int N, M, ope, X, Y, C;
int Tr[MAXN<<2][3], mark[MAXN<<2][2];
void Build(int idx, int L, int R)
{
	Tr[idx][2] = Tr[idx][1] = Tr[idx][0] = 0;
	mark[idx][0] = 1, mark[idx][1] = 0;
	if (L == R)
		return;
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	Build(left, L, mid);
	Build(right, mid+1, R);
}
void PushDown(int idx, int L, int R)
{
	if (mark[idx][0] == 1 && mark[idx][1] == 0)
		return;
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	int a1 = mark[idx][0], a2 = a1*a1%MOD, a3 = a2*a1%MOD;
	int b1 = mark[idx][1], b2 = b1*b1%MOD, b3 = b2*b1%MOD;
	Tr[left][2] = Tr[left][2]*a3%MOD;
	Tr[left][1] = Tr[left][1]*a2%MOD;
	Tr[left][0] = Tr[left][0]*a1%MOD;
	Tr[left][2] = (Tr[left][2]+3*b1*Tr[left][1]+3*b2*Tr[left][0]+(mid-L+1)*b3)%MOD;
	Tr[left][1] = (Tr[left][1]+2*b1*Tr[left][0]+(mid-L+1)*b2)%MOD;
	Tr[left][0] = (Tr[left][0]+(mid-L+1)*b1)%MOD;
	mark[left][0] = (mark[left][0]*a1)%MOD, mark[left][1] = (mark[left][1]*a1+b1)%MOD;
	Tr[right][2] = Tr[right][2]*a3%MOD;
	Tr[right][1] = Tr[right][1]*a2%MOD;
	Tr[right][0] = Tr[right][0]*a1%MOD;
	Tr[right][2] = (Tr[right][2]+3*b1*Tr[right][1]+3*b2*Tr[right][0]+(R-mid)*b3)%MOD;
	Tr[right][1] = (Tr[right][1]+2*b1*Tr[right][0]+(R-mid)*b2)%MOD;
	Tr[right][0] = (Tr[right][0]+(R-mid)*b1)%MOD;
	mark[right][0] = (mark[right][0]*a1)%MOD, mark[right][1] = (mark[right][1]*a1+b1)%MOD;
	mark[idx][0] = 1, mark[idx][1] = 0;
}
void Update(int idx, int L, int R, int l, int r, int ope, int c)
{
	if (l <= L && R <= r)
	{
		int c1 = c, c2 = c*c%MOD, c3 = c2*c%MOD;
		if (ope == 1)
		{
			Tr[idx][2] = (Tr[idx][2]+3*c1*Tr[idx][1]+3*c2*Tr[idx][0]+(R-L+1)*c3)%MOD;
			Tr[idx][1] = (Tr[idx][1]+2*c1*Tr[idx][0]+(R-L+1)*c2)%MOD;
			Tr[idx][0] = (Tr[idx][0]+(R-L+1)*c1)%MOD;
			mark[idx][1] = (mark[idx][1]+c)%MOD;
		}
		else if (ope == 2)
		{
			Tr[idx][2] = Tr[idx][2]*c3%MOD;
			Tr[idx][1] = Tr[idx][1]*c2%MOD;
			Tr[idx][0] = Tr[idx][0]*c1%MOD;
			mark[idx][0] = (mark[idx][0]*c)%MOD, mark[idx][1] = (mark[idx][1]*c)%MOD;

		}
		else
		{
			Tr[idx][2] = (R-L+1)*c3%MOD;
			Tr[idx][1] = (R-L+1)*c2%MOD;
			Tr[idx][0] = (R-L+1)*c1%MOD;
			mark[idx][0] = 0, mark[idx][1] = c;
		}
		return;
	}
	PushDown(idx, L, R);
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	if (l <= mid)
		Update(left, L, mid, l, r, ope, c);
	if (mid < r)
		Update(right, mid+1, R, l, r, ope, c);
	Tr[idx][2] = (Tr[left][2]+Tr[right][2])%MOD;
	Tr[idx][1] = (Tr[left][1]+Tr[right][1])%MOD;
	Tr[idx][0] = (Tr[left][0]+Tr[right][0])%MOD;
}
int Query(int idx, int L, int R, int l, int r, int c)
{
	if (l <= L && R <= r)
		return Tr[idx][c-1];
	PushDown(idx, L, R);
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	int ql = 0, qr = 0;
	if (l <= mid)
		ql = Query(left, L, mid, l, r, c);
	if (mid < r)
		qr = Query(right, mid+1, R, l, r, c);
	return (ql+qr)%MOD;
}
int main()
{
	while (scanf("%d%d", &N, &M))
	{
		if (!N && !M)
			break;
		Build(1, 1, N);
		while (M--)
		{
			scanf("%d%d%d%d", &ope, &X, &Y, &C);
			if (ope < 4)
				Update(1, 1, N, X, Y, ope, C);
			else
				printf("%d\n", Query(1, 1, N, X, Y, C));
		}
	}
	return 0;
}
