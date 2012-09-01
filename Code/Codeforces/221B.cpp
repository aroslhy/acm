//Sep 1, 2012 5:32:34 AM 	bigoceanlhy 	221B - Little Elephant and Numbers 	GNU C++ 	Accepted 	30 ms 	1200 KB 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 100000+5;
int X, d, ans;
int prm[MAXN];
bool vis[10];
bool is[MAXN];
vector<int> P, C;
int getprm(int n){
    int i, j, k = 0;
    int s, e = (int)(sqrt(0.0 + n) + 1);
    memset(is, 1, sizeof(is));
    prm[k++] = 2; is[0] = is[1] = 0;
    for (i = 4; i < n; i += 2) is[i] = 0;
    for (i = 3; i < e; i += 2) if (is[i]) {
        prm[k++] = i;
        for (s = i * 2, j = i * i; j < n; j += s)
            is[j] = 0;            // 因为j是奇数,所以+奇数i后是偶数,不必处理!
    }
    for ( ; i < n; i += 2) if (is[i]) prm[k++] = i;
        return k;        // 返回素数的个数
}
void dfs(int x)
{
    if (x == P.size())
    {
        int t = d;
        bool flag = 0;
        while (!flag && t)
        {
            if (vis[t%10])
                flag = 1;
            t /= 10;
        }
        if (flag)
        {
//            printf("%d ", d);
            ans++;
        }
        return;
    }
    for (int i = 0; i <= C[x]; i++)
    {
        for (int j = 1; j <= i; j++)
            d *= P[x];
        dfs(x+1);
        for (int j = 1; j <= i; j++)
            d /= P[x];
    }
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
    int c = getprm(MAXN);
    d = 1;
    while (scanf("%d", &X) != EOF)
    {
        memset(vis, 0, sizeof(vis));
        P.clear();
        C.clear();
        int t = X;
        while (t)
        {
            vis[t%10] = 1;
            t /= 10;
        }
        t = X;
        for (int i = 0; i < c; i++)
            if (!(t%prm[i]))
            {
                P.push_back(prm[i]);
                int cnt = 0;
                for (; !(t%prm[i]); cnt++)
                    t /= prm[i];
                C.push_back(cnt);
//                printf("%d %d\n", prm[i], cnt);
            }
        if (t > 1)
        {
            P.push_back(t);
            C.push_back(1);
        }
        ans = 0;
        dfs(0);
//        printf("\n");
        printf("%d\n", ans);
    }
    return 0;
}
