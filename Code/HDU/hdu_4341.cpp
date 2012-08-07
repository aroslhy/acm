//2012-08-07 19:47:53	Accepted	4341	859MS	756K	1964 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 200+5, MAXM = 40000+5;
int N, T, x, y, t, v, d[MAXM], match[2][MAXN][MAXN];
struct Node
{
    int x, y, t, v;
    Node(int a, int b, int c = 0, int d = 0)
    {
        x = a; y = b; t = c; v = d;
    }
};
bool operator < (const Node a, const Node b)
{
    return a.y < b.y;
}
vector<Node> V[MAXN];
int gcd(int x, int y)
{
    return x ? gcd(y%x, x) : y;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int cas = 0;
    while (scanf("%d%d", &N, &T) != EOF)
    {
        memset(d, 0, sizeof(d));
        memset(match, 0, sizeof(match));
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%d%d%d%d", &x, &y, &t, &v);
            int X, Y;
            if (x)
            {
                int g = gcd(abs(x), y);
                X = x/g, Y = y/g;
            }
            else
                X = 0, Y = 1;
            Node u = Node(x, y, t, v);
            int &m = match[x < 0 ? 1 : 0][X][Y];
            if (m)
                V[m].push_back(u);
            else
            {
                m = ++cnt;
                V[m].clear();
                V[m].push_back(u);
            }
        }
        for (int j = 1; j <= cnt; j++)
            for (int i = T; i >= 0; i--)
            {
                int tot = 0, tov = 0;
                sort(V[j].begin(), V[j].end());
                for (int k = 0; k < (int)V[j].size(); k++)
                {
                    tot += V[j][k].t;
                    tov += V[j][k].v;
                    if (i-tot >= 0)
                        d[i] = max(d[i], d[i-tot]+tov);
                    else
                        break;
                }
            }
        printf("Case %d: %d\n", ++cas, d[T]);
    }
    return 0;
}
