#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5;
int T, N, t[MAXN];
int F(int x)
{
    if (x == 1) return t[1];
    else if (x == 2) return t[2];
    else if (x == 3) return t[1]+t[2]+t[3];
	return F(x-2)+min(t[1]+2*t[2]+t[x], 2*t[1]+t[x-1]+t[x]);
    // else if (t[1]+2*t[2]+t[x] < 2*t[1]+t[x-1]+t[x])
        // return t[1]+2*t[2]+t[x]+F(x-2);
    // else
        // return 2*t[1]+t[x-1]+t[x]+F(x-2);
}
int main()
{
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d", &t[i]);
        sort(t+1, t+1+N);
        printf("%d\n", F(N));
    }
    return 0;
}
