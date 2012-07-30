#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_NODE_NUM = 352525;
const int INF = 65535;
const int ROOT = 1;

struct Node{
    int l, r;
    long long max_value, count;
    long long cover;
}tr[MAX_NODE_NUM];
int sz;

struct Segment{
    int x, y1, y2, t, w;
    bool operator <(const Segment &n)const
    {
        if(x != n.x) return x < n.x;
        return t < n.t;
    }
    void set(int _x, int _y1, int _y2, int _t, int _w)
    {
        x = _x, y1 = _y1, y2 = _y2, t = _t, w = _w;
    }
}ss[121212];

long long ans_max_value;
long long ans_count;
int N, T, X[51515], Y[51515], G[51515], H, W;

void init()
{
    ans_max_value = 0;
    ans_count = INF;
}

void build(int k, int l, int r)
{
    tr[k].l = l, tr[k].r = r;
    tr[k].max_value = tr[k].cover = 0;
    tr[k].count = (l==r && l%2==0) ? 1 : INF;
    if(l<r){
        build(k*2, l, (l+r)/2);
        build(k*2+1, (l+r)/2+1, r);
    }
}

void update_node(int k)
{
    if(tr[k].l < tr[k].r){
        tr[k*2].cover += tr[k].cover;
        tr[k*2+1].cover += tr[k].cover;
    }
    tr[k].max_value += tr[k].cover;
    tr[k].cover = 0;
}

void add_segment(int k, int l, int r, int v)
{
    update_node(k);
    if(l <= tr[k].l && tr[k].r <= r){
        tr[k].cover += v;
    } else{
        int m = (tr[k].l+tr[k].r)/2, pl = k*2, pr = k*2+1;
        if(l <= m) add_segment(pl, l, r, v);
        if(m < r) add_segment(pr, l, r, v);
        update_node(pl);
        update_node(pr);
        long long tmx = max(tr[pl].max_value, tr[pr].max_value);
        tr[k].max_value = tmx;
        tr[k].count = 0;
        if(tr[pl].max_value == tmx){
            tr[k].count = tr[pl].count;
        }
        if(tr[pr].max_value == tmx){
            tr[k].count += tr[pr].count;
        }
    }
    update_node(k);
}

int main()
{
//    freopen("data.in","r",stdin);
//    freopen("data.out","w",stdout);
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d%d", &N, &H, &W);
        int min_x = 100000, max_x = 0, min_y = 100000, max_y = 0;
        for(int i = 0; i < N; i++){
            char gg[10];
            scanf("%s%d%d", gg, &X[i], &Y[i]);
            int w;
            if(gg[0] == 'G') w = 1;
            else w = -INF;
            ss[i*2].set(X[i], Y[i]*2, (Y[i]+H)*2, 0, w);
            ss[i*2+1].set(X[i]+W, Y[i]*2, (Y[i]+H)*2, 1, -w);
            min_x = min(min_x, X[i]);
            max_x = max(max_x, X[i]+W);
            min_y = min(min_y, Y[i]*2);
            max_y = max(max_y, (Y[i]+H)*2);
        }
        sort(ss, ss+N*2);
        init();
        build(ROOT, min_y, max_y);
        for(int i = 0, up = N*2; i < up; ){
            while(i < up && ss[i].t == 0){
                add_segment(ROOT, ss[i].y1, ss[i].y2, ss[i].w);
                if(++i >= up || ss[i].x != ss[i-1].x) break;
            }
            if(ans_max_value < tr[ROOT].max_value){
                ans_max_value = tr[ROOT].max_value;
                ans_count = tr[ROOT].count;
            } else if(ans_max_value == tr[ROOT].max_value){
                ans_count += tr[ROOT].count;
            }
            
            while(i < up && ss[i].t == 1){
                add_segment(1, ss[i].y1, ss[i].y2, ss[i].w);
                if(++i >= up || ss[i].x != ss[i-1].x) break;
            }
            if(ans_max_value <= tr[ROOT].max_value){
                ans_max_value = tr[ROOT].max_value;
                ans_count = INF;
            }
        }
        if(ans_count >= INF){
            printf("so many!\n");
        } else{
            printf("%lld\n", ans_count);
        }
        printf("%lld\n\n", ans_max_value);
        
    }
    return 0;
}

