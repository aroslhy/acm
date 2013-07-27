// Jul 27, 2013 2:58:18 PM	bigoceanlhy	 333A - Secrets	 GNU C++	Accepted	 30 ms	 0 KB
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 38;
long long N, pow3[MAX];
int n, bit[MAX];
int main()
{
	pow3[0] = 1;
	for (int i = 1; i < MAX; i++)
		pow3[i] = pow3[i-1]*3;
	cin>>N;
	long long sum = 0;
	bool flag = 0;
	for (int i = 0; ; i++)
	{
		if (!N)
		{
			n = i;
			break;
		}
		bit[i] = N%3;
		N /= 3;
	}
	for (int i = 0, p; i <= n; i++)
	{
		if (sum)
			sum += bit[i]*pow3[i-p-1];
		else if (flag)
			sum += (bit[i]+1)*pow3[i-p-1];
		else if (bit[i])
		{
			flag = 1;
			p = i;
		}
	}
	cout<<sum<<"\n";
	return 0;
}
