#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 15000+5, MAXM = 32000+5;
int N, X, Y, lv[MAXN];
int Tr[MAXM<<2];
void Update(int idx, int L, int R){
    int left = (idx<<1), right = (idx<<1)^1;
    if (L == X && R == X)
        Tr[idx]++;
    else{
        int mid = ((L+R)>>1);
        if (X <= mid)
            Update(left, L, mid);
        else if (mid < X)
            Update(right, mid+1, R);
        Tr[idx] = Tr[left]+Tr[right];
    }
}
int Query(int idx, int L, int R, int l, int r){
    int left = (idx<<1), right = (idx<<1)^1;
    if (L == l && R == r)
        return Tr[idx];
    int mid = ((L+R)>>1);
    if (r <= mid)
        return Query(left, L, mid, l, r);
    else if (mid < l)
        return Query(right, mid+1, R, l, r);
    else
        return Query(left, L, mid, l, mid)+Query(right, mid+1, R, mid+1, r);
}
int main(){
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        scanf("%d%d", &X, &Y);
        lv[Query(1, 0, 32000, 0, X)]++;
        Update(1, 0, 32000);
    }
    for (int i = 0; i < N; i++)
        printf("%d\n", lv[i]);
    return 0;
}
