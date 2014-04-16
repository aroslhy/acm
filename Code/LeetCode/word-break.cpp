#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		vector<bool> d(s.length()+1, 0);
		d[0] = 1;
		for (int i = 0; i < s.length(); i++) if (d[i]) {
			unordered_set<string>::iterator it = dict.begin();
			for (; it != dict.end(); it++) if (i+it->length() <= s.length() && s.substr(i, it->length()) == *it)
				d[i+it->length()] = 1;
		}
		return d[s.length()];
	}
};

int main() {
	Solution so;
	string s = "aaaaaaa";
	unordered_set<string> dict;
	dict.insert("aaaa");
	dict.insert("aaa");
	dict.insert("aa");
	bool ans = so.wordBreak(s, dict);
	cout << ans << endl;
	return 0;
}