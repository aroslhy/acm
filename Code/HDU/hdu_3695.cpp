//2012-09-06 18:31:56	Accepted	3695	781MS	31584K	3447 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 5100000+5, MAXM = 1000+5, MAXP = 250+5;
const int MAX_NODE = 250000+5, MAX_CHD = 26;
int T, N, q;
char vir[MAXM], cpd[MAXN], dcpd[MAXN];
struct AC_Automaton
{
    int chd[MAX_NODE][MAX_CHD], val[MAX_NODE], fail[MAX_NODE];
    int ID[1<<8], nv;
    queue<int> Q;
    void Initialize()
    {
        fail[0] = 0;
        for (int i = 0; i < MAX_CHD; i++)
            ID[i+'A'] = i;
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
                int &v = chd[u][i];
                if (v)
                {
                    Q.push(v);
                    fail[v] = chd[fail[u]][i];
                }
                else
                    v = chd[fail[u]][i];
            }
        }
    }
    int solve(char *str)
    {
        int res = 0, u = 0;
        for (int i = 1; str[i]; i++)
        {
            int t = u = chd[u][ID[str[i]]];
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
    int solve_(char *str)
    {
        int res = 0, u = 0;
        for (int i = strlen(str+1); str[i]; i--)
        {
            int t = u = chd[u][ID[str[i]]];
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
        ac.Reset();
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
        {
            scanf("%s", vir);
            ac.Insert(vir);
        }
        ac.Construct();
        scanf("%s", cpd);
        int i = 0, j = 1;
        while (cpd[i])
        {
            if (cpd[i] == '[')
            {
                int q = 0, k = i+1;
                while (isdigit(cpd[k]))
                    q = q*10+cpd[k++]-'0';
                if (q > 1000)
                    q = 1000;
                while (q--)
                    dcpd[j++] = cpd[k];
                i = k+2;
            }
            else
                dcpd[j++] = cpd[i++];
        }
        dcpd[j] = 0;
//        printf("%s\n", dcpd+1);
        int ans = 0;
        ans += ac.solve(dcpd);
        ans += ac.solve_(dcpd);
        printf("%d\n", ans);
    }
    return 0;
}
