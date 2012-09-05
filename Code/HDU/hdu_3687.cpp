//2012-09-05 18:33:20	Accepted	3687	46MS	252K	958 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 56+5;
const int INF = 0x3f3f3f3f;
int N, M, X, Y;
vector<int> pos[MAXN];
int main()
{
    while (scanf("%d%d", &N, &M))
    {
        if (!N && !M)
            break;
        for (int i = 1; i <= N; i++)
            pos[i].clear();
        int n = N*N;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &X, &Y);
            pos[X].push_back(Y);
        }
        for (int i = 1; i <= N; i++)
            sort(pos[i].begin(), pos[i].end());
        int ans = INF;
        for (int i = 1; i <= M-N+1; i++)
        {
            int cost = 0;
            for (int j = 1; j <= N; j++)
                for (int k = 0; k < N; k++)
                    cost += abs(pos[j][k]-(i+k));
            ans = min(ans, cost);
        }
        printf("%d\n", ans);
    }
    return 0;
}
