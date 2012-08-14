//2012-08-14 19:14:25	Accepted	4004	296MS	384K	1061 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 500000+5;
const int MAX = 1000000000;
int L, N, M, stn[MAXN], r[MAXN], ans;
void find(int x, int y)
{
    int mid = (x+y)/2, cur = 0, cnt = 0;
    bool flag = 1;
    for (int i = 1; i <= N+1 && flag; i++)
    {
        if (stn[i-1]-stn[cur] <= mid && mid < stn[i]-stn[cur])
            cnt++, cur = i-1;
        if (stn[i]-stn[cur] > mid || cnt+1 > M)
            flag = 0;
    }
    if (flag)
        ans = min(ans, mid);
    if (x == y)
        return;
    else if (flag)
        find(x, mid);
    else
        find(mid+1, y);
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    while (scanf("%d%d%d", &L, &N, &M) != EOF)
    {
        stn[0] = 0;
        for (int i = 1; i <= N; i++)
            scanf("%d", &stn[i]);
        stn[N+1] = L;
        sort(stn+1, stn+1+N);
        ans = MAX;
        find(1, MAX);
        printf("%d\n", ans);
    }
    return 0;
}
