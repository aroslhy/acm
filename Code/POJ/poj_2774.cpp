#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 2*(100000+5);
string s, a, b;
//char s[MAXN]; // MAXN > 256
int len, sa[MAXN], height[MAXN], rank[MAXN], tmp[MAXN], top[MAXN];
void makesa()
{ // O(N * log N)
    int lena = len < 256 ? 256 : len;
    memset(top, 0, lena*sizeof(int));
    for (int i = 0; i < len ; i++)
        top[rank[i] = s[i]&0xff]++;
    for (int i = 1; i < lena; i++)
        top[i] += top[i-1];
    for (int i = 0; i < len ; i++)
        sa[--top[rank[i]]] = i;
    for (int j, k = 1; k < len; k <<= 1)
    {
        for (int i = 0; i < len; i++)
        {
            j = sa[i]-k;
            if (j < 0)
                j += len;
            tmp[top[rank[j]]++] = j;
        }
        sa[tmp[top[0] = 0]] = j = 0;
        for (int i = 1; i < len; i++)
        {
            if (rank[tmp[i]] != rank[tmp[i-1]] || rank[tmp[i]+k] != rank[tmp[i-1]+k])
                top[++j] = i;
            sa[tmp[i]] = j;
        }
        memcpy(rank, sa , len*sizeof(int));
        memcpy(sa , tmp, len*sizeof(int));
        if (j >= len-1)
            break;
    }
}
void lcp()
{ // O(4 * N)
    for (int i, k, j = rank[height[i = k = 0] = 0]; i < len-1; i++, k++)
        while (k >= 0 && s[i] != s[sa[j-1]+k])
            height[j] = k--, j = rank[sa[j]+1];
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    cin>>a>>b;
    s = a+"$"+b;
    len = s.length()+1; //!!!
    makesa();
    lcp();
    int ans = 0, mid = a.length();
    for (int i = 1; i < len; i++)
        if ((sa[i-1] < mid && sa[i] > mid) || (sa[i-1] > mid && sa[i] < mid))
            ans = max(ans, height[i]);
    cout<<ans<<endl;
    return 0;
}
