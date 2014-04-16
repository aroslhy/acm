#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		stack<int> sta;
		for (int i = 0; i < tokens.size(); i++) {
			if (isdigit(tokens[i][tokens[i].length()-1])) {
				stringstream sin(tokens[i]);
				int a;
				sin >> a;
				sta.push(a);
				// cout << a << endl;
			}
			else {
				int a, b, c;
				b = sta.top(); sta.pop();
				a = sta.top(); sta.pop();
				switch (tokens[i][0]) {
					case '+':
					c = a+b;
					break;
					case '-':
					c = a-b;
					break;
					case '*':
					c = a*b;
					break;
					case '/':
					c = a/b;
					break;
				}
				sta.push(c);
				// cout << a << b << c << endl;
			}
		}
		return sta.top();
	}
};

int main() {
	vector<string> vec;
	vec.push_back("-1");
	vec.push_back("1");
	vec.push_back("*");
	vec.push_back("-1");
	vec.push_back("+");
	Solution x;
	cout << x.evalRPN(vec) << endl;
	return 0;
}
