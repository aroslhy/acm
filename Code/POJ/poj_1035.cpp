//bigoceanlhy	1035	Accepted	476K	375MS	C++	1519B	2012-02-04 18:20:52
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string Dic[10000+5];
int n;
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    for (;;)
    {
        string dic;
        cin>>dic;
        if (dic == "#") break;
        Dic[++n] = dic;
    }
    for (;;)
    {
        string chk;
        cin>>chk;
        if (chk == "#") break;
        bool flag = 0;
        for (int i = 1; i <= n; i++)
            if (chk == Dic[i])
            {
                cout<<chk<<" is correct"<<endl;
                flag = 1;
                break;
            }
        if (!flag)
        {
            int len_chk = chk.length();
            cout<<chk<<":";
            for (int i = 1; i <= n; i++)
            {
                string dic = Dic[i];
                int len_dic = dic.length();
                if (len_chk == len_dic)
                {
                    int cnt = 0;
                    for (int j = 0; j < len_chk && cnt <= 1; j++)
                        if (chk[j] != dic[j]) cnt++;
                    if (cnt == 1) cout<<" "+dic;
                }
                if (len_chk == len_dic+1)
                {
                    string tmp;
                    for (int j = 0; j < len_chk; j++)
                        if (chk[j] != dic[j])
                        {
                            tmp = chk;
                            tmp.erase(j, 1);
                            if (tmp == dic) cout<<" "+dic;
                            break;
                        }
                }
                if (len_chk == len_dic-1)
                {
                    string tmp;
                    for (int j = 0; j < len_dic; j++)
                        if (chk[j] != dic[j])
                        {
                            tmp = chk;
                            tmp.insert(j, 1, dic[j]);
                            if (tmp == dic) cout<<" "+dic;
                            break;
                        }
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
