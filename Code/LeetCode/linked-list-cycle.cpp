#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (!head)
			return 0;
		ListNode *slow = head, *fast = head;
		for (; ; ) {
			if (!fast->next)
				return 0;
			fast = fast->next;
			if (!fast->next)
				return 0;
			fast = fast->next;
			slow = slow->next;
			if (slow == fast)
				return 1;
		}
	}
};

int main() {
	ListNode a[5] = {0, 1, 2, 3, 4};
	a[0].next = &a[1];
	a[1].next = &a[2];
	a[2].next = &a[1];
	Solution so;
	ListNode *head = &a[0];
	cout << so.hasCycle(head) << endl;
	return 0;
}
