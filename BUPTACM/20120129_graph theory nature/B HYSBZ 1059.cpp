#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 200+5;
int T, N, m[MAXN][MAXN];
int xM[MAXN], yM[MAXN]; // 输出量
bool chk[MAXN]; // 辅助量检查某轮y[v]是否被check
bool SearchPath(int u){
    int v;
    for(v = 1; v <= N; v++)
        if(m[u][v] && !chk[v])
        {
            chk[v] = true;
            if(yM[v] == -1 || SearchPath(yM[v]))
            {
                yM[v] = u; xM[u] = v;
                return true ;
            }
        }
    return false ;
}
int MaxMatch(){
    int u, ret = 0 ;
    memset(xM, -1, sizeof (xM));
    memset(yM, -1, sizeof (yM));
    for(u = 1; u <= N; u++)
        if(xM[u] == -1){
            memset(chk, false, sizeof (chk));
            if(SearchPath(u)) ret++;
        }
    return ret;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                scanf("%d", &m[i][j]);
        printf("%s\n", MaxMatch() == N ? "Yes" : "No");
    }
    return 0;
}
