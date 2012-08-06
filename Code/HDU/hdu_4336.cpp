//2012-08-06 09:29:05	Accepted	4336	46MS	236K	742 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 20+5, MAXM = 100000+5;
int N, cnt;
double p[MAXN], sum, ans;
void dfs(int x)
{
    if (x == N)
    {
        if (cnt)
        {
            if (cnt%2)
                ans += 1/sum;
            else
                ans -= 1/sum;
        }
        return;
    }
    dfs(x+1);
    sum += p[x];
    cnt++;
    dfs(x+1);
    sum -= p[x];
    cnt--;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < N; i++)
            scanf("%lf", &p[i]);
        sum = 0; ans = 0;
        dfs(0);
        printf("%.4lf\n", ans);
    }
    return 0;
}
