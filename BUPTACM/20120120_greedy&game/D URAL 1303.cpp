#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int MAXN = 100000+5, INF = 0x3f3f3f3f;
int M, L[MAXN], R[MAXN], n, r[MAXN];
vector<int> V;
bool cmp(const int a, const int b)
{
    if (L[a] != L[b])
        return L[a] < L[b];
    else
        return R[a] < R[b];
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &M);
    for (int i = 1; ; i++)
    {
        scanf("%d%d", &L[i], &R[i]);
        if (!L[i] && !R[i])
        {
            n = i-1;
            break;
        }
        r[i] = i;
    }
    sort(r+1, r+1+n, cmp);
    int cur = 0;
    bool flag = 1;
    for (int j = 1; flag; )
    {
        int E = 0;
        for (int i = j; i <= n; i++, j++)
        {
            int e = r[i];
            if (L[e] <= cur)
            {
                if (R[E] < R[e])
                    E = e;
            }
            else
                break;
        }
        if (E)
            V.push_back(E), cur = R[E];
        else
            flag = 0;
        if (M <= cur) break;
    }
    if (flag)
    {
        printf("%d\n", (int)V.size());
        for (int i = 0; i < (int)V.size(); i++)
            printf("%d %d\n", L[V[i]], R[V[i]]);
    }
    else
        printf("No solution\n");
    return 0;
}
