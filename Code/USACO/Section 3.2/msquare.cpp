/*
ID: bigocea1
PROG: msquare
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
const int MAXN = 3, MAXM = 362880+5;
const int MAXH = 1000007;
struct Node
{
    int value, cnt;
    string path;
} root;
queue<Node> Q;
int e, head[MAXH], next[MAXM], vs[MAXM];
int A(int x)
{
    int res = 0;
    for (int i = 0; i < 8; i++)
    {
        res = 10*res+x%10;
        x /= 10;
    }
    return res;
}
int B(int x)
{
    int a = x/100000, b = (x/10000)%10, c = (x/1000)%10, d = x%1000;
    return 10000000*b+10000*a+10*d+c;
}
int C(int x)
{
    int a = (x/1000000)%10, b = (x/100000)%10, c = (x/100)%10, d = (x/10)%10;
    return x-1000000*a-100000*b-100*c-10*d+1000000*d+100000*a+100*b+10*c;
}
bool try_to_insert(int x)
{
    int h = x%MAXH;
    for (int i = head[h]; i != -1; i = next[i])
        if (vs[i] == x)
            return 0;
    vs[e] = x;
    next[e] = head[h]; head[h] = e++;
    return 1;
}
int main()
{
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);
    memset(head, -1, sizeof(head));
    int FIN = 0;
    for (int i = 0; i < 8; i++)
    {
        int t;
        scanf("%d", &t);
        FIN = 10*FIN+t;
    }
    root.value = 12345678;
    Q.push(root);
    try_to_insert(root.value);
    while (!Q.empty())
    {
        Node u = Q.front(), v; Q.pop();
        if (u.value == FIN)
        {
            printf("%d\n%s\n", u.cnt, u.path.c_str());
            break;
        }
        v.value = A(u.value);
        if (try_to_insert(v.value))
        {
            v.path = u.path+"A";
            v.cnt = u.cnt+1;
            Q.push(v);
        }
        v.value = B(u.value);
        if (try_to_insert(v.value))
        {
            v.path = u.path+"B";
            v.cnt = u.cnt+1;
            Q.push(v);
        }
        v.value = C(u.value);
        if (try_to_insert(v.value))
        {
            v.path = u.path+"C";
            v.cnt = u.cnt+1;
            Q.push(v);
        }
    }
    return 0;
}
