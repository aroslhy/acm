#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 30+5, MAXM = 10000;
const int INF = 0x3f3f3f3f;
int T;
int N;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &N) != EOF)
    {

        //cout<<N<<endl;
        for (int y = 1; ; y++)
        {
            if (N*y == sqrt(N*y)*sqrt(N*y))
            {
                int x = N+2*sqrt(N*y)+y;
                printf("%d\n", x);
                break;
            }
        }
    }
    return 0;
}
