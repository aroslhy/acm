//Sep 1, 2012 5:37:42 AM 	bigoceanlhy 	220A - Little Elephant and Problem 	GNU C++ 	Accepted 	60 ms 	1500 KB 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
int N, a[MAXN], b[MAXN];
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b, b+N);
        int cnt = 0;
        for (int i = 0; i < N; i++)
            if (a[i] == b[i])
                cnt++;
        if (cnt >= N-2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
