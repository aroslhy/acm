#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int MAXN = 100+5;
int n;
double x_1, y_1, x_2, y_2, y[MAXN<<1];
map<double, int> My;
struct Line
{
    double x, ya, yb;
    int InOut;
    Line(){}
    Line(double X, double Ya, double Yb, int inout)
    {
        x = X; ya = Ya; yb = Yb; InOut = inout;
    }
} line[MAXN<<1];
bool cmp(const Line a, const Line b)
{
    return a.x < b.x;
}
struct Node
{
    int cov;
    double sum;
} T[MAXN<<3];
void Change(int idx, int L, int R, int l, int r, int inout)
{
    int left = idx<<1, right = (idx<<1)^1;
    if (L == l && R == r)
        T[idx].cov += inout;
    else
    {
        int mid = (L+R)>>1;
        if (r <= mid)
            Change(left, L, mid, l, r, inout);
        else if (mid <= l)
            Change(right, mid, R, l, r, inout);
        else
        {
            Change(left, L, mid, l, mid, inout);
            Change(right, mid, R, mid, r, inout);
        }
    }
    if (T[idx].cov)
        T[idx].sum = y[R]-y[L];
    else if (R-L == 1)
        T[idx].sum = 0;
    else
        T[idx].sum = T[left].sum+T[right].sum;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    for (int cas = 0; scanf("%d", &n) && n; )
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf%lf", &x_1, &y_1, &x_2, &y_2);
            line[i<<1] = Line(x_1, y_1, y_2, 1);
            line[(i<<1)^1] = Line(x_2, y_1, y_2, -1);
            y[i<<1] = y_1;
            y[(i<<1)^1] = y_2;
        }
        sort(line, line+(n<<1), cmp);
        sort(y, y+(n<<1));
        for (int i = 0; i < (n<<1); i++)
            My[y[i]] = i;
        memset(T, 0, sizeof(T));
        double ans = 0;
        for (int i = 0; i < (n<<1)-1; i++)
        {
            Change(1, 0, (n<<1)-1, My[line[i].ya], My[line[i].yb], line[i].InOut);
            ans += T[1].sum*(line[i+1].x-line[i].x);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n", ++cas, ans);
    }
    return 0;
}
