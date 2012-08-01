#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int MAXN = 10000+5;
struct Node
{
    int L, R, len;
    int seg_num, cov_num, sum;
    int cov_L, cov_R;
    Node()
    {
        L = R = 0;
        len = seg_num = cov_num = sum = 0;
        cov_L = cov_R = 0;
    }
} T[4*MAXN];
struct Line
{
    int x, y1_, y2;
    bool InOut;
    Line(){}
    Line(int x_, int y1__, int y2_, bool inout)
    {
        x = x_, y1_ = y1__, y2 = y2_, InOut = inout;
    }
} line[MAXN];
bool cmp(const Line a, const Line b)
{
    return a.x < b.x;
}
int y[MAXN], cnt;
int n, x1, y1_, x2, y2;
void Build(int l, int r, int i)
{
    T[i].L = l; T[i].R = r;
    T[i].len = y[r]-y[l];
    T[i].cov_num = 0;
    T[i].seg_num = 0;
    T[i].sum = 0;
    T[i].cov_L = T[i].cov_R = 0;
    if (r-l > 1)
    {
        int mid = (l+r)>>1;
        Build(l, mid, 2*i+0);
        Build(mid, r, 2*i+1);
    }
}
void GetLen(int i)
{
    if (T[i].cov_num)
        T[i].sum = T[i].len;
    else if (T[i].R-T[i].L > 1)
        T[i].sum = T[2*i+0].sum+T[2*i+1].sum;
    else
        T[i].sum = 0;
}
void GetSegNum(int i)
{
    if (T[i].cov_num)
    {
        T[i].cov_L = T[i].cov_R = 1;
        T[i].seg_num = 1;
    }
    else if (T[i].R-T[i].L > 1)
    {
        T[i].cov_L = T[2*i+0].cov_L;
        T[i].cov_R = T[2*i+1].cov_R;
        T[i].seg_num = T[2*i+0].seg_num+T[2*i+1].seg_num-T[2*i+0].cov_R*T[2*i+1].cov_L;
    }
    else
    {
        T[i].cov_L = T[i].cov_R = 0;
        T[i].seg_num = 0;
    }
}
void Insert(int l, int r, int i)
{
    if (T[i].L == l && T[i].R == r)
        T[i].cov_num++;
    else
    {
        int mid = (T[i].L+T[i].R)>>1;
        if (r <= mid)
            Insert(l, r, 2*i+0);
        else if (mid <= l)
            Insert(l, r, 2*i+1);
        else
        {
            Insert(l, mid, 2*i+0);
            Insert(mid, r, 2*i+1);
        }
    }
    GetLen(i);
    GetSegNum(i);
}
void Delete(int l, int r, int i)
{
    if (T[i].L == l && T[i].R == r)
        T[i].cov_num--;
    else
    {
        int mid = (T[i].L+T[i].R)>>1;
        if (r <= mid)
            Delete(l, r, 2*i+0);
        else if (mid <= l)
            Delete(l, r, 2*i+1);
        else
        {
            Delete(l, mid, 2*i+0);
            Delete(mid, r, 2*i+1);
        }
    }
    GetLen(i);
    GetSegNum(i);
}
int GetIndex(int x)
{
    return lower_bound(y, y+cnt, x)-y;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &x1, &y1_, &x2, &y2);
        line[2*i+0] = Line(x1, y1_, y2, 1);
        line[2*i+1] = Line(x2, y1_, y2, 0);
        y[2*i+0] = y1_;
        y[2*i+1] = y2;
    }
    sort(y, y+2*n);
    sort(line, line+2*n, cmp);
    cnt = 0;
    for (int i = 1; i < 2*n; i++)
        if (y[i-1] != y[i])
            y[cnt++] = y[i-1];
    y[cnt++] = y[2*n-1];
    Build(0, cnt-1, 1);
    int ans = 0, sum_ = 0;
    for (int i = 0; i < 2*n-1; i++)
    {
        if (line[i].InOut)
            Insert(GetIndex(line[i].y1_), GetIndex(line[i].y2), 1);
        else
            Delete(GetIndex(line[i].y1_), GetIndex(line[i].y2), 1);
        ans += T[1].seg_num*(line[i+1].x-line[i].x)*2;
        ans += fabs(T[1].sum-sum_);
        sum_ = T[1].sum;

    }
    Delete(GetIndex(line[2*n-1].y1_), GetIndex(line[2*n-1].y2), 1);
    ans += fabs(T[1].sum-sum_);
    printf("%d\n", ans);
    return 0;
}
