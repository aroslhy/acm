#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	void reverseWords(string &s) {
		stringstream sin(s);
		string temp, ans;
		vector<string> V;
		while (sin>>temp)
			V.push_back(temp);
		reverse(V.begin(), V.end());
		for (int i = 0; i < V.size(); i++) {
			if (i)
				ans += " ";
			ans += V[i];
		}
		s = ans;
	}
};

int main() {
	Solution x;
	string str = " d ";
	x.reverseWords(str);
	cout << str << endl;
	return 0;
}
