#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int MAXN = 1000+5;
int T, V, N;
struct Equ{int A, B;} equ[MAXN];
bool cmp(const Equ a, const Equ b)
{
    return max(a.A+b.B, a.B) < max(b.A+a.B, b.B);
}
int main()
{

//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &V, &N);
        for (int i = 1; i <= N; i++)
            scanf("%d%d", &equ[i].A, &equ[i].B);
        sort(equ+1, equ+1+N, cmp);
        bool flag = 1;
        for (int i = 1; i <= N; i++)
        {
            if (V < equ[i].B)
            {
                flag = 0;
                break;
            }
            V -= equ[i].A;
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
