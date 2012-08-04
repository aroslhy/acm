#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 29+5, MAXM = 100+5;
int K, N, I, J, s[MAXN], t, X[MAXN], A[MAXN][MAXN], B[MAXN];
void showmat()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            printf("%d ", A[i][j]);
        printf("%d\n", B[i]);
    }
    printf("\n");
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &K);
    while (K--)
    {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d", &s[i]);
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &t);
            if (t != s[i])
                B[i] = 1;
            A[i][i] = 1;
        }
        while (scanf("%d%d", &I, &J) && I && J)
            A[J][I] = 1;
//        showmat();
        for (int i = 1; i <= N; i++)
        {
            int tp = i;
            for (int j = i+1; j <= N; j++)
                if (A[j][i] > A[tp][i])
                    tp = j;
            if (tp != i)
            {
                for (int j = 1; j <= N; j++)
                    swap(A[tp][j], A[i][j]);
                swap(B[tp], B[i]);
            }
            if (A[i][i])
                for (int j = i+1; j <= N; j++) if (A[j][i])
                {
                    int c = A[j][i]/A[i][i];
                    for (int k = 1; k <= N+1; k++)
                    {
                        A[j][k] -= A[i][k]*c;
                        A[j][k] = A[j][k]%2 ? 1 : 0;
                    }
                    B[j] -= B[i]*c;
                    B[j] = B[j]%2 ? 1 : 0;
                }
//            showmat();
        }
        int freevar = 0;
        bool flag = 1;
        for (int i = N; i >= 1 && flag; i--)
        {
            int s = B[i];
            for (int j = i+1; j <= N; j++)
                s -= A[i][j]*X[j];
            if (A[i][i])
                X[i] = A[i][i]*s;
            else if (!s)
                freevar++;
            else
                flag = 0;
        }
        if (flag)
            printf("%d\n", 1<<freevar);
        else
            printf("Oh,it's impossible~!!\n");
    }
    return 0;
}
