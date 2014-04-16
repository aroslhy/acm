#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<bool> d;
	vector<pair<int, int> > rec;
	void dfs(string &s, int n, unordered_set<string> &dict, vector<string> &ans) {
		if (n < 0) {
			string str = "";
			for (int i = rec.size()-1; i >= 0; i--) {
				str += s.substr(rec[i].first, rec[i].second);
				if (i)
					str += ' ';
			}
			ans.push_back(str);
			return;
		}
		if (d[n]) {
			for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
				if (n+1 >= it->length() && s.substr(n+1-it->length(), it->length()) == *it) {
					rec.push_back(make_pair(n-it->length()+1, it->length()));
					dfs(s, n-int(it->length()), dict, ans);
					rec.pop_back();
				}
			}
		}
	}
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		d.assign(s.length(), 0);
		for (int i = 0; i < s.length(); i++) {
			for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) if (!d[i] && i+1 >= it->length() && s.substr(i+1-it->length(), it->length()) == *it) {
				if (i-int(it->length()) < 0)
					d[i] = 1;
				else
					d[i] = d[i-it->length()];
			}
		}
		vector<string> ans;
		dfs(s, s.length()-1, dict, ans);
		return ans;
	}
};

int main() {
	Solution so;
	string s = "aaaaaaa";
	unordered_set<string> dict;
	dict.insert("aaaa");
	dict.insert("aaa");
	dict.insert("aa");
	vector<string> ans = so.wordBreak(s, dict);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}