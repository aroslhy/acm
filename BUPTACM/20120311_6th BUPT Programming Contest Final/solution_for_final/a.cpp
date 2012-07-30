#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<climits>
#include<complex>
#include<cassert>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define all(x) x.begin(),x.end()
#define clr(x) memset((x),0,sizeof(x))
#define cdp(x) memset((x),-1,sizeof(x))
#define rep(i,n) for (i=0;i<n;i++)
#define Rep(i,a,b) for (i=a;i<=b;i++)
#define ff(i,x) for (i=start[x];i!=-1;i=a[i].next)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
const double eps=1e-8;
const double pi=acos(-1.0);
int dblcmp(double d){if (fabs(d)<eps)return 0;return d>eps?1:-1;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef char Type;
const int MAXL = 110020;
const int MaxQ = 110020;
struct treap{
    struct tnode{
        tnode *l, *r;
        int x, size, k;
        const int h;
        tnode(int a): l(NULL), r(NULL), x(a), k(1), h(rand()), size(0){}
        ~tnode(){
            delete l;
            delete r;
        }
        
        void upd(){
            size=k;
            if (l) size += l->size;
            if (r) size += r->size;
        }
    }* root;
    
    treap():root(NULL){}
    static tnode * zig(tnode *p) {
        tnode *t = p->l;
        p->l=t->r;
        t->r=p;
        p->upd();
        t->upd();
        return t;
    }
    static tnode * zag(tnode *p) {
        tnode *t = p->r;
        p->r=t->l;
        t->l=p;
        p->upd();
        t->upd();
        return t;
    }
    static tnode* merge(tnode *l, tnode *r) {
        if (l==NULL) return r;
        if (r==NULL) return l;
        if (l->h < r->h) {
            l->r = merge(l->r, r);
            l->upd();
            return l;
        }
        r->l = merge(l, r->l);
        r->upd();
        return r;
    }
    static tnode* insert(tnode *p, int a) {
        if (p==NULL) p = new tnode(a);
        else if (p->x == a) {
            p->k++;
        }else if (a < p->x) {
            p->l = insert(p->l, a);
            if (p->l->h < p->h)
                p = zig(p);
        }else {
            p->r = insert(p->r, a);
            if (p->r->h < p->h)
                p = zag(p);
        }
        p->upd();
        return p;
    }
    void insert(int a) {
        root = insert(root, a);
    }
    
    static tnode* remove(tnode *p, int a) {
        if (p==NULL) return NULL;
        else if (p->x == a) {
            p->k--;
            if (p->k == 0) {
                tnode * t = p;
                p = merge(p->l, p->r);
                t->l = t->r = NULL;
                delete t;
            }
        }else if (a < p->x) {
            p->l = remove(p->l, a);
        }else {
            p->r = remove(p->r, a);
        }
        if(p) p->upd();
        return p;
    }
    void remove(int a) {
        root = remove(root, a);
    }
    static int count(tnode *p, int a) {
        int ans;
        if (p==NULL) return 0;
        else if (p->x <= a) {
            ans = p->k;
            if (p->l) ans += p->l->size;
            ans += count(p->r, a);
            return ans;
        }else 
            return count(p->l, a);
    }
    int count(int a) {
        return count(root, a-1);
    }
    void cc(){
        delete root;
        root = NULL;
    }
};
struct bit 
{
    int n;
    treap gao[133333];
    void add(int x,int c)
    {
        for (int i=x;i<=n;i+=i&(-i))
        {
            gao[i].insert(c);
        }
    }
    void del(int x,int c)
    {
        for (int i=x;i<=n;i+=i&(-i))
        {
            gao[i].remove(c);
        }
    }
    int sum(int x,int v)
    {
        int y=0;
        for (int i=x;i;i-=i&(-i))
        {
            y+=gao[i].count(v);
        }
        return y;
    }
    void cc()
    {
        for (int i=0;i<133333;i++)
        {
            gao[i].cc();
        }
    }
}bt[2];

int len[250000];//len[i]Â±Ã­ÃÂ¾ÃÃiÃÂªÃÃÃÃÂµÃÂ»ÃÃÃÂ³Â¤Â¶Ã
void palindrome(char*cs)
{
    int n=strlen(cs);
    for (int i=0,j=0,k;i<n*2;i+=k,j=max(j-k,0))
    {
        while (i-j>=0&&i+j+1<n*2&&cs[(i-j)/2]==cs[(i+j+1)/2])j++;
        len[i]=j;
        for (k=1;i-k>=0&&j-k>=0&&len[i-k]!=j-k;k++)
        {
            len[i+k]=min(len[i-k],j-k);
        }
    }
}
int query(int a,int b,int c)
{
    //printf("%d %d %d\n",a,b,c);
    if (b>c)return 0;
    int f=-1-a;
    int l1,r1;
    if ((a+b)%2==0)
    {
        l1=(a+b)/2+1;
    }
    else 
    {
        l1=(a+b)/2+2;
    }
    if ((a+c)%2==0)
    {
        r1=(a+c)/2+1;
    }
    else 
    {
        r1=(a+c)/2+1;
    }
    int ans=r1-l1+1-(bt[0].sum(r1,f)-bt[0].sum(l1-1,f));
    if ((a+b)%2==0)
    {
        l1=(a+b)/2+1;
    }
    else 
    {
        l1=(a+b)/2+1;
    }
    if ((a+c)%2==0)
    {
        r1=(a+c)/2;
    }
    else 
    {
        r1=(a+c)/2+1;
    }
    //printf("%d %d %d\n",l1,r1,f);
    ans+=r1-l1+1-(bt[1].sum(r1,f+1)-bt[1].sum(l1-1,f+1));
    //printf("ans=%d\n",ans);
    return ans;    
}
inline int turnS(char i)
{
    return i-'a';
}
int l1,l2;
int lim;
struct SuffixTree_Small //of small alphabet
{
private:
    const static int setSize = 30;//size of char set
    const static int MaxS = MAXL*3;
    struct sufNode
    {
        int s,t;
        ll one ,two;
        sufNode *fa,*sl,*son[setSize];
        sufNode(){}
        sufNode(int s,int t,sufNode *fa,sufNode *sl):
                s(s),t(t),fa(fa),sl(sl)
        {
            one=two=0;
            memset(son,0,sizeof(son));
        }
    }sufBox[MaxS],*cur,*pre,*np;
    int snCnt,cT,fT,fId[MAXL];
    int Leaf;
    ll diffSub;
    char used[MaxS];
    inline sufNode *newSuf(int s,int t,sufNode *fa,sufNode *sl)
    {
        //if (snCnt>=MaxS)while (1);
        sufBox[snCnt] = sufNode(s,t,fa,sl);
        return &sufBox[snCnt++];
    }
public:
    void init()
    {
        sufBox[0] = sufNode(-1,-1,NULL,NULL);
        cur = sufBox,fT = cT = -1,snCnt = 1;
        Leaf = 0,diffSub = 0;
    }
    ll addText(Type *Text,int d)
    {
        int cd;
        pre = NULL;
        diffSub += Leaf;
        while (1)
        {
            if (cur->s > -1 && cT != cur->t) //split edge
            {
                if (Text[cT+1] == Text[d])
                {
                    ++cT;
                    break;
                }
                np = newSuf(cur->s,cT,cur->fa,NULL);//insert an internal node
                cur->fa->son[Text[cur->s]] = np;
                cur->fa = np,cur->s = cT+1;
                np->son[Text[cT+1]] = cur;
                cur = np;
            }
            else if (np = cur->son[Text[d]]) //explicit node
            {
                if (pre > sufBox) pre->sl = cur;
                cT = (cur = np)->s;
                break;
            }
            cur->son[Text[d]] = newSuf(d,-1,cur,NULL);//add a leaf
            ++Leaf,++diffSub;
            if (pre > sufBox) pre->sl = cur;//suffix link
            pre = cur;
            if (cur->sl)
                cur = cur->sl,cT = cur->t;
            else if (cur > sufBox)
            {
                fT -= cur->t-cur->s+1;
                cur = cur->fa;
                if (cur == sufBox) ++fT;
                else cur = cur->sl;
            }
            else
                break;
            while (fT+1 < d)
            {
                cur = cur->son[Text[fT+1]];
                cd = (cur->t == -1?d-fT:cur->t-cur->s)+1;
                if (fT+cd+1 < d) cT = cur->t,fT += cd;
                else cT = cur->s+d-1-fT-1,fT = d-1;
            }
        }
        ++fT;
        return diffSub;
        //printf("cT = %d , fT = %d , Leaf = %d , diffSub = %d\n",cT,fT,Leaf,diffSub);
    }
    /*****************************/
    void output(Type *Text,int d)
    {
        //printf("Node\tStart\tEnd\tfather\tSufLink\tString\n");
        int i,j;
        for (i = 0;i < snCnt;i++)
        {
            if (sufBox[i].t==-1)sufBox[i].t=d-1;continue;
            printf("%d\t%d\t%d\t%d\t%d\t",i,sufBox[i].s,sufBox[i].t,sufBox[i].fa?sufBox[i].fa-sufBox:-1,sufBox[i].sl?sufBox[i].sl-sufBox:-1);
            if (sufBox[i].s == -1) puts("NULL");
            else
            {
                for (j = sufBox[i].s;j < d;j++)
                {
                    if (sufBox[i].t > -1 && j > sufBox[i].t) break;
                    putchar(Text[j]);
                }
                puts("");
            }
        }
    }
    ll ans;
    void walkTree(int pl,sufNode *p)
    {
        int c = 0,cd;
        ll &one=p->one,&two=p->two;
        one=two=0;
        if (p->s > -1) pl += p->t-p->s+1;
        for (int i = 0;i <setSize;i++)
            if (p->son[i])
            {
                walkTree(pl,p->son[i]);
                one+=p->son[i]->one;
                two+=p->son[i]->two;
                ++c;
            }
        if (c == 0)
        {
            cd = p->t-pl+1;
            two++;
            if (cd<=l1)one++;
        }
        cd = p->t-pl+1;
        if (p->s>-1&&p->t<=l1)ans+=(ll)query(cd,max(p->s,cd+lim-1),p->t)*(two-one)*one;
    }
    ll walk(Type *Text,int end)
    {
        ans=0;
        walkTree(0,&sufBox[0]);
        return ans;
    }
};

SuffixTree_Small ST;
Type NS[MaxQ];
char s1[111111],s2[111111];
int main()
{
	//freopen("C:\\Users\\daizhy\\Desktop\\ÃÃ¢ÃÂ¿\\in.txt","r",stdin);
    int cas,cc=0;
    while (scanf("%d",&lim)!=EOF)
    {
        scanf("%s",s1);
        palindrome(s1);
        int l=strlen(s1),i;
        l1=l;
        bt[0].n=bt[1].n=120000;
        for (i=0;i<2*l;i+=2)
        {
            bt[0].add(i/2+1,(len[i]-1)/2-i/2-1);
        }
        for (i=1;i<2*l;i+=2)
        {
            bt[1].add(i/2+1,len[i]/2-i/2-1);
        }
        memset(NS,0,sizeof(NS));
        strcat(NS,s1);strcat(NS,"!");
        scanf("%s",s2);
        strcat(NS,s2);
        strcat(NS,"@");
        l=strlen(NS);
        //printf("%d\n",l);
        ST.init();
        for (int i=0;i<l;i++)
        {
            if (NS[i]=='!')
            {
                NS[i]='z'+1;
                l1=i;
            }
            if (NS[i]=='@')
            {
                NS[i]='z'+2;
            }
            NS[i]=turnS(NS[i]);
            ST.addText(NS,i);
        }
        ST.output(NS,l);
        printf("%lld\n",ST.walk(NS,l));
        bt[0].cc();bt[1].cc();
    }
    return 0;
}
