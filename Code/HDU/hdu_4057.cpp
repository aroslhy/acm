//2012-09-24 20:09:38	Accepted	4057	562MS	2268K	3036 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX_NODE = 1000+5, MAX_CHD = 4;
const int MAX = 10, MAXN = 100+5;
const int INF = 0x3f3f3f3f;
int N, M, w[MAX];
bool d[2][MAX_NODE][1<<MAX];
char DNA[MAXN];
struct AC_Automaton
{
    int chd[MAX_NODE][MAX_CHD], out[MAX_NODE], fail[MAX_NODE];
    int ID[1<<8], nv;
    queue<int> Q;
    void Initialize()
    {
        fail[0] = 0;
        ID['A'] = 0; ID['G'] = 1; ID['T'] = 2; ID['C'] = 3;
    }
    void Reset()
    {
        memset(chd[0], 0, sizeof(chd[0]));
        nv = 1;
    }
    void Insert(char *pat, int val)
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
        out[u] |= val;
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
    int solve()
    {
        int tot = (1<<N)-1, res = -INF, s = 0, t = 1;
        memset(d[t], 0, sizeof(d[t]));
        d[t][0][0] = 1;
        for (int i = 0; i < M; i++)
        {
            swap(s, t);
            memset(d[t], 0, sizeof(d[t]));
            for (int u = 0; u < nv; u++)
                for (int a = 0; a < tot; a++) if (d[s][u][a])
                    for (int k = 0; k < MAX_CHD; k++)
                    {
                        int v = chd[u][k], b = a|out[v];
                        d[t][v][b] = 1;
                    }
        }
        for (int u = 0; u < nv; u++)
            for (int a = 0; a <= tot; a++) if (d[t][u][a])
            {
                int W = 0;
                for (int i = 0; i < N; i++)
                    if (a&(1<<i))
                        W += w[i];
                res = max(res, W);
            }
        return res;
    }
} ac;
int main()
{
    ac.Initialize();
    while (scanf("%d%d", &N, &M) != EOF)
    {
        ac.Reset();
        for (int i = 0; i < N; i++)
        {
            scanf("%s%d", DNA, &w[i]);
            ac.Insert(DNA, 1<<i);
        }
        ac.Construct();
        int ans = ac.solve();
        if (ans < 0)
            printf("No Rabbit after 2012!\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
