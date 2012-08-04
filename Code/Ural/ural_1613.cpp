#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int MAXN = 70000+5;
const int INF = 0x3f3f3f3f;
int n, q, c[MAXN], d[MAXN], l, r, x;
vector<int> V[MAXN];
map<int, int> M;
int find_x(int L, int R){
    int mid = (L+R)>>1;
    if (x == d[mid])
        return mid;
    else if (L < R){
        if (x < d[mid])
            return find_x(L, mid);
        else
            return find_x(mid+1, R);
    }
    else
        return 0;
}
bool find_p(int L, int R, int X){
    int mid = (L+R)>>1;
    if (l <= V[X][mid] && V[X][mid] <= r)
        return 1;
    else if (L < R){
        if (r < V[X][mid])
            return find_p(L, mid, X);
        else
            return find_p(mid+1, R, X);
    }
    else
        return 0;
}
int main(){
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    memcpy(d, c, sizeof(c));
    sort(d+1, d+1+n);
    for (int i = 1; i <= n; i++)
        if (d[i] == d[i+1])
            d[i] = INF;
    sort(d+1, d+1+n);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (d[i] < INF)
            M[d[i]] = ++cnt;
        else break;
    for (int i = 1; i <= n; i++)
        V[M[c[i]]].push_back(i);
    scanf("%d", &q);
    while (q--){
        scanf("%d%d%d", &l, &r, &x);
        bool flag = 0;
        int X = find_x(1, cnt);
        if (X && find_p(0, V[X].size()-1, X))
            flag = 1;
        printf(flag ? "1" : "0");
    }
    printf("\n");
    return 0;
}
