//2012-08-25 09:06:45	Accepted	4391	578MS	3736K	2619 B	C++	Aros
#include<cstdio>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100000+5;
const int INF = 0x3f3f3f3f;
int N, M, cmd, a, b;
unsigned int color[MAXN], z;
unsigned int Tr[MAXN<<2], Tmax[MAXN<<2], Tmin[MAXN<<2];
void PushUp(int idx)
{
    int left = idx*2, right = idx*2+1;
    if (Tr[left] == Tr[right])
        Tr[idx] = Tr[left];
    else
        Tr[idx] = -1;
    Tmin[idx] = min(Tmin[left], Tmin[right]);
    Tmax[idx] = max(Tmax[left], Tmax[right]);
}
void PushDown(int idx)
{
    int left = idx*2, right = idx*2+1;
    Tr[left] = Tr[right] = Tr[idx];
    Tmin[left] = Tmin[right] = Tmin[idx];
    Tmax[left] = Tmax[right] = Tmax[idx];
}
void Init(int idx, int L, int R)
{
    if (L == R)
    {
        Tr[idx] = Tmin[idx] = Tmax[idx] = color[L];
        return;
    }
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    Init(left, L, mid);
    Init(right, mid+1, R);
    PushUp(idx);
}
void Update(int idx, int L, int R, int l, int r, int c)
{
    if (l <= L && R <= r)
    {
        Tr[idx] = Tmin[idx] = Tmax[idx] = c;
        return;
    }
    if (Tr[idx] != -1)
        PushDown(idx);
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    if (l <= mid && Tr[left] != c)
        Update(left, L, mid, l, r, c);
    if (mid < r && Tr[right] != c)
        Update(right, mid+1, R, l, r, c);
    PushUp(idx);
}
int Query(int idx, int L, int R, int l, int r, int c)
{
    if (l <= L && R <= r)
    {
        if (Tr[idx] != -1)
        {
            if (Tr[idx] == c)
                return R-L+1;
            else
                return 0;
        }
        else if (c < Tmin[idx] || Tmax[idx] < c)
            return 0;
    }
    if (Tr[idx] != -1)
        PushDown(idx);
    int mid = (L+R)/2, left = idx*2, right = idx*2+1;
    int q = 0;
    if (l <= mid)
        q += Query(left, L, mid, l, r, c);
    if (mid < r)
        q += Query(right, mid+1, R, l, r, c);
    return q;
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    while (scanf("%d%d", &N, &M) != EOF)
    {
        for (int i = 0; i < N; i++)
            scanf("%u", &color[i]);
        Init(1, 0, N-1);
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d%u", &cmd, &a, &b, &z);
            if (cmd == 1)
                Update(1, 0, N-1, a, b, z);
            else
            {
                int ans = Query(1, 0, N-1, a, b, z);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}

//分段哈希(TLE)
//#include<cstdio>
//#include<cstring>
//#include<cmath>
//#include<algorithm>
//#include<queue>
//using namespace std;
//const int MAXN = 100489, MAXM = 317+5;
//const int INF = 0x3f3f3f3f;
//const unsigned int HASH = 1009;
//int N, M, cmd, a, b;
//int e[MAXM], head[MAXM][HASH], next[MAXM][MAXM], v[MAXM][MAXM], w[MAXM][MAXM];
//unsigned int color[MAXN], z, mark[MAXM];
//void init()
//{
//    memset(e, 0, sizeof(e));
//    memset(head, -1, sizeof(head));
//    memset(mark, -1, sizeof(mark));
//}
//int find(int j, unsigned int c, int h)
//{
//    for (int k = head[j][h]; k != -1; k = next[j][k])
//        if (v[j][k] = c)
//            return k;
//    return -1;
//}
//void update(int j, unsigned int c, int a)
//{
//    int h = c%HASH, k = find(j, c, h);
//    if (k != -1)
//        w[j][k] += a;
//    else
//    {
//        v[j][e[j]] = c;
//        w[j][e[j]] = a;
//        next[j][e[j]] = head[j][h];
//        head[j][h] = e[j]++;
//    }
//}
//int main()
//{
//    freopen("onlinejudge.in", "r", stdin);
////    freopen("onlinejudge.out", "w", stdout);
//    for (int cas = 1; scanf("%d%d", &N, &M) != EOF; cas++)
//    {
////        printf("case %d:\n", cas);
//        init();
//        int len = sqrt(N+0.0)+1;
////        printf("%d %d %d\n", N, len, n);
//        for (int i = 0; i < N; i++)
//        {
////            printf("N=%d ", i);
//            scanf("%u", &color[i]);
//            update(i/len, color[i], 1);
//        }
//        for (int j = 0; j < M; j++)
//        {
////            printf("M=%d ", j);
//            scanf("%d%d%d%u", &cmd, &a, &b, &z);
////            printf("cmd = %d, a = %d, b = %d, z = %u\n", cmd, a, b, z);
//            if (cmd == 1)
//            {
//                int A = a/len, B = b/len;
//                if (A != B)
//                {
//                    e[A] = 0;
//                    memset(head[A], -1, sizeof(head[A]));
//                    for (int i = len*A; i < len*(A+1); i++)
//                    {
//                        if (a <= i)
//                            color[i] = z;
//                        else if (mark[A] != -1)
//                            color[i] = mark[A];
//                        update(A, color[i], 1);
//                    }
//                    mark[A] = -1;
//                    for (int i = A+1; i < B; i++)
//                    {
//                        e[i] = 0;
//                        memset(head[i], -1, sizeof(head[i]));
//                        update(i, z, len);
//                        mark[i] = z;
//                    }
//                    e[B] = 0;
//                    memset(head[B], -1, sizeof(head[B]));
//                    for (int i = len*B; i < len*(B+1) && i < N; i++)
//                    {
//                        if (i <= b)
//                            color[i] = z;
//                        else if (mark[B] != -1)
//                            color[i] = mark[B];
//                        update(B, color[i], 1);
//                    }
//                    mark[B] = -1;
//                }
//                else
//                {
//                    e[A] = 0;
//                    memset(head[A], -1, sizeof(head[A]));
//                    for (int i = len*A; i < len*(A+1); i++)
//                    {
//                        if (a <= i)
//                            color[i] = z;
//                        else if (mark[A] != -1)
//                            color[i] = mark[A];
//                        update(A, color[i], 1);
//                    }
//                    mark[A] = -1;
//                }
//            }
//            else
//            {
//                int A = a/len, B = b/len, ans = 0;
//                if (A != B)
//                {
//                    for (int i = len*A; i < len*(A+1); i++)
//                    {
//                        if (mark[A] != -1)
//                            color[i] = mark[A];
//                        if (a <= i && color[i] == z)
//                            ans++;
//                    }
//                    mark[A] = -1;
//                    for (int i = A+1; i < B; i++)
//                    {
//                        int k = find(i, color[i], color[i]%HASH);
//                        if (k != -1)
//                            ans += w[i][k];
//                    }
//                    for (int i = len*B; i < len*(B+1) && i < N; i++)
//                    {
//                        if (mark[B] != -1)
//                            color[i] = mark[B];
//                        if (i <= b && color[i] == z)
//                            ans++;
//                    }
//                    mark[B] = -1;
//                }
//                else
//                {
//                    for (int i = len*A; i < len*(A+1); i++)
//                    {
//                        if (mark[A] != -1)
//                            color[i] = mark[A];
//                        if (a <= i && color[i] == z)
//                            ans++;
//                    }
//                    mark[A] = -1;
//                }
//                printf("%d\n", ans);
//            }
////            for (int i = 0; i < N; i++)
////                printf("%u ", color[i]);
////            printf("\n");
//        }
////        printf("\n");
//    }
//    return 0;
//}
