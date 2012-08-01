#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1000+5, MAXM = 640000+5, MAXP = 400+5;
const int INF = 0x3f3f3f3f;
int l1, l2, d[MAXN][MAXN];
char s1[MAXN], s2[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%s%d%s", &l1, s1+1, &l2, s2+1) != EOF)
    {
        for (int i = 0; i <= l1; i++)
            for (int j = 0; j <= l2; j++)
            {
                if (!(i*j))
                    d[i][j] = i+j;
                else
                {
                    d[i][j] = min(d[i-1][j]+1, d[i][j-1]+1);
                    if (s1[i] == s2[j])
                        d[i][j] = min(d[i][j], d[i-1][j-1]);
                    else
                        d[i][j] = min(d[i][j], d[i-1][j-1]+1);
                }
//                printf("%d,%d:%d\n", i, j, d[i][j]);
            }
        printf("%d\n", d[l1][l2]);
    }
    return 0;
}
