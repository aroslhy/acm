//2012-10-09 14:07:20	Accepted	3962	78MS	288K	2821 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXM = 5+5, MAXS = 60+5;
const int MAX_NODE = 30+5, MAX_CHD = 4;
const int MOD = 10007;
typedef int MAT[MAXS][MAXS];
MAT g, G;
int N, L;
int chd[MAX_NODE][MAX_CHD], fail[MAX_NODE], ID[1<<8], nv;
int out[MAX_NODE];
char mg[MAXM];
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
		out[u]++;
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
					out[v] += out[fail[v]];
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
	void Power(int size, MAT x, int n, MAT y, int &ans)
	{
		MAT tx, r;
		Copy(size, x, tx);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				r[i][j] = (i == j ? 1 : 0);
		int ta = 4;
		while (n)
		{
			if (n&1)
			{
				Mutiply(size, r, tx, r);
				ans = (ans*ta)%MOD;
			}
			n >>= 1;
			if (!n)
				break;
			Mutiply(size, tx, tx, tx);
			ta = (ta*ta)%MOD;
		}
		Copy(size, r, y);
	}
}
int main()
{
	AC_Automaton::Initialize();
	while (scanf("%d%d", &N, &L) != EOF)
	{
		memset(g, 0, sizeof(g));
		AC_Automaton::Reset();
		for (int i = 0; i < N; i++)
		{
			scanf("%s", mg);
			AC_Automaton::Insert(mg);
		}
		AC_Automaton::Construct();
		for (int u = 0; u < nv; u++)
			for (int k = 0; k < MAX_CHD; k++)
			{
				if (out[chd[u][k]] == 0)
				{
					g[u][chd[u][k]]++;
					g[u+nv][chd[u][k]+nv]++;
				}
				else if (out[chd[u][k]] == 1)
					g[u][chd[u][k]+nv]++;
			}
		int n = (nv<<1), ans = 1;
		Matrix::Power(n, g, L, G, ans);
		for (int i = 0; i < n; i++)
			ans = (ans-G[0][i])%MOD;
		printf("%d\n", (ans+MOD)%MOD);
	}
	return 0;
}
