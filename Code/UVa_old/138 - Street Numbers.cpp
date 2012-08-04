#include<cstdio>
using namespace std;
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	const int x0 = 3, y0 = 2;
	int x1 = x0, y1 = y0, x2, y2;
	for (int i = 1; i <= 10; i++)
	{
	    x2 = x1*x0+2*y1*y0;
	    y2 = x1*y0+y1*x0;
	    printf("%10d%10d\n", y2/2, (x2-1)/2);
	    x1 = x2, y1 = y2;
	}
	return 0;
}
