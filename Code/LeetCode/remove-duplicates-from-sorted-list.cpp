#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode *cur = head;
		for (; cur; cur = cur->next) {
			while (cur->next && cur->val == cur->next->val) {
				ListNode *tmp = cur->next;
				cur->next = tmp->next;
				delete(tmp);
			}
		}
		return head;
	}
};

int main() {
	Solution so;
	ListNode *p[5], *head;
	for (int i = 0; i < 5; i++)
		p[i] = new ListNode(i);
	p[0]->val = 1;
	p[1]->val = 1;
	p[2]->val = 2;
	p[3]->val = 3;
	p[4]->val = 3;
	for (int i = 0; i+1 < 5; i++)
		p[i]->next = p[i+1];
	head = so.deleteDuplicates(p[0]);
	for (; head; head = head->next)
		cout << head->val << endl;
	return 0;
}
