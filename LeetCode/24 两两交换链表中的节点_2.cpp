class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode ans;
		ans.next = head;
		ListNode* temp = &ans;
		ListNode* a;
		ListNode* b = head;
		while (temp->next && temp->next->next) {
			a = b->next;
			temp->next = a;
			b->next = a->next;
			a->next = b;
			temp = b;
			b = b->next;
		}
		return ans.next;
	}
};