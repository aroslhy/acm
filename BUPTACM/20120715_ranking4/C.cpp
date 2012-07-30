//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int MAXN = 1000+5, MAXM = 100+5;
//const int INF = 0x3f3f3f3f;
//int p, q, n;
//int SG(int x, int y)
//{
//    bool vis[MAXM];
//    memset(vis, 0, sizeof(vis));
//    for (int i = 1; i <= x; i++)
//        vis[SG(x-i, y)] = 1;
//    for (int i = 1; i <= y; i++)
//        vis[SG(x, y-i)] = 1;
//    for (int i = 1; i <= x && i <= y; i++)
//        vis[SG(x-i, y-i)] = 1;
//    for (int i = 0; ; i++) if (!vis[i])
//        return i;
//}
//int main()
//{
//    freopen("input.txt", "r", stdin);
////    freopen("output.txt", "w", stdout);
////    n = 10;
////    for (int i = 0; i <= n; i++)
////        for (int j = i; j <= n; j++)
////        {
////            if (SG(i, j))
////            {
//////                printf("%d,%d:%d\n", i, j, 1);
////            }
////            else
////            {
////                printf("%d,%d:%d\n", i, j, 0);
////            }
////        }
//    while (scanf("%d%d", &p, &q) != EOF)
//    {
//        if (p > q) swap(p, q);
//        int a = p/3, b = q/5;
//        int c = (p-1)/3, d = (q-2)/5;
//        if ((p == 3*a && q == 5*b) || (p == 3*c+1 && q == 5*d+2))
//            printf("0\n");
//        else
//            printf("1\n");
//    }
//    return 0;
//}
