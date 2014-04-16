#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.empty())
			return "";
		string ans = "";
		bool flag = 1;
		for (int i = 0; i < strs[0].length() && flag; i++) {
			for (int j = 1; j < strs.size() && flag; j++) if (i >= strs[j].length() || strs[0][i] != strs[j][i])
				flag = 0;
			if (flag)
				ans += strs[0][i];
		}
		return ans;
	}
};

int main() {
	Solution so;
	vector<string> strs;
	strs.push_back("aaab");
	strs.push_back("saaa");
	strs.push_back("aaaca");
	cout << so.longestCommonPrefix(strs) << endl;
	return 0;
}
