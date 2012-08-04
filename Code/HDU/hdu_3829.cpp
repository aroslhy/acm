#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 500*2+5, MAXM = 500*500+5;
const int INF = 0x3f3f3f3f;
int N, M, P, lik[MAXN], dsl[MAXN];
int e, head[MAXN], next[MAXM], v[MAXM];
int xM[MAXN], yM[MAXN];
bool chk[MAXN];
bool SearchPath(int u)
{
    for(int i = head[u]; i != -1; i = next[i])
        if(!chk[v[i]])
        {
            chk[v[i]] = 1;
            if(yM[v[i]] == -1 || SearchPath(yM[v[i]]))
            {
                yM[v[i]] = u; xM[u] = v[i];
                return 1;
            }
        }
    return 0;
}
int MaxMatch()
{
    int ret = 0 ;
    memset(xM, -1, sizeof (xM));
    memset(yM, -1, sizeof (yM));
    for(int u = 1; u <= P; u++)
        if(xM[u] == -1)
        {
            memset(chk, 0, sizeof (chk));
            if(SearchPath(u)) ret++;
        }
    return ret;
}
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e++;
}
int main()
{
    freopen("input.txt", "r", stdin);
    while (scanf("%d%d%d", &N, &M, &P) != EOF)
    {
        e = 0;
        memset(head, -1, sizeof(head));
        for (int i = 1; i <= P; i++)
        {
            char x[10], y[10];
            scanf("%s%s", x, y);
            int X, Y;
            sscanf(x+1, "%d", &X);
            if (x[0] == 'D') X += N;
            sscanf(y+1, "%d", &Y);
            if (y[0] == 'D') Y += N;
            lik[i] = X;
            dsl[i] = Y;
            for (int j = 1; j < i; j++)
                if (lik[j] == dsl[i] || dsl[j] == lik[i])
                {
                    addedge(i, j+P);
                    addedge(j, i+P);
                }
        }
        printf("%d\n", P-MaxMatch()/2);
    }
    return 0;
}
