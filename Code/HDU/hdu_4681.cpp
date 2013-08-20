// 2013-08-20 17:13:43	Accepted	4681	562MS	8132K	1744 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1000+5;
int T;
int f[MAXN][MAXN], g[MAXN][MAXN];
char A[MAXN], B[MAXN], C[MAXN];
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%s%s%s", A+1, B+1, C+1);
		int lenA = strlen(A+1), lenB = strlen(B+1), lenC = strlen(C+1);
		for (int i = 1; i <= lenA; i++)
			for (int j = 1; j <= lenB; j++)
			{
				if (A[i] == B[j])
					f[i][j] = f[i-1][j-1]+1;
				else
					f[i][j] = max(f[i-1][j], f[i][j-1]);
			}
		for (int i = 1; i <= lenA; i++)
			g[i][lenB+1] = 0;
		for (int i = 1; i <= lenB; i++)
			g[lenA+1][i] = 0;
		g[lenA+1][lenB+1] = 0;
		for (int i = lenA; i >= 1; i--)
			for (int j = lenB; j >= 1; j--)
			{
				if (A[i] == B[j])
					g[i][j] = g[i+1][j+1]+1;
				else
					g[i][j] = max(g[i+1][j], g[i][j+1]);
			}
		vector<pair<int, int> > VA, VB;
		int ans = lenC;
		for (int i = 1; i <= lenA; i++) if (A[i] == C[1])
		{
			int cur = 1;
			for (int j = i; j <= lenA; j++) if (C[cur] == A[j])
			{
				cur++;
				if (cur > lenC)
				{
					VA.push_back(make_pair(i, j));
					break;
				}
			}
		}
		for (int i = 1; i <= lenB; i++) if (B[i] == C[1])
		{
			int cur = 1;
			for (int j = i; j <= lenB; j++) if (C[cur] == B[j])
			{
				cur++;
				if (cur > lenC)
				{
					VB.push_back(make_pair(i, j));
					break;
				}
			}
		}
		vector<pair<int, int> >::iterator itA, itB;
		for (itA = VA.begin(); itA != VA.end(); itA++)
			for (itB = VB.begin(); itB != VB.end(); itB++)
				ans = max(ans, lenC+f[(*itA).first-1][(*itB).first-1]+g[(*itA).second+1][(*itB).second+1]);
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
