#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		ListNode front(0);
		while (head) {
			ListNode *pre = &front, *cur = head;
			while (pre->next && pre->next->val < cur->val)
				pre = pre->next;
			head = head->next;
			cur->next = pre->next;
			pre->next = cur;
		}
		return front.next;
	}
};

int main() {
	Solution so;
	const int N = 3;
	int a[N] = {1, 2, -4};
	ListNode *p[N];
	for (int i = 0; i < N; i++)
		p[i] = new ListNode(a[i]);
	for (int i = 0; i+1 < N; i++)
		p[i]->next = p[i+1];
	ListNode *newHead = so.insertionSortList(p[0]);
	// ListNode *newHead = so.insertionSortList(NULL);
	for (; newHead; newHead = newHead->next)
		cout << newHead->val << endl;
	for (int i = 0; i < N; i++)
		delete(p[i]);
	return 0;
}
