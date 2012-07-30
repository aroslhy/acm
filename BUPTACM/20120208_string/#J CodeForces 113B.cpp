#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
const int MAX = 2000+5, INF = 0x3f3f3f3f, MAXHASH = 10000;
string t, s1, s2;
vector<string> V[MAXHASH];
int ELFhash(string s)
{
    char key[MAX];
    strcpy(key, s.c_str());
    unsigned long h = 0;
    while (*key)
    {
        h = (h<<4)+(*key)++;
        unsigned long g = h&0xf0000000L;
        if (g) h ^= g>>24;
        h &= ~g;
    }
    return h%MAXHASH;
}
bool try_to_insert(string s)
{
    int h = ELFhash(s);
    for (int i = 0; i < (int)V[h].size(); i++)
        if (s == V[h][i])
            return 0;
    V[h].push_back(s);
    return 1;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    cin>>t>>s1>>s2;
    int lent = t.length();
    int len1 = s1.length();
    int len2 = s2.length();
    int ans = 0;
    for (int i = 0; i < lent; i++)
    {
        string sub1 = t.substr(i, len1);
        if (sub1 == s1)
        {
            for (int j = i; j+len2-1 < lent; j++)
            {
                string sub2 = t.substr(j, len2);
                if (sub2 == s2)
                {
                    string sub = t.substr(i, j-i+len2);
                    if (try_to_insert(sub))
                        ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
