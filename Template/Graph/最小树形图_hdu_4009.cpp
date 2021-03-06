/*
题意：有n个地方需要供水，每个地方都可以选择是自己挖井，还是从别的地方引水，根据方法不同和每个地方的坐标不同，花费也不同，现在给出每个地方的坐标，花费的计算方法，以及每个地方可以给哪些地方供水（即对方可以从这里引水），求给所有地方供水的最小花费。
思路：显然对于每个地方，只有一种供水方式就足够了，这样也能保证花费最小，而每个地方都可以自己挖井，所以是不可能出现无解的情况的，为了方便思考，我们引入一个虚拟点，把所有自己挖井的都连到这个点，边权为挖井的花费，而如果i能从j处引水，则从j向i连边，边权为引水的花费，然后对这个有向图，以虚拟点为根，求最小树形图即可（最小树形图即为有向图的最小生成树）。
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5, MAXM = 1001000+5;
const int INF = 0x3f3f3f3f;
int N, X, Y, Z, K, x[MAXN], y[MAXN], z[MAXN];
int e, u[MAXM], v[MAXM], w[MAXM];
int pre[MAXN], id[MAXN], vis[MAXN];
int in[MAXN];
int Directed_MST(int root,int NV,int NE) //number vertices from zero!!!
{
	int res = 0;
	for (;;)
	{
		//1.找最小入边
		for (int i = 0; i < NV; i++)
			in[i] = INF, id[i] = -1, vis[i] = -1;
		for (int i = 0; i < NE; i++)
		{
			int s = u[i], t = v[i];
			if (w[i] < in[t] && s != t)
			{
				pre[t] = s;
				in[t] = w[i];
			}
		}
		for (int i = 0; i < NV; i++)
		{
			if (i == root)
				continue;
			if (in[i] == INF)
				return -1;//除了跟以外有点没有入边,则根无法到达它
		}
		//2.找环
		int cntnode = 0;
		in[root] = 0;
		for (int i = 0; i < NV; i++)
		{//标记每个环
			res += in[i];
			int t = i;
			for (; vis[t] != i && id[t] == -1 && t != root; t = pre[t])
				vis[t] = i;
			if (t != root && id[t] == -1)
			{
				for (int s = pre[t] ; s != t ; s = pre[s])
					id[s] = cntnode;
				id[t] = cntnode++;
			}
		}
		if (!cntnode)
			break;//无环
		for (int i = 0; i < NV; i++)
			if (id[i] == -1)
				id[i] = cntnode++;
		//3.缩点,重新标记
		for (int i = 0; i < NE; i++)
		{
			int t = v[i];
			u[i] = id[u[i]];
			v[i] = id[v[i]];
			if (u[i] != v[i])
				w[i] -= in[t];
		}
		NV = cntnode;
		root = id[root];
	}
	return res;
}
void addedge(int x, int y, int z)
{
	u[e] = x; v[e] = y; w[e] = z;
	e++;
}
int main()
{
	while (scanf("%d%d%d%d", &N, &X, &Y, &Z))
	{
		if (!N && !X && !Y && !Z)
			break;
		e = 0;
		int root = 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d%d%d", &x[i], &y[i], &z[i]);
			addedge(root, i, z[i]*X);
		}
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &K);
			for (int k = 1, j; k <= K; k++)
			{
				scanf("%d", &j);
				if (z[i] < z[j])
					addedge(i, j, (abs(x[i]-x[j])+abs(y[i]-y[j])+abs(z[i]-z[j]))*Y+Z);
				else
					addedge(i, j, (abs(x[i]-x[j])+abs(y[i]-y[j])+abs(z[i]-z[j]))*Y);
			}
		}
		printf("%d\n", Directed_MST(root, N+1, e));
	}
	return 0;
}
