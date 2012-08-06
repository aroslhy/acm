//2012-08-05 10:43:10	Accepted	4331	2812MS	20028K	3485 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1000+5, MAXM = 10000+5, MAXP = 1000000+5;
int T, N, mat[MAXN][MAXN];
int u[MAXN][MAXN], d[MAXN][MAXN], l[MAXN][MAXN], r[MAXN][MAXN];
int Tr[MAXN<<2];
struct Node
{
    bool inout;
    int X, x, y;
    Node (bool a, int d, int b, int c)
    {
        inout = a; X = d; x = b; y = c;
    }
};
bool operator < (const Node a, const Node b)
{
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.inout > b.inout;
}
vector<Node> vec;
//void Init(int idx, int L, int R)
//{
//    if (L == R)
//    {
//        Tr[idx] = 0;
//        return;
//    }
//    int mid = (L+R)>>1, left = (idx<<1), right = (idx<<1)^1;
//    Init(left, L, mid);
//    Init(right, mid+1, R);
//    Tr[idx] = Tr[left]+Tr[right];
//}
void Update(int idx, int L, int R, int x, int c)
{
    if (L == x && R == x)
    {
        Tr[idx] = c;
        return;
    }
    int mid = (L+R)>>1, left = (idx<<1), right = (idx<<1)^1;
    if (x <= mid)
        Update(left, L, mid, x, c);
    else
        Update(right, mid+1, R, x, c);
    Tr[idx] = Tr[left]+Tr[right];
}
int Query(int idx, int L, int R, int l, int r)
{
    if (L == l && R == r)
        return Tr[idx];
    int mid = (L+R)>>1, left = (idx<<1), right = (idx<<1)^1;
    if (r <= mid)
        return Query(left, L, mid, l, r);
    else if (mid < l)
        return Query(right, mid+1, R, l, r);
    else
        return Query(left, L, mid, l, mid)+Query(right, mid+1, R, mid+1, r);
}
int Calc(int a, int b)
{
    int res = 0;
    vec.clear();
    for (int i = a, j = b; i <= N && j <= N; i++, j++)
        if (mat[i][j])
        {
            vec.push_back(Node(1, i, i, j));
            vec.push_back(Node(0, i, i+min(d[i][j], r[i][j])-1, j+min(d[i][j], r[i][j])-1));
        }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < (int)vec.size(); i++)
    {
        if (vec[i].inout)
        {
            Update(1, 1, N, vec[i].X, 1);
            res += Query(1, 1, N, vec[i].x-min(u[vec[i].x][vec[i].y], l[vec[i].x][vec[i].y])+1, vec[i].x);
        }
        else
            Update(1, 1, N, vec[i].X, 0);
    }
//    printf("%d,%d,%d,%d:%d\n", a, b, s, t, res);
    return res;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                scanf("%d", &mat[i][j]);
                u[i][j] = mat[i][j];
                if (i > 1 && mat[i][j])
                    u[i][j] += u[i-1][j];
                l[i][j] = mat[i][j];
                if (j > 1 && mat[i][j])
                    l[i][j] += l[i][j-1];
            }
        for (int i = N; i >= 1; i--)
            for (int j = N; j >= 1; j--)
            {
                d[i][j] = mat[i][j];
                if (i < N && mat[i][j])
                    d[i][j] += d[i+1][j];
                r[i][j] = mat[i][j];
                if (j < N && mat[i][j])
                    r[i][j] += r[i][j+1];
            }
        int ans = 0;
        for (int i = N; i >= 2; i--)
            ans += Calc(1, i);
        ans += Calc(1, 1);
        for (int i = 2; i <= N; i++)
            ans += Calc(i, 1);
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}
