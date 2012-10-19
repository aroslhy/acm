/*
题意：就是给你一些长方体，求这些长方体相交至少3次的体积和。
思路：对z轴扫描线，每次在xy平面对x轴扫描线、对y轴离散化用线段树求面积并，再把分段求得的体积加和。
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2000+5, MAXM = 2000+5, MAXP = 2000000+5;
int T, N, X[MAXM], Y[MAXM], Z[MAXM], rx[MAXM], ry[MAXM], rz[MAXM];
int Tr[MAXN<<2], Tcov[MAXN<<2], mark[MAXN<<2];
int match[MAXP], toy[MAXN];
bool cmpz(const int a, const int b)
{
	return Z[a] < Z[b];
}
bool cmpx(const int a, const int b)
{
	return X[a] < X[b];
}
bool cmpy(const int a, const int b)
{
	return Y[a] < Y[b];
}
//void Init(int idx, int L, int R)
//{
//	if (R-L == 1)
//	{
//		Tr[idx] = 0;
//		Tcov[idx] = 0;
//		mark[idx] = 0;
//		return;
//	}
//	int mid = (L+R)/2, left = idx*2, right = idx*2+1;
//	Init(left, L, mid);
//	Init(right, mid, R);
//	Tr[idx] = 0;
//	Tcov[idx] = 0;
//	mark[idx] = 0;
//}
void PushDown(int idx, int L, int R)
{
	int mid = (L+R)/2, left = idx*2, right = idx*2+1;
	Tcov[left] += mark[idx];
	Tr[left] = Tcov[left] > 2 ? toy[mid]-toy[L] : 0;
	mark[left] += mark[idx];
	Tcov[right] += mark[idx];
	Tr[right] = Tcov[right] > 2 ? toy[R]-toy[mid] : 0;
	mark[right] += mark[idx];
	mark[idx] = 0;
}
void Update(int idx, int L, int R, int l, int r, int c)
{
	if (l <= L && R <= r)
	{
		Tcov[idx] += c;
		if (Tcov[idx] > 2 || R-L == 1)
		{
			mark[idx] += c;
			Tr[idx] = Tcov[idx] > 2 ? toy[R]-toy[L] : 0;
			return;
		}
	}
	if (mark[idx])
		PushDown(idx, L, R);
	int mid = (L+R)/2, left = idx*2, right = idx*2+1;
	if (l < mid)
		Update(left, L, mid, l, r, c);
	if (mid < r)
		Update(right, mid, R, l, r, c);
	Tr[idx] = Tr[left]+Tr[right];
}
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		memset(match, 0, sizeof(match));
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < 2; j++)
			{
				int k = 2*i+j;
				scanf("%d%d%d", &X[k], &Y[k], &Z[k]);
				Y[k] += 1000000;
				rx[k] = ry[k] = rz[k] = k;
			}
		sort(rx, rx+2*N, cmpx);
		sort(ry, ry+2*N, cmpy);
		sort(rz, rz+2*N, cmpz);
		int cnt = 0;
		for (int i = 0; i < 2*N; i++)
			if (!match[Y[ry[i]]])
			{
				match[Y[ry[i]]] = ++cnt;
				toy[cnt] = Y[ry[i]];
			}
		long long ans = 0;
		for (int i = 0; i < 2*N; )
		{
			long long area = 0;
			for (int j = 0; j < 2*N; )
			{
				int curX = X[rx[j]];
				for (; curX == X[rx[j]] && j < 2*N; j++)
				{
					int k = rx[j]/2;
					if (Z[2*k] <= Z[rz[i]] && Z[rz[i]] < Z[2*k+1])
						Update(1, 1, cnt, match[Y[2*k]], match[Y[2*k+1]], (rx[j]&1 ? -1 : 1));
				}
				if (j < 2*N)
					area += (long long)(X[rx[j]]-X[rx[j-1]])*Tr[1];
			}
			int curZ = Z[rz[i]];
			for (; curZ == Z[rz[i]] && i < 2*N; i++);
			if (i < 2*N)
				ans += (Z[rz[i]]-Z[rz[i-1]])*area;
		}
		printf("Case %d: %I64d\n", cas, ans);
	}
	return 0;
}
