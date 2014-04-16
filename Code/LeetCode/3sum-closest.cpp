#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int ans = num[0]+num[1]+num[2];
		for (int i = 0; i < num.size(); i++) {
			int j = i+1, k = num.size()-1;
			while (j < k) {
				int sum = num[i]+num[j]+num[k];
				if (abs(sum-target) < abs(ans-target))
					ans = sum;
				sum < target ? j++ : k--;
			}
		}
		return ans;
	}
};

int main() {
	Solution so;
	int a[] = {2, 3, 4, 5, 6};
	vector<int> vec(a, a+5);
	cout << so.threeSumClosest(vec, 20) << endl;
	return 0;
}
