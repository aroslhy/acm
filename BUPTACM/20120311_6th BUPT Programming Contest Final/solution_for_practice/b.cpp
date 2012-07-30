#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct susr
{
	char id[24];
	char post[111];
	int len;
	void read()
	{
		scanf("%s%s", id, post);
		len = strlen(post);
	}
	bool operator<(const susr &u) const
	{
		if (len == u.len)
			if (strcmp(post, u.post)==0)
				return strcmp(id, u.id)<0;
			else
				return strcmp(post, u.post)>0;
		else
			return len > u.len;
	}
}usr[10010];
int N;

int main()
{
	int i, j, k;
	while (~scanf("%d", &N))
	{
		for (i = 0; i < N; ++i)
			usr[i].read();
		sort(usr, usr+N);
		for (i = 0; i < N; ++i)
			puts(usr[i].id);
	}
	return 0;
}
