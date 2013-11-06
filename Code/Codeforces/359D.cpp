#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 300000+5;
int N, a[MAXN], L[MAXN], R[MAXN];
vector<int> vec;
int main()
{
	freopen("put.in", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
		int j = i;
		while (j > 1 && !(a[j-1]%a[i]))
			j = L[j-1];
		L[i] = j;
	}
	for (int i = N; i >= 1; i--)
	{
		int j = i;
		while (j < N && !(a[j+1]%a[i]))
			j = R[j+1];
		R[i] = j;
	}
	int maxi = -1;
	for (int i = 1; i <= N; i++)
	{
		int len = R[i]-L[i];
		if (len > maxi)
		{
			maxi = len;
			vec.clear();
			vec.push_back(L[i]);
		}
		else if (len == maxi)
			vec.push_back(L[i]);
	}
	sort(vec.begin(), vec.end());
	vec.resize(distance(vec.begin(), unique(vec.begin(), vec.end())));
	printf("%d %d\n", vec.size(), maxi);
	for (int i = 0; i < (int)vec.size(); i++)
	{
		if (i)
			printf(" ");
		printf("%d", vec[i]);
	}
	printf("\n");
	return 0;
}
