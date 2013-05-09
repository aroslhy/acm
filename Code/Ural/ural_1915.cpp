// aroslhy	URAL 1915	Accepted	8489 KB	531 ms	G++ 4.7.2	438 B	2013-05-09 09:53:53
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int N, x;
int main()
{
	scanf("%d", &N);
	vector<int> vec;
	while (N--)
	{
		scanf("%d", &x);
		if (x > 0)
			vec.push_back(x);
		else if (x == -1)
		{
			printf("%d\n", vec[vec.size()-1]);
			vec.pop_back();
		}
		else if (vec.size() < N)
		{
			int n = vec.size();
			for (int i = 0; i < n; i++)
				vec.push_back(vec[i]);
		}
	}
	return 0;
}
