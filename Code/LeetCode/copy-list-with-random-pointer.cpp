#include <iostream>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode *cur = head, *tmp, *newHead;
		for (;cur ; cur = tmp) {
			RandomListNode *x = new RandomListNode(cur->label);
			tmp = cur->next;
			cur->next = x;
			x->next = tmp;
		}
		cur = head;
		for (; cur; cur = cur->next->next)
			cur->next->random = cur->random ? cur->random->next : NULL;
		newHead = head ? head->next : NULL;
		cur = head;
		for (; cur; cur = cur->next) {
			tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = tmp->next ? tmp->next->next : NULL;
		}
		return newHead;
	}
};

int main() {
	Solution so;
	RandomListNode *p[5], *head;
	for (int i = 0; i < 5; i++)
		p[i] = new RandomListNode(i);
	p[0]->label = -1;
	p[1]->label = 8;
	p[2]->label = 7;
	p[3]->label = -3;
	p[4]->label = 4;
	p[0]->random = p[4];
	p[1]->random = p[3];
	p[2]->random = NULL;
	p[3]->random = NULL;
	p[4]->random = p[0];
	for (int i = 0; i+1 < 5; i++)
		p[i]->next = p[i+1];
	head = so.copyRandomList(p[0]);
	for (; head; head = head->next)
		cout << "label: " << head->label << ", next: " << (head->next ? head->next->label : 999) << ", random: " << (head->random ? head->random->label : 999) << endl;
	return 0;
}
