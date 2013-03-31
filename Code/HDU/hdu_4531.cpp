// 2013-03-31 21:46:04	Accepted	4531	593MS	11912K	3756 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
int T, ans;
bool mov[6], vis[3][3][4], visc[10];
char one[10];
struct Node
{
	int mat[3][3], step;
} root;
bool operator < (const Node &a, const Node &b)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) if (a.mat[i][j] != b.mat[i][j])
			return a.mat[i][j] < b.mat[i][j];
	return 0;
}
int cid(char ch)
{
	if (ch == 'R')
		return 1;
	else if (ch == 'G')
		return 2;
	else if (ch == 'B')
		return 4;
	else
		return 8;
}
int get(int x, int c)
{
	if (c == 0)
		return x&15;
	else if (c == 1)
		return (x&240)>>4;
	else if (c == 2)
		return (x&3840)>>8;
	else
		return (x&61440)>>12;
}
void dfs(Node &u, int i, int j, int k, int c)
{
	if (vis[i][j][k])
		return;
	vis[i][j][k] = 1;
	if (k == 0)
	{
		if (i > 0 && c == get(u.mat[i-1][j], 1))
			dfs(u, i-1, j, 1, c);
		if (c == get(u.mat[i][j], 2))
			dfs(u, i, j, 2, c);
		if (c == get(u.mat[i][j], 3))
			dfs(u, i, j, 3, c);
	}
	else if (k == 1)
	{
		if (i+1 < 3 && c == get(u.mat[i+1][j], 0))
			dfs(u, i+1, j, 0, c);
		if (c == get(u.mat[i][j], 2))
			dfs(u, i, j, 2, c);
		if (c == get(u.mat[i][j], 3))
			dfs(u, i, j, 3, c);
	}
	else if (k == 2)
	{
		if (j > 0 && c == get(u.mat[i][j-1], 3))
			dfs(u, i, j-1, 3, c);
		if (c == get(u.mat[i][j], 0))
			dfs(u, i, j, 0, c);
		if (c == get(u.mat[i][j], 1))
			dfs(u, i, j, 1, c);
	}
	else
	{
		if (j+1 < 3 && c == get(u.mat[i][j+1], 2))
			dfs(u, i, j+1, 2, c);
		if (c == get(u.mat[i][j], 0))
			dfs(u, i, j, 0, c);
		if (c == get(u.mat[i][j], 1))
			dfs(u, i, j, 1, c);
	}
}
bool check(Node &u)
{
	memset(vis, 0, sizeof(vis));
	memset(visc, 0, sizeof(visc));
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 4; k++) if (!vis[i][j][k])
			{
				if (visc[get(u.mat[i][j], k)])
					return 0;
				dfs(u, i, j, k, get(u.mat[i][j], k));
				visc[get(u.mat[i][j], k)] = 1;
			}
	return 1;
}
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		memset(mov, 0, sizeof(mov));
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				scanf("%s", one);
				root.mat[i][j] = 0;
				for (int k = 0; k < 4; k++)
					root.mat[i][j] ^= cid(one[k])<<(4*k);
				if (one[4] == '1')
				{
					mov[i] = 1;
					mov[j+3] = 1;
				}
			}
		root.step = 0;
		queue<Node> que;
		set<Node> st;
		que.push(root);
		st.insert(root);
		bool ok = 0;
		while (!que.empty())
		{
			Node u = que.front();
			que.pop();
			if (check(u))
			{
				ok = 1;
				ans = u.step;
				break;
			}
			for (int i = 0; i < 3; i++) if (!mov[i])
			{
				Node v = u;
				int t = v.mat[i][0];
				v.mat[i][0] = v.mat[i][1];
				v.mat[i][1] = v.mat[i][2];
				v.mat[i][2] = t;
				if (st.find(v) == st.end())
				{
					v.step++;
					que.push(v);
					st.insert(v);
				}
				v = u;
				t = v.mat[i][2];
				v.mat[i][2] = v.mat[i][1];
				v.mat[i][1] = v.mat[i][0];
				v.mat[i][0] = t;
				if (st.find(v) == st.end())
				{
					v.step++;
					que.push(v);
					st.insert(v);
				}
			}
			for (int j = 0; j < 3; j++) if (!mov[j+3])
			{
				Node v = u;
				int t = v.mat[0][j];
				v.mat[0][j] = v.mat[1][j];
				v.mat[1][j] = v.mat[2][j];
				v.mat[2][j] = t;
				if (st.find(v) == st.end())
				{
					v.step++;
					que.push(v);
					st.insert(v);
				}
				v = u;
				t = v.mat[2][j];
				v.mat[2][j] = v.mat[1][j];
				v.mat[1][j] = v.mat[0][j];
				v.mat[0][j] = t;
				if (st.find(v) == st.end())
				{
					v.step++;
					que.push(v);
					st.insert(v);
				}
			}
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
