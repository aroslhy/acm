//比较高效的大数
#include<cstdio>
#include<cstring>
using namespace std;
const int base = 10000; // (base^2) fit into int
const int width = 4; // width = log base
const int maxn = 1000; // n*width: 可表示的最大位数
struct bint
{
    int len, s[maxn];
    bint (int r = 0)
    { // r应该是字符串！
        for (len = 0; r > 0; r /= base)
            s[len++] = r%base;
    }
    bint &operator = (const bint &r)
    {
        memcpy(this, &r, (r.len+1)*sizeof(int));// !
        return *this;
    }
};
bool operator < (const bint &a, const bint &b)
{
    int i;
    if (a.len != b.len) return a.len < b.len;
    for (i = a.len-1; i >= 0 && a.s[i] == b.s[i]; i--);
    return i < 0 ? 0 : a.s[i] < b.s[i];
}
bool operator <= (const bint &a, const bint &b)
{
    return !(b < a);
}
bint operator + (const bint &a, const bint &b)
{
    bint res; int i, cy = 0;
    for (i = 0; i < a.len || i < b.len || cy > 0; i++)
    {
        if (i < a.len)
            cy += a.s[i];
        if (i < b.len)
            cy += b.s[i];
        res.s[i] = cy%base; cy /= base;
    }
    res.len = i;
    return res;
}
bint operator - (const bint &a, const bint &b)
{
    bint res; int i, cy = 0;
    for (res.len = a.len, i = 0; i < res.len; i++)
    {
        res.s[i] = a.s[i]-cy;
        if (i < b.len)
            res.s[i] -= b.s[i];
        if (res.s[i] < 0)
            cy = 1, res.s[i] += base;
        else
            cy = 0;
    }
    while (res.len > 0 && res.s[res.len-1] == 0)
        res.len--;
    return res;
}
bint operator * (const bint &a, const bint &b)
{
    bint res; res.len = 0;
    if (0 == b.len)
    {
        res.s[0] = 0;
        return res;
    }
    int i, j, cy;
    for (i = 0; i < a.len; i++)
    {
        for (j=cy=0; j < b.len || cy > 0; j++, cy/= base)
        {
            if (j < b.len)
                cy += a.s[i]*b.s[j];
            if (i+j < res.len)
                cy += res.s[i+j];
            if (i+j >= res.len)
                res.s[res.len++] = cy%base;
            else
                res.s[i+j] = cy%base;
        }
    }
    return res;
}
bint operator / (const bint &a, const bint &b)
{ // ! b != 0
    bint tmp, mod, res;
    int i, lf, rg, mid;
    mod.s[0] = mod.len = 0;
    for (i = a.len-1; i >= 0; i--)
    {
        mod = mod*base+a.s[i];
        for (lf = 0, rg = base-1; lf < rg; )
        {
            mid = (lf+rg+1)/2;
            if (b*mid <= mod)
                lf = mid;
            else
                rg = mid-1;
        }
        res.s[i] = lf;
        mod = mod-b*lf;
    }
    res.len = a.len;
    while (res.len > 0 && res.s[res.len-1] == 0)
        res.len--;
    return res; // return mod 就是%运算
}
int digits(bint &a) // 返回位数
{
    if (a.len == 0) return 0;
    int l = (a.len-1)*4;
    for (int t = a.s[a.len-1]; t; ++l, t/=10);
    return l;
}
bool read(bint &b, char buf[]) // 读取失败返回0
{
    if (1 != scanf("%s", buf)) return 0;
    int w, u, len = strlen(buf);
    memset(&b, 0, sizeof(bint));
    if ('0' == buf[0] && 0 == buf[1]) return 1;
    for (w = 1, u = 0; len; )
    {
        u += (buf[--len]-'0')*w;
        if (w*10 == base)
        {
            b.s[b.len++] = u;
            u = 0;
            w = 1;
        }
        else
            w *= 10;
    }
    if (w != 1)
        b.s[b.len++] = u;
    return 1;
}
void write(const bint &v)
{
    int i;
    printf("%d", v.len == 0 ? 0 : v.s[v.len-1]);
    for (i = v.len-2; i >= 0; i--)
        printf("%04d", v.s[i]); // ! 4 == width
    printf("\n");
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int a, b; scanf("%d%d", &a, &b);
    bint A(a), B(b);
    if (B < A)
    {
        write(A+B);
        write(A-B);
        write(A*B);
        write(A/B);
    }
    return 0;
}
