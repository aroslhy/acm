//bigoceanlhy	3691	Accepted	4548K	110MS	G++	2374B	2012-09-28 21:00:02
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1000+5;
const int INF = 0x3f3f3f3f;
const int MAX_NODE = 1000+5, MAX_CHD = 4;
int N, d[MAXN][MAX_NODE], cas = 0;
int chd[MAX_NODE][MAX_CHD], fail[MAX_NODE], ID[1<<8], nv;
bool out[MAX_NODE];
char DNA[MAXN];
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
int main()
{
	AC_Automaton::Initialize();
	while (scanf("%d", &N) && N)
	{
		AC_Automaton::Reset();
		for (int i = 0; i < N; i++)
		{
			scanf("%s", DNA);
			AC_Automaton::Insert(DNA);
		}
		AC_Automaton::Construct();
		scanf("%s", DNA);
		int len = strlen(DNA);
		for (int i = 0; i < len; i++)
		{
			fill(d[i+1], d[i+1]+nv, INF);
			for (int u = 0; u < nv; u++) if (!out[u])
				for (int k = 0; k < MAX_CHD; k++)
				{
					int v = chd[u][k];
					if (!out[v])
						d[i+1][v] = min(d[i+1][v], d[i][u]+(ID[DNA[i]] == k ? 0 : 1));
				}
		}
		int ans = INF;
		for (int u = 0; u < nv; u++) if (!out[u])
			ans = min(ans, d[len][u]);
		printf("Case %d: %d\n", ++cas, (ans < INF ? ans : -1));
	}
	return 0;
}
