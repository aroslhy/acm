/*
ID: bigocea1
PROG: rect1
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
const int MAX = 2500+5;
int A, B, N, count_color[MAX];
struct Rectangle {int llx, lly, urx, ury, color;} rec[MAX];
void Search(int n, int llx, int lly, int urx, int ury)
{
    int i;
    for (i = n+1; i <= N && (llx >= rec[i].urx || urx <= rec[i].llx || lly >= rec[i].ury || ury <= rec[i].lly); i++);
    if (i > N)
        count_color[rec[n].color] += (urx-llx)*(ury-lly);
    else
    {
        if (llx < rec[i].llx)
            Search(n, llx, lly, rec[i].llx, ury), llx = rec[i].llx;
        if (urx > rec[i].urx)
            Search(n, rec[i].urx, lly, urx, ury), urx = rec[i].urx;
        if (lly < rec[i].lly)
            Search(n, llx, lly, urx, rec[i].lly);
        if (ury > rec[i].ury)
            Search(n, llx, rec[i].ury, urx, ury);
    }
}
int main()
{
    freopen("rect1.in", "r", stdin);
    freopen("rect1.out", "w", stdout);
    scanf("%d%d%d", &A, &B, &N);
    rec[0].llx = rec[0].lly = 0, rec[0].urx = A, rec[0].ury = B, rec[0].color = 1;
    for (int i = 1; i <= N; i++)
        scanf("%d%d%d%d%d", &rec[i].llx, &rec[i].lly, &rec[i].urx, &rec[i].ury, &rec[i].color);
    for (int i = N; i >= 0; i--)
        Search(i, rec[i].llx, rec[i].lly, rec[i].urx, rec[i].ury);
    for (int i = 1; i <= MAX; i++)
        if (count_color[i])
            printf("%d %d\n", i, count_color[i]);
	return 0;
}
