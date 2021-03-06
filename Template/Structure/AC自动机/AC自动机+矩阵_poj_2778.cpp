/*
问你长度为N的串中不包含模式串的串有几个
n属于1 ~ 2000000000看到这个数据范围我们就应该敏感的想到这是矩阵~
最多100个结点，先建好所有结点(不包括模式串结尾的和fail指向结尾的结点,所以其实最多只有90个有效结点)之间的转化关系，然后二分矩阵乘法，复杂度O(100^3*log(2000000000))
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXM = 10+5;
const int MAX_NODE = 100+5, MAX_CHD = 4;
const long long MOD = 100000;
typedef long long MAT[MAX_NODE][MAX_NODE];
MAT g, G;
int M, N;
int chd[MAX_NODE][MAX_CHD], fail[MAX_NODE], ID[1<<8], nv;
bool out[MAX_NODE];
char DNA[MAXM];
queue<int> Q;
namespace AC_Automaton
{
	void Initialize()
	{
		fail[0] = 0;
		ID['A'] = 0; ID['C'] = 1; ID['T'] = 2; ID['G'] = 3;
	}
	void Reset()
	{
		memset(chd[0], 0, sizeof(chd[0]));
		nv = 1;
	}
	void Insert(char *pat)
	{
		int u = 0;
		for (int i = 0; pat[i]; i++)
		{
			int c = ID[pat[i]];
			if (!chd[u][c])
			{
				memset(chd[nv], 0, sizeof(chd[nv]));
				out[nv] = 0;
				chd[u][c] = nv++;
			}
			u = chd[u][c];
		}
		out[u] = 1;
	}
	void Construct()
	{
		for (int i = 0; i < MAX_CHD; i++)
			if (chd[0][i])
			{
				fail[chd[0][i]] = 0;
				Q.push(chd[0][i]);
			}
		while (!Q.empty())
		{
			int u = Q.front(); Q.pop();
			for (int i = 0; i < MAX_CHD; i++)
			{
				int &v = chd[u][i];
				if (v)
				{
					Q.push(v);
					fail[v] = chd[fail[u]][i];
					out[v] |= out[fail[v]];
				}
				else
					v = chd[fail[u]][i];
			}
		}
	}
}
namespace Matrix
{
	void Copy(int size, MAT x, MAT y)
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				y[i][j] = x[i][j];
	}
	void Mutiply(int size, MAT x, MAT y, MAT z)
	{
		MAT tx, ty;
		Copy(size, x, tx);
		Copy(size, y, ty);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				z[i][j] = 0;
				for (int k = 0; k < size; ++k)
					z[i][j] = (z[i][j]+tx[i][k]*ty[k][j])%MOD;
			}
	}
	void Power(int size, MAT x, int n, MAT y)
	{
		MAT tx, r;
		Copy(size, x, tx);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				r[i][j] = (i == j ? 1 : 0);
		while (n)
		{
			if (n&1)
				Mutiply(size, r, tx, r);
			n >>= 1;
			if (!n)
				break;
			Mutiply(size, tx, tx, tx);
		}
		Copy(size, r, y);
	}
}
int main()
{
	AC_Automaton::Initialize();
	memset(g, 0, sizeof(g));
	AC_Automaton::Reset();
	scanf("%d%d", &M, &N);
	for (int i = 0; i < M; i++)
	{
		scanf("%s", DNA);
		AC_Automaton::Insert(DNA);
	}
	AC_Automaton::Construct();
	for (int u = 0; u < nv; u++) if (!out[u])
		for (int k = 0; k < MAX_CHD; k++) if (!out[chd[u][k]])
			g[u][chd[u][k]]++;
	Matrix::Power(nv, g, N, G);
	long long ans = 0;
	for (int i = 0; i < nv; i++)
		ans = (ans+G[0][i])%MOD;
	printf("%lld\n", ans);
	return 0;
}
