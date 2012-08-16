//2012-08-16 20:06:23	Accepted	4377	109MS	1044K	1039 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN = 100000+5;
int T, N, seq[MAXN], ans[MAXN];
int main()
{
    scanf("%d\n", &T);
    while (T--)
    {
        scanf("%d", &N);
        if (N == 1)
        {
            printf("1\n");
            continue;
        }
        for (int i = 1; i <= N; i++)
            seq[i] = i;
        int id = sqrt((double)N);
        if (id*id != N)
            id++;
        int cur = N, n = (N-id)/(id-1), r = (N-id)%(id-1);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= id; j++)
                ans[N-id*i+j] = seq[cur--];
        for (int j = 1; j <= r+1; j++)
            ans[N-(n*id+r+1)+j] = seq[cur--];
        for (int i = 0; cur > 0; i++)
            ans[N-(n*id+r+1)-i] = seq[cur--];
        for (int i = 1; i <= N; i++)
        {
            if (i > 1)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
