// 5798	Jupiter Atacks!	Accepted	C++	0.402	2013-10-21 13:56:58
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
int B, P, L, N, X, Y;
int Tr[MAXN<<2], powB[MAXN];
char ope[5];
void Build(int idx, int L, int R)
{
	Tr[idx] = 0;
	if (L == R)
		return;
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	Build(left, L, mid);
	Build(right, mid+1, R);
}
void Update(int idx, int L, int R, int x, int c)
{
	if (x <= L && R <= x)
	{
		Tr[idx] = c;
		return;
	}
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	if (x <= mid)
		Update(left, L, mid, x, c);
	else
		Update(right, mid+1, R, x, c);
	Tr[idx] = ((long long)Tr[left]*powB[R-mid]+Tr[right])%P;
}
int Query(int idx, int L, int R, int l, int r)
{
	if (l <= L && R <= r)
		return Tr[idx];
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	if (r <= mid)
		return Query(left, L, mid, l, r);
	else if (mid < l)
		return Query(right, mid+1, R, l, r);
	else
		return ((long long)Query(left, L, mid, l, mid)*powB[r-mid]+Query(right, mid+1, R, mid+1, r))%P;
}
int main()
{
	powB[0] = 1;
	while (scanf("%d%d%d%d", &B, &P, &L, &N))
	{
		if (!B && !P && !L && !N)
			break;
		for (int i = 1; i <= L; i++)
			powB[i] = ((long long)powB[i-1]*B)%P;
		Build(1, 1, L);
		for (int i = 1; i <= N; i++)
		{
			scanf("%s%d%d", ope, &X, &Y);
			if (ope[0] == 'E')
				Update(1, 1, L, X, Y);
			else
				printf("%d\n", Query(1, 1, L, X, Y));
		}
		printf("-\n");
	}
	return 0;
}
