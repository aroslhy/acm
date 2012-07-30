#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 500000+5, MAXM = 1000000+5;
const int INF = 0x3f3f3f3f;
const int MAX = 500000;
//int n, sg[MAXN];
int n, sg[] = {0,1,1,2,0,3,1,1,0,3,3,2,2,4,0,5,2,2,3,3,0,1,1,3,0,2,1,1,0,4,5,2,7,4,0,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,2,3,3,0,1,1,3,0,2,1,1,0,4,5,3,7,4,8,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,9,3,3,0,1,1,3,0,2,1,1,0,4,5,3,7,4,8};
bool vis[MAXM];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    n = 102;
//    for (int i = 1; i <= n; i++)
//    {
//        memset(vis, 0, sizeof(vis));
//        for (int j = 1; j <= i; j++)
//        {
//            int x = 0;
//            if (j-2 > 0)
//                x ^= sg[j-2];
//            if (i-j-1 > 0)
//                x ^= sg[i-j-1];
//            vis[x] = 1;
//        }
//        for (int y = 0; ; y++) if (!vis[y])
//        {
//            sg[i] = y;
//            break;
//        }
//        printf("%d,", sg[i]);
//        if (i%34 == 0)
//            printf("\n");
//    }
    scanf("%d", &n);
    if (n <= 68)
        printf("%s\n", sg[n] ? "White" : "Black");
    else
        printf("%s\n", sg[(n-1)%34+1+68] ? "White" : "Black");
    return 0;
}
