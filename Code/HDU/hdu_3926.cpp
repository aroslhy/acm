#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 10000+5, MAXM = 10000+5, MAXP = 1000000+5;
int T, N[2], M[2], cnt[MAXN], p[MAXN], iscir[MAXN];
struct Edge
{
    int u, v;
} e[MAXM];
struct Group
{
    bool ISC;
    int num;
    Group(int x, int y)
    {
        ISC = x; num = y;
    }
};
bool operator < (const Group a, const Group b)
{
    if (a.ISC != b.ISC)
        return a.ISC < b.ISC;
    else
        return a.num < b.num;
}
vector<Group> vec[2];
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        for (int k = 0; k < 2; k++)
        {
            memset(iscir, 0, sizeof(iscir));
            memset(cnt, 0, sizeof(cnt));
            vec[k].clear();
            scanf("%d%d", &N[k], &M[k]);
            for (int i = 1; i <= N[k]; i++)
                p[i] = i, cnt[i] = 1;
            for (int i = 1; i <= M[k]; i++)
            {
                int x, y;
                scanf("%d%d", &x, &y);
                int u = find(x), v = find(y);
                if (u == v)
                    iscir[u] = 1;
                else
                {
                    p[u] = v;
                    cnt[v] += cnt[u];
                }
            }
            for (int i = 1; i <= N[k]; i++) if (i == p[i])
                vec[k].push_back(Group(iscir[i], cnt[i]));
        }
        int cnt0 = vec[0].size(), cnt1 = vec[1].size();
        bool flag = 1;
        if (N[0] == N[1] && M[0] == M[1] && cnt0 == cnt1)
        {
            for (int k = 0; k < 2; k++)
                sort(vec[k].begin(), vec[k].end());
//            for (int k = 0; k < 2; k++)
//            {
//                for (int i = 0; i < (int)vec[k].size(); i++)
//                    printf("%d %d\n", vec[k][i].ISC, vec[k][i].num);
//                printf("\n");
//            }
            for (int i = 0; i < cnt0 && flag; i++)
                if (vec[0][i].ISC != vec[1][i].ISC || vec[0][i].num != vec[1][i].num)
                    flag = 0;
        }
        else
            flag = 0;
        printf("Case #%d: %s\n", cas, flag ? "YES" : "NO");
    }
    return 0;
}
