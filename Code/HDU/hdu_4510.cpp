// 2013-03-23 18:18:26	Accepted	4510	0MS	228K	578 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, HH, MM, SS, hh, mm, ss;
int main()
{
	scanf("%d", &N);
	while (N--)
	{
		int sf = 0, mf = 0;
		scanf("%d:%d:%d %d:%d:%d", &HH, &MM, &SS, &hh, &mm, &ss);
//		printf("%d %d %d %d %d %d\n", HH, MM, SS, hh, mm, ss);
		if (SS >= ss)
			SS -= ss;
		else
		{
			SS = SS+60-ss;
			sf = 1;
		}
		if (MM >= mm+sf)
			MM -= mm+sf;
		else
		{
			MM = MM+60-(mm+sf);
			mf = 1;
		}
		HH -= hh+mf;
		HH = (HH%12+12)%12;
		printf("%02d:%02d:%02d\n", HH, MM, SS);
	}
	return 0;
}
