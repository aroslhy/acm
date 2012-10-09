#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 150+5, MAXM = 22500+5, MAXP = 50+5;
int N, M, a, b;
int e, head[MAXN], next[MAXM], v[MAXM];
int mark[MAXN];
vector<int> vec;
void Init()
{
    e = 0;
    memset(head, -1, sizeof(head));
    memset(mark, -1, sizeof(mark));
    vec.clear();
}
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e++;
}
bool dfs(int u, int step = 0)
{
    mark[u] = step;
    vec.push_back(u);
    for (int i = head[u]; i != -1; i = next[i])
    {
        if (mark[v[i]] == -1)
        {
            if (dfs(v[i], step+1))
                return 1;
        }
        else if (step-mark[v[i]]+1 == N)
            return 1;
    }
    mark[u] = -1;
    vec.pop_back();
    return 0;
}
int main()
{
    while (scanf("%d%d", &N, &M) != EOF)
    {
        Init();
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d", &a, &b);
            addedge(a, b);
            addedge(b, a);
        }
        if (dfs(1))
        {
            for (int i = 0; i < (int)vec.size(); i++)
            {
                if (i)
                    printf(" ");
                printf("%d", vec[i]);
            }
            printf("\n");
        }
        else
            printf("no solution\n");
    }
    return 0;
}
