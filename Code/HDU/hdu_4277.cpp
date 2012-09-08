//2012-09-08 18:34:41	Accepted	4277	1078MS	4724K	799 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN = 15+5;
int T, N, l[MAXN], L[3];
set<pair<int, int> > ans;
void dfs(int x)
{
    if (x == N)
    {
        if (L[0] <= L[1] && L[1] <= L[2] && L[0]+L[1] > L[2])
        {
            ans.insert(make_pair(L[0], L[1]));
//            printf("%d %d %d\n", L[0], L[1], L[2]);
        }
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        L[i] += l[x];
        dfs(x+1);
        L[i] -= l[x];
    }
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        ans.clear();
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%d", &l[i]);
        dfs(0);
        printf("%d\n", ans.size());
    }
    return 0;
}
