#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 20+5, MAXM = 640000+5, MAXP = 400+5;
const int INF = 0x3f3f3f3f;
int N;
struct Node
{
    int dps, hp;
} E[MAXN];
bool operator < (const Node a, const Node b)
{
    return b.dps*a.hp < a.dps*b.hp;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &N) != EOF)
    {
        int A = 0, ans = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%d%d", &E[i].dps, &E[i].hp);
            A += E[i].dps;
        }
        sort(E, E+N);
        for (int i = 0; i < N; i++)
        {
//            printf("%d %d\n", E[i].dps, E[i].hp);
            ans += A*E[i].hp;
            A -= E[i].dps;
        }
        printf("%d\n", ans);
    }
    return 0;
}
