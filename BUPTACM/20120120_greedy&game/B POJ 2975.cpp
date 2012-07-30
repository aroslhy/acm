#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int MAXN = 1000+5;
int n, k[MAXN], K;
int main()
{

//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &n))
    {
        if (!n) break;
        K = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &k[i]);
            K = K^k[i];
        }
        int ans = 0;
        for (int i = 1; i <= n && K; i++)
            if ((k[i]^K) < k[i]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
