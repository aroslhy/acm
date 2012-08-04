#include<cstdio>
using namespace std;
int Ca, Cb, N;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	while (scanf("%d%d%d", &Ca, &Cb, &N) != EOF)
	{
	    int A = 0, B = 0;
	    while (B != N)
	    {
	        if (!A)
	            A = Ca, printf("fill A\n");
	        else
	        {
	            if (A+B <= Cb)
	                B += A, A = 0, printf("pour A B\n");
	            else
	            {
	                A -= (Cb-B), printf("pour A B\n");
	                B = 0, printf("empty B\n");
	            }
	        }
	    }
	    printf("success\n");
	}
	return 0;
}
