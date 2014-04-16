#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head)
			return NULL;
		ListNode *p = head, *q = head;
		for (; ; ) {
			if (!q->next)
				return NULL;
			q = q->next;
			if (!q->next)
				return NULL;
			q = q->next;
			p = p->next;
			if (p == q) {
				p = head;
				while (p != q)
					p = p->next, q = q->next;
				return q;
			}
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
	ListNode *p = so.detectCycle(head);
	if (p)
		cout << p->val << endl;
	else
		cout << "NULL" << endl;
	return 0;
}
