#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 120*2+5, MAXM = 120*2*2*120+5;
int T, n, m;
int e, head[MAXN], next[MAXM], v[MAXM];
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e++;
}
int xM[MAXN], yM[MAXN];
bool chk[MAXN];
bool SearchPath(int u)
{
    for(int i = head[u]; i != -1; i = next[i])
        if(!chk[v[i]])
        {
            chk[v[i]] = true;
            if(yM[v[i]] == -1 || SearchPath(yM[v[i]]))
            {
                yM[v[i]] = u; xM[u] = v[i];
                return true ;
            }
        }
    return false ;
}
int MaxMatch()
{
    int u, ret = 0 ;
    memset(xM, -1, sizeof (xM));
    memset(yM, -1, sizeof (yM));
    for(u = 1; u <= n; u++)
    if(xM[u] == -1)
    {
        memset(chk, false, sizeof (chk));
        if(SearchPath(u)) ret++;
    }
    return ret;
}
int main()
{
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    scanf("%d", &T);
    while (T--)
    {
        e = 0;
        memset(head, -1, sizeof(head));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int S, E;
            scanf("%d%d", &S, &E);
            addedge(S, E+n);
        }
        printf("%d\n", n-MaxMatch());
    }
    return 0;
}

