#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int MAXN = 30+5;
int N;
//long long D(int a, int b, int c, int p)
//{
//    long long &res = d[a][b][c][p];
//    if (res != -1)
//        return res;
//    if (!a && !b && !c)
//    {
//        if (p != 1)
//            return res = 1;
//        else
//            return res = 0;
//    }
//    res = 0;
//    if (p == 1)
//    {
//        if (b)
//            res += b*D(a, b-1, c, 2);
//        if (c)
//            res += c*D(a, b, c-1, 3);
//    }
//    if (p == 2)
//    {
//        if (c)
//            res += c*D(a, b, c-1, 3);
//        if (a)
//            res += a*D(a-1, b, c, 1);
//    }
//    if (p == 3)
//    {
//        if (a)
//            res += a*D(a-1, b, c, 1);
//        if (b)
//            res += b*D(a, b-1, c, 2);
//    }
//    return res;
//}
const int base = 10000; // (base^2) fit into int
const int width = 4; // width = log base
const int maxN = 150; // n * width: 可表示的最大位数
struct bint{
int ln, v[maxN];
bint (int r = 0) { // r应该是字符串！
for (ln = 0; r > 0; r /= base) v[ln++] = r % base;
}
bint& operator = (const bint& r) {
memcpy(this, &r, (r.ln + 1) * sizeof(int));// !
return *this;
}
} ;
bool operator < (const bint& a, const bint& b){
int i;
if (a.ln != b.ln) return a.ln < b.ln;
for (i = a.ln - 1; i >= 0 && a.v[i] == b.v[i]; i--);
return i < 0 ? 0 : a.v[i] < b.v[i];
}
bool operator <= (const bint& a, const bint& b){
return !(b < a);
}
bint operator + (const bint& a, const bint& b){
bint res; int i, cy = 0;
for (i = 0; i < a.ln || i < b.ln || cy > 0; i++) {
if (i < a.ln) cy += a.v[i];
if (i < b.ln) cy += b.v[i];
res.v[i] = cy % base; cy /= base;
}
res.ln = i;
return res;
}
bint operator - (const bint& a, const bint& b){
bint res; int i, cy = 0;
for (res.ln = a.ln, i = 0; i < res.ln; i++) {
res.v[i] = a.v[i] - cy;
if (i < b.ln) res.v[i] -= b.v[i];
if (res.v[i] < 0) cy = 1, res.v[i] += base;
else cy = 0;
}
while (res.ln > 0 && res.v[res.ln - 1] == 0) res.ln--;
return res;
}
bint operator * (const bint& a, const bint& b){
bint res; res.ln = 0;
if (0 == b.ln) { res.v[0] = 0; return res; }
int i, j, cy;
for (i = 0; i < a.ln; i++) {
for (j=cy=0; j < b.ln || cy > 0; j++, cy/= base) {
if (j < b.ln) cy += a.v[i] * b.v[j];
if (i + j < res.ln) cy += res.v[i + j];
if (i + j >= res.ln) res.v[res.ln++] = cy % base;
else res.v[i + j] = cy % base;
}
}
return res;
}
bint operator / (const bint& a, const bint& b)
{ // ! b != 0
bint tmp, mod, res;
int i, lf, rg, mid;
mod.v[0] = mod.ln = 0;
for (i = a.ln - 1; i >= 0; i--) {
mod = mod * base + a.v[i];
for (lf = 0, rg = base -1; lf < rg; ) {
mid = (lf + rg + 1) / 2;
if (b * mid <= mod) lf = mid;
else rg = mid - 1;
}
res.v[i] = lf;
mod = mod - b * lf;
}
res.ln = a.ln;
while (res.ln > 0 && res.v[res.ln - 1] == 0) res.ln--;
return res; // return mod 就是%运算
}
int digits(bint& a) // 返回位数
{
if (a.ln == 0) return 0;
int l = ( a.ln - 1 ) * 4;
for (int t = a.v[a.ln - 1]; t; ++l, t/=10) ;
return l;
}
bool read(bint& b, char buf[]) // 读取失败返回0
{
if (1 != scanf("%s", buf)) return 0;
int w, u, ln = strlen(buf);
memset(&b, 0, sizeof(bint));
if ('0' == buf[0] && 0 == buf[1]) return 1;
for (w = 1, u = 0; ln; ) {
u += (buf[--ln] - '0') * w;
if (w * 10 == base) {
b.v[b.ln++] = u; u = 0; w = 1;
}
else w *= 10;
}
if (w != 1) b.v[b.ln++] = u;
return 1;
}
void write(const bint& v){
int i;
printf("%d", v.ln == 0 ? 0 : v.v[v.ln - 1]);
for (i = v.ln - 2; i >= 0; i--)
printf("%04d", v.v[i]); // ! 4 == width
printf("\n");
}

bint d[MAXN][MAXN][MAXN][4];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i <= N-1; i++)
        for (int j = 0; j <= N; j++)
            for (int k = 0; k <= N; k++)
                for (int p = 1; p <= 3; p++)
                {
                    if (!i && !j && !k && p != 1)
                    {
                        d[i][j][k][p] = bint(1);
                        continue;
                    }
                    if (p == 1)
                    {
                        if (j)
                            d[i][j][k][p] = d[i][j][k][p]+(bint)j*d[i][j-1][k][2];
                        if (k)
                            d[i][j][k][p] = d[i][j][k][p]+(bint)k*d[i][j][k-1][3];
                    }
                    if (p == 2)
                    {
                        if (k)
                            d[i][j][k][p] = d[i][j][k][p]+(bint)k*d[i][j][k-1][3];
                        if (i)
                            d[i][j][k][p] = d[i][j][k][p]+(bint)i*d[i-1][j][k][1];
                    }
                    if (p == 3)
                    {
                        if (i)
                            d[i][j][k][p] = d[i][j][k][p]+(bint)i*d[i-1][j][k][1];
                        if (j)
                            d[i][j][k][p] = d[i][j][k][p]+(bint)j*d[i][j-1][k][2];
                    }
                }
    bint ans = d[N-1][N][N][1]/2;
    write(ans);
    return 0;
}
