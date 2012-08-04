#include<cstdio>
//#include<cstring>
//#include<algorithm>
using namespace std;
//const int MAXN = 30+5;
int n;
//char seq[MAXN][10000];
//bool vis[MAXN];
//void Seq(int x)
//{
//    if (!vis[x-1]) Seq(x-1);
//    char num = '0'; int cnt;
//    int len = strlen(seq[x-1]);
//    int j = 0;
//    for (int i = 0; i <= len; i++)
//    {
//        if (seq[x-1][i] != num)
//        {
//            if (num != '0')
//                seq[x][j++] = '0'+cnt, seq[x][j++] = num;
//            num = seq[x-1][i], cnt = 1;
//        }
//        else
//            cnt++;
//    }
//    seq[x][j] = '\0';
//}
int a[30] = {1,2,2,4,6,6,8,10,14,20,26,34,46,62,78,102,134,176,226,302,408,528,678,904,1182,1540,2012,2606,3410,4462};
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    strcpy(seq[1], "1"); vis[1] = 1;
//    Seq(30);
//    for (int i = 1; i <= 30; i++)
//        printf("%d,", strlen(seq[i]));
    while (scanf("%d", &n) && n)
        printf("%d\n", a[n-1]);
    return 0;
}
