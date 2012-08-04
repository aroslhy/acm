#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 16, MAXM = 100+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000009;
int n, d[1<<MAXN][MAXN], w[MAXN][MAXN], p[1<<MAXN][MAXN], ans;
unsigned long long a;
char A[MAXN][MAXM], *pat, *str;
int fail[MAXM];
bool mark[MAXN];
void kmp(int x)
{
    pat = A[x];
    int len2 = strlen(pat);
    fail[0] = -1;
    for (int i = 1, j = -1; i < len2; i++)
    {
        while (j != -1 && pat[j+1] != pat[i])
            j = fail[j];
        if (pat[j+1] == pat[i])
            j++;
        fail[i] = j;
    }
    for (int i = 0; i < n; i++)
        if (i != x && !mark[i])
        {
            str = A[i];
            int len1 = strlen(str);
            int p = 0, q = 0;
            while (p < len1 && q < len2)
            {
                if (pat[q] == str[p])
                    ++p, ++q;
                else if (q == 0)
                    ++p;
                else
                    q = fail[q-1]+1;
            }
            w[i][x] = q;
            if (w[i][x] == len2) mark[x] = 1;
        }
}
void hamiltonian_path(int S)
{
    for (int u = 1; u <= S; u++)
        for(int i = 0; i < n; i++)
            d[u][i] = INF;
    for (int i = 0; i < n; i++) if ((1<<i)&S)
        d[(1<<i)][i] = strlen(A[i]);
    for (int u = 1; u <= S; u++) if (u == (u&S))
        for (int i = 0; i < n; i++) if ((1<<i)&u)
            for (int j = 0; j < n; j++) if ((1<<j)&u) if (i != j)
            {
                int v = u^(1<<j), len = strlen(A[j]);
                if (len-w[j][i]+d[v][i] < d[u][j] || (len-w[j][i]+d[v][i] == d[u][j] && strcmp(A[i]+w[j][i], A[p[u][j]]+w[j][p[u][j]]) < 0))
                {
                    d[u][j] = len-w[j][i]+d[v][i];
                    p[u][j] = i;
                }
            }
}
void make_ans(int u, int x)
{
    int len = strlen(A[x]);
    if (p[u][x] == -1)
    {
        for (int i = 0; i < len; i++)
            ans = (ans*2+A[x][i]-'0')%MOD;
        return;
    }
    for (int i = 0; i < len-w[x][p[u][x]]; i++)
        ans = (ans*2+A[x][i]-'0')%MOD;
    int v = u^(1<<x);
    make_ans(v, p[u][x]);
}
int main()
{
    freopen("input.txt", "r", stdin);
    while (scanf("%d", &n) != EOF)
    {
        memset(A, 0, sizeof(A));
        memset(w, 0, sizeof(w));
        memset(mark, 0, sizeof(mark));
        memset(p, -1, sizeof(p));
        for (int i = 0; i < n; i++)
        {
            scanf("%I64u", &a);
            for (int j = 0; a; j++)
            {
                A[i][j] = a%2 ? '1' : '0';
                a /= 2;
            }
            int len = strlen(A[i]);
            for (int j = 0; j < len/2; j++)
                swap(A[i][j], A[i][len-j-1]);
//            printf("%s\n", A[i]);
        }
        for (int i = 0; i < n; i++)
            kmp(i);
        int S = (1<<n)-1;
        for (int i = 0; i < n; i++)
            if (mark[i])
                S ^= (1<<i);
        hamiltonian_path(S);
        int minlen = INF, q;
        for (int i = 0; i < n; i++)
            if ((minlen > d[S][i]) || (minlen == d[S][i] && strcmp(A[i], A[q]) < 0))
            {
                minlen = d[S][i];
                q = i;
            }
        ans = 0;
        make_ans(S, q);
        printf("%d\n", ans);
    }
    return 0;
}
