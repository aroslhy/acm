//Jul 27, 2013 12:49:22 PM	bigoceanlhy	 334A - Candy Bags	 GNU C++	Accepted	 30 ms	 0 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= N>>1; j++)
		{
			if (j > 1)
				printf(" ");
			printf("%d", i*N/2+j);
		}
		for (int j = 1; j <= N>>1; j++)
			printf(" %d", N*N-i*N/2-j+1);
		printf("\n");
	}
	return 0;
}
