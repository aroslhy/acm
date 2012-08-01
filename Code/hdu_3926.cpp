//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int MAXN = 10000+5, MAXM = 10000+5, MAXP = 1000000+5;
//int T, N[2], M[2], cnt[MAXN], p[MAXN];
//bool iscir[MAXN];
//struct Edge
//{
//    int u, v;
//} e[MAXM];
//bool operator < (const Edge x, const Edge y)
//{
//    if (x.u != y.u)
//        return x.u < y.u;
//    else
//        return x.v < y.v;
//}
//int find(int x)
//{
//    return p[x] == x ? x : p[x] = find(p[x]);
//}
//int main()
//{
//    freopen("input.txt", "r", stdin);
////    freopen("output.txt", "w", stdout);
//    scanf("%d", &T);
//    for (int cas = 1; cas <= T; cas++)
//    {
//        for (int k = 0; k < 2; k++)
//        {
//            memset(iscir, 0, sizeof(iscir));
//            memset(cnt, 0, sizeof(cnt));
//            scanf("%d%d", &N[k], &M[k]);
//            for (int i = 1; i <= N[k]; i++)
//                p[i] = i;
//            for (int i = 1; i <= M[k]; i++)
//            {
//                int x, y;
//                scanf("%d%d", &x, &y);
//                int u = find(x), v = find(y);
//                if (u == v)
//                    iscir[u] = 1;
//                else
//                {
//                    p[u] = v;
//                    cnt[v] += cnt[u];
//                }
//            }
//            for (int i = 1; i <= N; i++) if (i == p[i])
//            {
//
//            }
//
//        }
//        printf("Case #%d: %s\n", cas, flag ? "YES" : "NO");
//    }
//    return 0;
//}
