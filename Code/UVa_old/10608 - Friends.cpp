#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXM = 500000+5;
int T, N, M, ans, cnt, V1[MAXM], V2[MAXM];
bool vis[MAXM];
void Search(int x)
{
    if (vis[x]) return;
    vis[x] = 1;
    cnt++;
    for (int i = 1; i <= M; i++)
    {
        if (x == V1[i])
            Search(V2[i]);
        if (x == V2[i])
            Search(V1[i]);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
	    memset(vis, 0, sizeof(vis));
	    scanf("%d%d", &N, &M);
	    for (int i = 1; i <= M; i++)
	        scanf("%d%d", &V1[i], &V2[i]);
	    ans = 0;
	    for (int i = 1; i <= N; i++)
	    {
            cnt = 0;
            Search(i);
            ans = max(ans, cnt);
	    }
	    printf("%d\n", ans);
	}
	return 0;
}
