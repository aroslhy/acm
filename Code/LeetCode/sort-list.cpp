#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *sortList(ListNode *head) {
		int len = 0;
		for (ListNode *p = head; p; p = p->next)
			len++;
		if (len < 2)
			return head;
		ListNode *tmp = head, *head2, *head3 = NULL, *cur = head3;
		for (int i = 0; i+1 < len/2; i++)
			tmp = tmp->next;
		head2 = tmp->next;
		tmp->next = NULL;
		head = sortList(head);
		head2 = sortList(head2);
		while (1) {
			if (head && head2) {
				if (head->val < head2->val) {
					tmp = head;
					head = head->next;
					tmp->next = NULL;
				}
				else {
					tmp = head2;
					head2 = head2->next;
					tmp->next = NULL;
				}
			}
			else if (head) {
				tmp = head;
				head = head->next;
				tmp->next = NULL;
			}
			else if (head2) {
				tmp = head2;
				head2 = head2->next;
				tmp->next = NULL;
			}
			else
				break;
			if (!head3)
				head3 = cur = tmp;
			else {
				cur->next = tmp;
				cur = cur->next;
			}
		}
		return head3;
	}
};

int main() {
	Solution so;
	ListNode a(1), b(2), c(1), d(4), e(-2), *p;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	p = &a;
	p = so.sortList(p);
	for (; p; p = p->next)
		cout << p->val << endl;
	return 0;
}
