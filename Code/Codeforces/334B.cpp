// Jul 27, 2013 2:54:09 PM	bigoceanlhy	 334B - Eight Point Sets	 GNU C++	Accepted	 30 ms	 100 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int x, y;
int main()
{
	set<int> stx, sty;
	set<pair<int, int> > stp;
	for (int i = 0; i < 8; i++)
	{
		scanf("%d%d", &x, &y);
		stx.insert(x);
		sty.insert(y);
		stp.insert(make_pair(x, y));
	}
	if (stx.size() == 3 && sty.size() == 3 && stp.size() == 8)
	{
		int mx = *(++stx.begin()), my = *(++sty.begin());
		if (stp.find(make_pair(mx, my)) == stp.end())
			printf("respectable\n");
		else
			printf("ugly\n");
	}
	else
		printf("ugly\n");
	return 0;
}
