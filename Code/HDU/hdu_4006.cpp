//2012-08-15 13:48:18	Accepted	4006	62MS	312K	916 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 50000+5, MAXM = 100000+5;
int N, K, a;
char cmd[5];
priority_queue<int, vector<int>, greater<int> > pq;
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    while (scanf("%d%d", &N, &K) != EOF)
    {
        while (!pq.empty())
            pq.pop();
        for (int i = 1; i <= N; i++)
        {
            scanf("%s", cmd);
            if (cmd[0] == 'I')
            {
                scanf("%d", &a);
                if (pq.size() < K)
                    pq.push(a);
                else if (a > pq.top())
                {
                    pq.pop();
                    pq.push(a);
                }
            }
            else
                printf("%d\n", pq.top());
        }
    }
    return 0;
}
