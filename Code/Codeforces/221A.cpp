//Aug 31, 2012 7:46:56 PM 	bigoceanlhy 	221A - Little Elephant and Function 	GNU C++ 	Accepted 	30 ms 	700 KB 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5;
int n, a[MAXN];
void f(int x)
{
    if (x == 1)
        return;
    f(x-1);
    swap(a[x-1], a[x]);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    scanf("%d", &n);
    printf("%d", n);
    for (int i = 1; i < n; i++)
        printf(" %d", i);
    printf("\n");
    return 0;
}
