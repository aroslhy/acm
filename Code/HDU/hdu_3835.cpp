#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5, MAXM = 31623+5;
const int INF = 0x3f3f3f3f;
int N, A2[MAXM];
int find(int x, int y, int w)
{
    int mid = ((x+y)>>1);
    if (A2[mid] == w)
        return mid;
    if (x == y)
        return -1;
    else if (w < A2[mid])
        return find(x, mid, w);
    else
        return find(mid+1, y, w);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    for (int i = 0; i <= 31623; i++)
        A2[i] = i*i;
    while (scanf("%d", &N) != EOF)
    {
        int ans = 0;
        for (int i = 0; 2*A2[i] <= N; i++)
        {
            int p = find(i, 31622, N-A2[i]);
            if (p != -1)
            {
                int a = i ? 2 : 1;
                int b = p ? 2 : 1;
                int c = i != p ? 2 : 1;
                ans += a*b*c;
//                printf("(%d,%d)\n", i, p);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
