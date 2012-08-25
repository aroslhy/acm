//2012-08-25 21:18:29	Accepted	4260	0MS	244K	990 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 63+5, MAXM = 1000000+5;
const int INF = 0x3f3f3f3f;
char s[MAXN];
vector<int> peg[3];
long long solve(int x, int b)
{
    if (!x)
        return 0;
    for (int a = 0; a < 3; a++)
        if (peg[a].size() && peg[a][peg[a].size()-1] == x)
        {
            peg[a].pop_back();
            if (a == b)
                return solve(x-1, b);
            else
                return (1LL<<(x-1))+solve(x-1, 3-a-b);
        }
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    while (scanf("%s", s))
    {
        if (s[0] == 'X')
            break;
        for (int i = 0; i < 3; i++)
            peg[i].clear();
        int n = strlen(s);
        for (int i = 1; i <= n; i++)
            peg[s[i-1]-'A'].push_back(i);
        printf("%I64d\n", solve(n, 1));
    }
    return 0;
}
