//Oct 1, 2012 7:42:03 PM 	bigoceanlhy 	230A - Dragons 	GNU C++ 	Accepted 	46 ms 	0 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5;
int N, s, x[MAXN], y[MAXN], r[MAXN];
bool cmp(const int a, const int b)
{
    return x[a] < x[b];
}
int main()
{
    scanf("%d%d", &s, &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        r[i] = i;
    }
    sort(r, r+N, cmp);
    bool flag = 1;
    for (int i = 0; i < N && flag; i++)
    {
        if (s > x[r[i]])
            s += y[r[i]];
        else
            flag = 0;
    }
    printf("%s\n", flag ? "YES" : "NO");
    return 0;
}
