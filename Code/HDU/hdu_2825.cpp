//2012-09-05 18:30:30	Accepted	2825	609MS	1092K	2989 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 25+5;
const int MOD = 20090717;
const int MAX_NODE = 100+5, MAX_CHD = 26;
int N, M, K, d[2][MAX_NODE][1<<10];
int chd[MAX_NODE][MAX_CHD], val[MAX_NODE], fail[MAX_NODE];
int ID[1<<8], nv;
queue<int> Q;
struct AC_Automaton
{
    void Initialize()
    {
        fail[0] = 0;
        for (int i = 0; i < MAX_CHD; i++)
            ID[i+'a'] = i;
    }
    void Reset()
    {
        memset(chd[0], 0, sizeof(chd[0]));
        nv = 1;
    }
    void Insert(char *pat, int key)
    {
        int u = 0;
        for (int i = 0; pat[i]; i++)
        {
            int c = ID[pat[i]];
            if (!chd[u][c])
            {
                memset(chd[nv], 0, sizeof(chd[nv]));
                val[nv] = 0;
                chd[u][c] = nv++;
            }
            u = chd[u][c];
        }
        val[u] = key;
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
                    val[v] |= val[fail[v]];
                }
                else
                    v = chd[fail[u]][i];
            }
        }
    }
} ac;
int main()
{
    ac.Initialize();
    while (scanf("%d%d%d", &N, &M, &K) != EOF)
    {
        if (!N && !M && !K)
            break;
        ac.Reset();
        for (int i = 0; i < M; i++)
        {
            char temp[11];
            scanf("%s", temp);
            ac.Insert(temp, 1<<i);
        }
        ac.Construct();
        int corpora = (1<<M)-1, ans = 0, s = 0;
        memset(d[s], 0, sizeof(d[s]));
        d[0][0][0] = 1;
        for (int i = 0; i < N; i++)
        {
            int t = 1-s;
            memset(d[t], 0, sizeof(d[t]));
            for (int u = 0; u < nv; u++)
                for (int a = 0; a <= corpora; a++) if (d[s][u][a])
                    for (int k = 0; k < MAX_CHD; k++)
                    {
                        int v = chd[u][k], b = (a|val[v]);
                        d[t][v][b] = (d[t][v][b]+d[s][u][a])%MOD;
                    }
            s = t;
        }
        for (int a = 0; a <= corpora; a++)
        {
            int cnt = 0;
            for (int i = 0; i < M; i++)
                if (a&(1<<i))
                    cnt++;
            if (cnt >= K)
            {
                for (int u = 0; u < nv; u++)
                    ans = (ans+d[s][u][a])%MOD;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
