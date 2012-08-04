#include<cstdio>
#include<cmath>
using namespace std;
void exgcd(int a, int b, int &g, int &x, int &y)
{
    if (!b)
        g = a, x = 1, y = 0;
    else
        exgcd(b, a%b, g, y, x), y -= x*(a/b);
}
int T, x, k;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
	    scanf("%d%d", &x, &k);
	    int p, q, g;
	    exgcd((int)floor((double)x/(double)k), (int)ceil((double)x/(double)k), g, p, q);
	    p *= x/g, q *= x/g;
	    printf("%d %d\n", p, q);
	}
	return 0;
}
