#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 10000+5, MAXM = 40000+5;
const int INF = 0x3f3f3f3f;
int T, N, a;
bool vis[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d", &N);
        bool flag = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &a);
            for (int d = 1; a-d >= 1 && a+d <= N && !flag; d++)
                if (vis[a-d]^vis[a+d])
                    flag = 1;
            vis[a] = 1;
        }
        printf("%s\n", flag ? "Y" : "N");
    }
    return 0;
}
