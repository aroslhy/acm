#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 200+5, MAXM = 40000+5, MAXP = 50+5;
int T, N;
long long a[5][MAXN], A[2][MAXM];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &N);
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < N; j++)
                scanf("%lld", &a[i][j]);
        int cnt0 = 0, cnt1 = 0;
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
            {
                A[0][cnt0++] = a[0][j]+a[1][k];
                A[1][cnt1++] = a[2][j]+a[3][k];
            }
        sort(A[0], A[0]+cnt0);
        sort(A[1], A[1]+cnt1);
        bool flag = 0;
        for (int i = 0; i < N && !flag; i++)
        {
            int p0 = 0, p1 = cnt1-1;
            while (p0 < cnt0 && p1 >= 0 && !flag)
            {
                if (A[0][p0]+A[1][p1]+a[4][i] < 0)
                    p0++;
                else if (A[0][p0]+A[1][p1]+a[4][i] > 0)
                    p1--;
                else
                    flag = 1;
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}
