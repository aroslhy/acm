#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
const int MAXN = 1000+5, MAXM = 26+5;
const int INF = 0x3f3f3f3f;
int m, n;
long long d[MAXN][MAXN];
vector<int> V;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &m) && m)
    {
        V.push_back(m);
        n = max(n, m);
    }
    for (int i = 1; i <= n; i++)
        for (int j = i; j > 0; j--)
        {
            d[i][j] = d[i][j+1];
            if (3*j <= i)
                d[i][j] += d[i-2*j][j];
            else if (j == i || 2*j == i)
                d[i][j] += 1;
//            printf("%d,%d:%d\n", i, j, d[i][j]);
        }
    for (int i = 0; i < (int)V.size(); i++)
        printf("%d %lld\n", V[i], d[V[i]][1]);
    return 0;
}
