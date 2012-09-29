#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1000000+5, MAXM = 50+5;
const int MAX_NODE = 500000+5, MAX_CHD = 26;
int T, N;
char key[MAXM], des[MAXN];
struct AC_Automaton
{
    int chd[MAX_NODE][MAX_CHD], fail[MAX_NODE], val[MAX_NODE];
    int ID[1<<8], nv;
    queue<int> Q;
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
    void Insert(char *pat)
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
        val[u]++;
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
                int v = chd[u][i];
                if (v)
                {
                    Q.push(v);
                    fail[v] = chd[fail[u]][i];
                }
                else
                    chd[u][i] = chd[fail[u]][i];
            }
        }
    }
    int solve(char *str)
    {
        int res = 0, u = 0;
        for (int i = 0; str[i]; i++)
        {
            int c = ID[str[i]];
            u = chd[u][c];
            int t = u;
            while (t)
            {
                if (val[t])
                {
                    res += val[t];
                    val[t] = 0;
                }
                t = fail[t];
            }
        }
        return res;
    }
} ac;
int main()
{
    ac.Initialize();
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        ac.Reset();
        for (int i = 0; i < N; i++)
        {
            scanf("%s", key);
            ac.Insert(key);
        }
        ac.Construct();
        scanf("%s", des);
        printf("%d\n", ac.solve(des));
    }
    return 0;
}
