//bigoceanlhy	2778	Accepted	1032K	547MS	G++	2902B	2012-09-28 13:09:00
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXM = 10+5;
const int MAX_NODE = 100+5, MAX_CHD = 4;
const long long MOD = 100000;
typedef long long Matrix[MAX_NODE][MAX_NODE];
Matrix g, G;
int M, N;
char DNA[MAXM];
int chd[MAX_NODE][MAX_CHD], out[MAX_NODE], fail[MAX_NODE];
int ID[1<<8], nv;
queue<int> Q;
struct AC_Automaton
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
} ac;
void Copy(int size, Matrix x, Matrix y)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			y[i][j] = x[i][j];
}
void Mutiply(int size, Matrix x, Matrix y, Matrix z)
{
	Matrix tx, ty;
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
void Power(int size, Matrix x, int n, Matrix y)
{
	Matrix tx, r;
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
int main()
{
	ac.Initialize();
	memset(g, 0, sizeof(g));
	ac.Reset();
	scanf("%d%d", &M, &N);
	for (int i = 0; i < M; i++)
	{
		scanf("%s", DNA);
		ac.Insert(DNA);
	}
	ac.Construct();
	for (int u = 0; u < nv; u++) if (!out[u])
		for (int k = 0; k < MAX_CHD; k++) if (!out[chd[u][k]])
			g[u][chd[u][k]]++;
	Power(nv, g, N, G);
	long long ans = 0;
	for (int i = 0; i < nv; i++)
		ans = (ans+G[0][i])%MOD;
	printf("%lld\n", ans);
	return 0;
}
