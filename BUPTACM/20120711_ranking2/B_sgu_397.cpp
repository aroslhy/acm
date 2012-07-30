#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000000+5, MAXM = 50+5, MAXP = 200+5;
const int INF = 0x3f3f3f3f;
char s[MAXN], out[MAXN];
int l[MAXN], r[MAXN];
int main()
{
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    scanf("%s", s);
//    printf("%s\n", s);
    int len = strlen(s);
    int head = 0, end = 1, now = 0, e = 2;
    r[head] = end;
    l[end] = head;
    for (int i = 0; i < len; i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            out[e] = s[i];
            l[e] = now;
            r[e] = r[now];
            r[now] = e;
            l[r[r[now]]] = e;
            now = e;
            e++;
        }
        else if (s[i] == 'L' && now != head)
            now = l[now];
        else if (s[i] == 'R' && r[now] != end)
            now = r[now];
    }
//    for (int i = 0; i < 6; i++)
//    {
//        printf("%d->%d->%d %c\n", l[i], i, r[i], out[i]);
//    }
    int p = head;
    while (r[p] != end)
    {
        p = r[p];
        printf("%c", out[p]);
    }
    printf("\n");
    return 0;
}
