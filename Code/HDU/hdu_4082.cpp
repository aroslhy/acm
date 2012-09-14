//2012-09-14 18:51:01	Accepted	4082	0MS	312K	1824 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 18+5, MAXM = 200+5;
const int INF = 0x3f3f3f3f;
int N, X[MAXN], Y[MAXN], L[3];
bool vis[MAXM][MAXM];
map<pair<pair<int, int>, int>, int> cnt;
int gcd(int x, int y)
{
    return y ? gcd(y, x%y) : x;
}
int main()
{
    while (scanf("%d", &N) && N)
    {
        memset(vis, 0, sizeof(vis));
        cnt.clear();
        int n = 0, ans = 0;
        for (int i = 0; i < N; i++, n++)
        {
            scanf("%d%d", &X[n], &Y[n]);
            if (!vis[X[n]+100][Y[n]+100])
                vis[X[n]+100][Y[n]+100] = 1;
            else
                n--;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                for (int k = 0; k < j; k++)
                {
                    if ((X[i]-X[k])*(Y[j]-Y[k]) == (X[j]-X[k])*(Y[i]-Y[k]))
                        continue;
                    L[0] = (X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]);
                    L[1] = (X[j]-X[k])*(X[j]-X[k])+(Y[j]-Y[k])*(Y[j]-Y[k]);
                    L[2] = (X[k]-X[i])*(X[k]-X[i])+(Y[k]-Y[i])*(Y[k]-Y[i]);
                    int g = gcd(gcd(L[0], L[1]), L[2]);
                    for (int p = 0; p < 3; p++)
                        L[p] /= g;
                    sort(L, L+3);
//                    printf("(%d,%d) (%d,%d) (%d,%d)\n", X[i], Y[i], X[j], Y[j], X[k], Y[k]);
//                    printf("%d %d %d\n", L[0], L[1], L[2]);
                    cnt[make_pair(make_pair(L[0], L[1]), L[2])]++;
                }
        map<pair<pair<int, int>, int>, int>::iterator ptr;
        for (ptr = cnt.begin(); ptr != cnt.end(); ptr++)
            ans = max(ans, ptr->second);
        printf("%d\n", ans);
    }
    return 0;
}
