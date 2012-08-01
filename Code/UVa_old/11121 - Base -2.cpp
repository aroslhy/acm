#include<cstdio>
using namespace std;
int T, n;
int Div(int x)
{
    if (x%-2 < 0) return x/-2+1;
    return x/-2;
}
int Mod(int x)
{
    if (x%-2 < 0) return 1;
    return x%-2;
}
void print_ans(int x)
{
    if (Div(x)) print_ans(Div(x));
    printf("%d", Mod(x));
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
	    scanf("%d", &n);
	    printf("Case #%d: ", cas);
	    print_ans(n);
	    printf("\n");
	}
	return 0;
}
