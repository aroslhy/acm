/*
    题意：平面上两个点集(N<=50000, 同一点集内无重合点)，问他们是否相似,
        即 S可以通过平移、放缩、旋转后与T重合。
        O(NlgN)
    解:
        求出每个点集的重心. 平移使两个点集重心重合.
        统计每个点集中所有点到重心的距离之和. 两个点集的距离和之比即为缩放比例.
        将两个点集缩放至相同大小.
        将每个点集以重心为原点极角排序, 建立特征序列.
        特征序列的每一项为:该点到重心的距离,以及该点到下一个点的旋转夹角.
        判断两个点集的特征序列是否循环相等. 可以用KMP(或者最小表示法).
        对seqS+"$"+seqT+seqT求next数组, 若在seqT+seqT子串中有某项next值等于len(seqS),说明相等.
        
    tricks: 
      只有1个点
      重心上有点(极角排序时该点位置不定)
      所有点在一条直线上
      
      by wolf5x
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath> 
#include <vector>
#include <assert.h>
using namespace std;

#define DEBUG -1

#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define SZ(x) ((x).size())

const double EPS = 1e-6;
const double PI = 3.141592653589793;

typedef pair<double,double> PAIR;
int T, _, N;
vector<PAIR> dot[2], seq[2], str;
double len[2];
vector<int> nxt;

int dblcmp(double x, double y, int f = 0)
{
    if (abs(x)<EPS && abs(y)<EPS) 
        return 0;
    if (abs(x-y)/(max(abs(x),abs(y))) < EPS)
        return 0;
    return x < y ? -1 : 1;
}

int angcmp(double x, double y)
{
    double t = abs(x-y);
    if(dblcmp(t, 0) == 0 || dblcmp(t, PI*2) == 0)
        return 0;
    return dblcmp(x, y);
}

double dist2(PAIR a, PAIR b)
{
    return (a.FI-b.FI)*(a.FI-b.FI) + (a.SE-b.SE)*(a.SE-b.SE);
}

double dist(PAIR a, PAIR b)
{
    return sqrt(dist2(a,b));
}

double dmul(PAIR u, PAIR v)
{
    return u.FI*v.FI + u.SE*v.SE;
}

double xmul(PAIR u, PAIR v)
{
    return u.FI*v.SE - v.FI*u.SE;
}

double radius(PAIR a)
{
    return dist(a, MP(0,0));
}

double rot_angle(PAIR o, PAIR a, PAIR b)
{
    PAIR u = MP(a.FI-o.FI, a.SE-o.SE);
    PAIR v = MP(b.FI-o.FI, b.SE-o.SE);
    double dm = dmul(u, v), di = dist(o,a)*dist(o,b);
    double ang = acos(abs(dm/di)>1.0 ? dm/abs(dm) : dm/di);
    return xmul(u, v) >= 0 ? ang : PI*2-ang;
}

bool comp(PAIR a, PAIR b)
{
    double anga = atan2(a.SE, a.FI);
    double angb = atan2(b.SE, b.FI);
    int t = angcmp(anga, angb);
    if(t != 0) 
        return t < 0;
    double la = radius(a);
    double lb = radius(b);
    return dblcmp(la, lb) < 0;
}

bool equal(PAIR a, PAIR b)
{
    return (dblcmp(a.FI, b.FI, 1) == 0 && angcmp(a.SE, b.SE) == 0);
}

void kmp_next()
{
    nxt.resize(str.size()+1);
    int i = 0, j = -1;
    for(nxt[0] = -1; i < str.size(); ){
        while(j >= 0 && !equal(str[i], str[j]))
            j = nxt[j];
        nxt[++i] = ++j;
    }
}

bool solve()
{
    if(N == 1)
        return true;
    // calculate mass center and total lenth
    for(int k = 0; k < 2; k++){
        PAIR cc = MP(0,0);
        for(int i = 0; i < N; i++) 
            cc.FI += dot[k][i].FI, cc.SE += dot[k][i].SE;
        cc.FI /= N, cc.SE /= N;
        for(int i = 0; i < N; i++)
            dot[k][i].FI -= cc.FI, dot[k][i].SE -= cc.SE;
        len[k] = 0;
        for(int i = 0; i < N; i++)
            len[k] += radius(dot[k][i]);
        sort(dot[k].begin(), dot[k].end(), comp);
    }

    int u = len[0]>len[1]?0:1;
    double f = len[u]/len[1-u];
    for(int i = 0; i < N; i++){
        dot[u][i].FI /= f;
        dot[u][i].SE /= f;
    }
    // erase the dot which is at the mass center
    for(int k = 0; k < 2; k++)
        for(int i = N-1; i >= 0; i--)
            if(dblcmp(radius(dot[k][i]), 0) == 0)
                dot[k].erase(dot[k].begin()+i);
    if(dot[0].size() != dot[1].size())
        return false;
    
    // make sequence
    int n = dot[0].size();
    for(int k = 0; k < 2; k++){
        seq[k].resize(n);
        for(int i = 0; i < n; i++){
            double l = radius(dot[k][i]);
            double a = rot_angle(MP(0,0), dot[k][i], dot[k][(i+1)%n]);
            seq[k][i] = MP(l, a);
        }
    }
    
    // do kmp match
    str.resize(n*3+1);
    copy(seq[0].begin(), seq[0].end(), str.begin());
    str[n] = MP(-1,-1);
    copy(seq[1].begin(), seq[1].end(), str.begin()+n+1);
    copy(seq[1].begin(), seq[1].end(), str.begin()+n*2+1);
    
    kmp_next();
    
    for(int i = n+1; i <= n*3+1; i++)
        if(nxt[i] == n)
            return true;
    return false;
}

int main()
{ 
    //freopen("data.in","r",stdin); 
    //freopen("data.out","w",stdout);
    scanf("%d", &T);
    for(_ = 1; _ <= T; _++){
        scanf("%d", &N);
        for(int i = 0; dot[i].resize(N), i < 2; i++)
            for(int j = 0; j < N; j++)
                scanf("%lf%lf", &dot[i][j].FI, &dot[i][j].SE);
        printf("Case #%d: %s\n", _, solve()?"YES":"NO");
    }
    
    return 0;
}
