#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 20+5;
const int INF = 0x3f3f3f3f;
int N;
struct Node
{
    long long S, T;
} wed[MAXN];
bool cmp(const Node a, const Node b)
{
    return a.S+a.T < b.S+b.T;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &N) && N)
    {
        for (int i = 0; i < N; i++)
            scanf("%lld%lld", &wed[i].S, &wed[i].T);
        sort(wed, wed+N, cmp);
        long long cur = wed[0].S;
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            cur = max(cur, wed[i].S);
            cur += (wed[i].T-wed[i].S)/2+1;
            if (cur > wed[i].T)
                break;
            cnt++;
        }
        printf("%s\n", (cnt == N) ? "YES" : "NO");
    }
    return 0;
}
