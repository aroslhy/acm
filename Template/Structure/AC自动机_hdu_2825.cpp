#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

//MAX_NODE = StringNumber * StringLength
const int MAX_NODE = 100+5;
//字符集大小,一般字符形式的题26个
const int MAX_CHD = 26;

//特定题目需要
const int MAXN = 25+5;
const int MOD = 20090717;
int N, M, K, d[2][MAX_NODE][1<<10];

struct AC_Automaton
{
    //每个节点的儿子,即当前节点的状态转移
    int chd[MAX_NODE][MAX_CHD];
    //记录题目给的关键数据(点的权值)
    int val[MAX_NODE];
    //传说中的fail指针
    int fail[MAX_NODE];
    //队列,用于广度优先计算fail指针
    queue<int> Q;
    //字母对应的ID
    int ID[1<<8];
    //已使用节点个数
    int nv;
    //初始化,计算字母对应的儿子ID,如:'a'->0 ... 'z'->25
    void Initialize()
    {
        fail[0] = 0;
        for (int i = 0; i < MAX_CHD; i++)
            ID[i+'a'] = i;
    }
    //重新建树需先Reset
    void Reset()
    {
        memset(chd[0], 0, sizeof(chd[0]));
        nv = 1;
    }
    //将权值为key的字符串a插入到trie中
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
    //建立AC自动机,确定每个节点的权值以及状态转移
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
                    //以下一行代码要根据题目所给val的含义来写
                    val[v] |= val[fail[v]];
                }
                else
                    v = chd[fail[u]][i];
            }
        }
    }
    //解题
    int solve()
    {
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
        return ans;
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
        printf("%d\n", ac.solve());
    }
    return 0;
}
