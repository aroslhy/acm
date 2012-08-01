#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5, MAXM = 155000*2+5;
const int INF = 0x3f3f3f3f;
struct Node
{
    long long x, p;
} r[MAXN];
bool operator < (const Node a, const Node b)
{
    return a.x < b.x;
}
int N;
long long K;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%I64d", &N, &K) != EOF)
    {
        for (int i = 1; i <= N; i++)
            scanf("%I64d%I64d", &r[i].x, &r[i].p);
        sort(r+1, r+1+N);
        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            int cnt = r[i].p, j = i-1, k = i+1;
            long long l = K;
            while (l && (1 <= j || k <= N))
            {
                long long ll = r[i].x-r[j].x, lr = r[k].x-r[i].x;
                if (1 <= j && k <= N)
                {
                    if (ll < lr)
                    {
                        if (l/ll >= r[j].p)
                        {
                            cnt += r[j].p;
                            l -= ll*r[j].p;
                        }
                        else
                        {
                            cnt += l/ll;
                            l = 0;
                        }
                        j--;
                    }
                    else
                    {
                        if (l/lr >= r[k].p)
                        {
                            cnt += r[k].p;
                            l -= lr*r[k].p;
                        }
                        else
                        {
                            cnt += l/lr;
                            l = 0;
                        }
                        k++;
                    }
                }
                else if (1 <= j)
                {
                    if (l/ll >= r[j].p)
                    {
                        cnt += r[j].p;
                        l -= ll*r[j].p;
                    }
                    else
                    {
                        cnt += l/ll;
                        l = 0;
                    }
                    j--;
                }
                else if (k <= N)
                {
                    if (l/lr >= r[k].p)
                    {
                        cnt += r[k].p;
                        l -= lr*r[k].p;
                    }
                    else
                    {
                        cnt += l/lr;
                        l = 0;
                    }
                    k++;
                }
            }
            ans = max(ans, cnt);
        }
        printf("%d\n", ans);
    }
    return 0;
}
