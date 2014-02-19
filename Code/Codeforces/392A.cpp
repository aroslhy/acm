#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long N;
int main()
{
	scanf("%I64d", &N);
	if (N)
	{
		long long i = N, j = 0;
		int ans = 0;
		while (i > 0)
		{
			ans++;
			if (i*i+(j+1)*(j+1) <= N*N)
				j++;
			else if ((i-1)*(i-1)+(j+1)*(j+1) <= N*N)
				j++, i--;
			else
				i--;
		}
		printf("%d\n", ans*4);
	}
	else
		printf("1\n");
}
