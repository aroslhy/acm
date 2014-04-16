#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> vec;
		stack<TreeNode *> sta, ass;
		sta.push(root);
		while (!sta.empty()) {
			TreeNode *p = sta.top();
			if (!ass.empty() && p == ass.top()) {
				vec.push_back(p->val);
				sta.pop();
				ass.pop();
			}
			else if (p) {
				ass.push(p);
				sta.push(p->right);
				sta.push(p->left);
			}
			else
				sta.pop();
		}
		return vec;
	}
};

int main() {
	Solution so;
	TreeNode node[3] = {0, 1, 2};
	node[0].left = &node[1];
	node[0].right = &node[2];
	vector<int> vec = so.postorderTraversal(&node[0]);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << (i+1 < vec.size() ? ", " : "\n");
	return 0;
}
