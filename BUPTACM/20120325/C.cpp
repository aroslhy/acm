#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 250+5, MAXM = 100+5;
int N, X[MAXN], A[MAXN][MAXN], B[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        int x;
        while (scanf("%d", &x) && x != -1)
            A[x][i] = 1;
    }
    for (int i = 1; i <= N; i++)
        B[i] = 1;
//    for (int i = 1; i <= N; i++)
//    {
//        for (int j = 1; j <= N; j++)
//            printf("%d ", A[i][j]);
//        printf("%d\n", B[i]);
//    }
//    printf("\n");
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
    }
//    for (int i = 1; i <= N; i++)
//    {
//        for (int j = 1; j <= N; j++)
//            printf("%d ", A[i][j]);
//        printf("%d\n", B[i]);
//    }
//    printf("\n");
    for (int i = N; i >= 1; i--)
    {
        int s = B[i];
        for (int j = i+1; j <= N; j++)
            s -= A[i][j]*X[j];
        if (A[i][i] != 0 && s != 0)
            X[i] = A[i][i]*s;
        else if (A[i][i] == 0 && s != 0)
        {
            printf("No solution\n");
            return 0;
        }
    }
    bool flag = 0;
    for (int i = 1; i <= N; i++)
        if (X[i]%2)
        {
            if (flag)
                printf(" ");
            else
                flag = 1;
            printf("%d", i);
        }
    printf("\n");
    return 0;
}
