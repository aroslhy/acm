#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
struct Point {
	int x;
	int y;
	Point(): x(0), y(0) {}
	Point(int a, int b): x(a), y(b) {}
};

using namespace std;
class Solution {
public:
	int maxPoints(vector<Point> &points) {
		int ans = 0;
		for (int i = 0; i < points.size(); i++) {
			map<double, int> mp;
			int nok = 0, same = 0, maxi = 0;
			for (int j = 0; j < points.size(); j++) {
				if (points[j].x == points[i].x) {
					if (points[j].y == points[i].y)
						same++;
					else
						maxi = max(maxi, ++nok);
				}
				else {
					double k = double(points[j].y-points[i].y)/(points[j].x-points[i].x);
					maxi = max(maxi, ++mp[k]);
				}
			}
			ans = max(ans, maxi+same);
		}
		return ans;
	}
};

int main() {
	Solution so;
	vector<Point> vec;
	vec.push_back(Point(0, 0));
	vec.push_back(Point(0, 2));
	vec.push_back(Point(2, 0));
	vec.push_back(Point(2, 2));
	vec.push_back(Point(1, 1));
	cout << so.maxPoints(vec) << endl;
	return 0;
}