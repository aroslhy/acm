#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int ans;
	int dfs(TreeNode *u) {
		if (!u)
			return 0;
		int maxl = dfs(u->left);
		int maxr = dfs(u->right);
		int res = max(u->val, u->val+max(maxl, maxr));
		ans = max(ans, max(res, maxl+u->val+maxr));
		return res;
	}
	int maxPathSum(TreeNode *root) {
		if (!root)
			return 0;
		ans = root->val;
		dfs(root);
		return ans;
	}
};

int main() {
	Solution so;
	TreeNode *p[5];
	p[0] = new TreeNode(1);
	p[1] = new TreeNode(-2);
	p[2] = new TreeNode(3);
	p[0]->left = p[1];
	p[0]->right = p[2];
	cout << so.maxPathSum(p[1]) << endl;
	return 0;
}
