//2012-09-06 21:39:35	Accepted	3689	31MS	8180K	2741 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1000+5, MAXM = 10+5;
const int INF = 0x3f3f3f3f;
const int MAX_NODE = MAXN, MAX_CHD = 26;
int N, M;
char ch[5], word[MAXM];
double P[MAX_CHD], d[MAXN][MAX_NODE];
struct AC_Automaton
{
    int chd[MAX_NODE][MAX_CHD], val[MAX_NODE], fail[MAX_NODE];
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
    double solve()
    {
        double ans = 0;
        d[0][0] = 1;
        for (int i = 0; i < M; i++)
            for (int u = 0; u < nv; u++) if (d[i][u])
            {
//                printf("%d,%d:%lf\n", i, u, d[i][u]);
                for (int j = 0; j < MAX_CHD; j++) if (!val[u])
                    d[i+1][chd[u][j]] += d[i][u]*P[j];
            }
        int len = strlen(word);
        for (int i = len; i <= M; i++)
            ans += d[i][len];
        return ans*100;
    }
} ac;
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    ac.Initialize();
    while (scanf("%d%d", &N, &M))
    {
        if (!N && !M)
            break;
        memset(P, 0, sizeof(P));
        memset(d, 0, sizeof(d));
        ac.Reset();
        for (int i = 0; i < N; i++)
        {
            scanf("%s", ch);
            scanf("%lf", &P[ch[0]-'a']);
        }
        scanf("%s", word);
        ac.Insert(word);
        ac.Construct();
        printf("%.2lf%s\n", ac.solve(), "\%");
    }
    return 0;
}
