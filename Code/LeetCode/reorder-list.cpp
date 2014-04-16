#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode *head) {
		if (!head)
			return;
		ListNode *mid = head, *fast = head, *tmp;
		while (fast->next && fast->next->next) {
			fast = fast->next->next;
			mid = mid->next;
		}
		tmp = mid;
		mid = tmp->next;
		tmp->next = NULL;
		ListNode *pre = NULL;
		while (mid) {
			tmp = mid->next;
			mid->next = pre;
			if (!tmp)
				break;
			pre = mid;
			mid = tmp;
		}
		ListNode *cur = head, *tem;
		while (mid) {
			tmp = cur->next;
			tem = mid->next;
			cur->next = mid;
			mid->next = tmp;
			cur = tmp;
			mid = tem;
		}
	}
};

int main() {
	Solution so;
	ListNode a[5] = {0, 1, 2, 3, 4};
	for (int i = 0; i+1 < 5; i++)
		a[i].next = &a[i+1];
	ListNode *head = &a[0];
	so.reorderList(head);
	for (ListNode *p = head; p; p = p->next)
		cout << p->val << (p->next ? ' ' : '\n');
	return 0;
}
