#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
const int MAXN = 100+5, MAXM = 10000+5, MAXP = 50+5;
int T, n;
char line[MAXM], word[MAXP], url[MAXP];
map<pair<string, string>, bool> match;
map<string, int> R;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        match.clear();
        R.clear();
        scanf("%d", &n); gets(line);
        for (int i = 0; i < n; i++)
        {
            gets(line);
            int len = strlen(line);
            sscanf(line, "%s", word);
            int p = strlen(word);
            for (int r = 1; ; r++)
            {
                while (isspace(line[p]) && p < len)
                    p++;
                if (p >= len)
                {
                    R[(string)word] = r-1;
                    break;
                }
                sscanf(line+p, "%s", url);
                match[make_pair((string)url, (string)word)] = 1;
                p += strlen(url);
            }
        }
        double MAP = 0;
        for (int i = 0; i < n; i++)
        {
            gets(line);
            int len = strlen(line), cnt = 0;
            double AveP = 0;
            sscanf(line, "%s", word);
            int p = strlen(word);
            for (int r = 1; ; r++)
            {
                while (isspace(line[p]) && p < len)
                    p++;
                if (p >= len)
                    break;
                sscanf(line+p, "%s", url);
                if (match[make_pair((string)url, (string)word)])
                {
                    double P = (double)(++cnt)/r;
                    AveP += P;
                }
                p += strlen(url);
            }
            AveP /= (double)R[(string)word];
            MAP += AveP;
        }
        MAP /= (double)n;
        printf("Case #%d: %.6lf\n", cas, MAP);
    }
    return 0;
}
