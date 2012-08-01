#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5, MAXM = 75+5;
const int INF = 0x3f3f3f3f;
int T;
long long N, M, K;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
//    cin>>T;
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%I64d%I64d%I64d", &N, &M, &K);
//        cin>>N>>M>>K;
        long long A = (N-1)+N*((M-1)+M*(K-1)), B = 0, m = 1;
        for (int i = 0; m < 2*N || m < 2*M || m < 2*K; i++)
        {
            if (m/2 < N && N <= m)
                B += i;
            if (m/2 < M && M <= m)
                B += i;
            if (m/2 < K && K <= m)
                B += i;
            m *= 2;
//            printf("%d %d\n", i, m);
        }
        printf("Case #%d: %I64d %I64d\n", cas, A, B);
//        cout<<"Case #"<<cas<<": "<<A<<" "<<B<<endl;
    }
    return 0;
}
