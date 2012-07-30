#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 100+5, INF = 0x3f3f3f3f;
string s;
int cnt[27], code[27];
int left_[60], right_[60], root;
struct Node{int num; int f;};
struct cmp
{
    bool operator ()(const Node a, const Node b)
    {
        return a.f > b.f;
    }
};
priority_queue<Node, vector<Node>, cmp> PQ;
void makecode(int x, int y)
{
    if (left_[x] == -1 && right_[x] == -1)
    {
        if (!y)
            code[x] = 1;
        else
            code[x] = y;
        return;
    }
    makecode(left_[x], y+1);
    makecode(right_[x], y+1);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (cin>>s)
    {
        if (s == "END") break;
        int len = (int)s.length();
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '_')
                cnt[26]++;
            else
                cnt[s[i]-'A']++;
        }
        for (int i = 0; i <= 26; i++)
            if (cnt[i])
            {
                Node n;
                n.num = i;
                n.f = cnt[i];
                PQ.push(n);
            }
        memset(left_, -1, sizeof(left_));
        memset(right_, -1, sizeof(right_));
        for (int x = 27; ; x++)
        {
            Node u = PQ.top(); PQ.pop();
            if (PQ.empty())
            {
                root = u.num;
                break;
            }
            Node v = PQ.top(); PQ.pop();
            Node w;
            w.f = u.f+v.f;
            w.num = x;
            left_[x] = u.num;
            right_[x] = v.num;
            PQ.push(w);
        }
        memset(code, 0, sizeof(code));
        makecode(root, 0);
        int code1 = 8*len, code2 = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '_')
                code2 += code[26];
            else
                code2 += code[s[i]-'A'];
        }
        printf("%d %d %.1lf\n", code1, code2, (double)code1/code2);
    }
    return 0;
}
