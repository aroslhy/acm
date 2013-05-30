// 1746	aroslhy(Aros)	Accepted	 732ms	 5324KB	 GPP	 1394 B	 2013-05-30 20:10
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 100000+5;
int N, M, a, l, r, p[MAXN], p1[MAXN], p2[MAXN], sum1[MAXN], sum2[MAXN];
bool cmp(const char &a, const char &b)
{
	return a > b;
}
int hash(int x)
{
	char s[15];
	sprintf(s, "%d", x);
	sort(s, s+strlen(s), cmp);
	sscanf(s, "%d", &x);
	return x;
}
int main()
{
	while (scanf("%d%d", &N, &M) != EOF)
	{
		map<int, int> mp;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &a);
			int h = hash(a);
			if (mp.find(h) != mp.end())
				p[i] = mp[h];
			else
				p[i] = 0;
			mp[h] = i;
			p1[i] = max(p1[i-1], p[i]);
			sum1[i] = sum1[i-1]+p1[i];
			p2[i] = max(max(p2[i-1], p[p[i]]), min(p1[i-1], p[i]));
			sum2[i] = sum2[i-1]+p2[i];
		}
		int k = 0;
		while (M--)
		{
			scanf("%d%d", &l, &r);
			l += k, r -= k, k = 0;
			int x = 0, left = l, right = r+1;
			while (left < right)
			{
				int mid = (left+right)>>1;
				if (p1[mid] >= l)
					x = right = mid;
				else
					left = mid+1;
			}
			if (x)
				k += sum1[r]-sum1[x-1]-(r-x+1)*(l-1);
			x = 0, left = l, right = r+1;
			while (left < right)
			{
				int mid = (left+right)>>1;
				if (p2[mid] >= l)
					x = right = mid;
				else
					left = mid+1;
			}
			if (x)
				k -= sum2[r]-sum2[x-1]-(r-x+1)*(l-1);
			printf("%d\n", k);
		}
	}
	return 0;
}
