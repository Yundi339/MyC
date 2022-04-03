/*
把题目理解成
第一步：
把链表 a1-b1-a2-b2-a3-b3-a4-...
转为链表 b1-a1-a2-b2-a3-b3-a4-...
第二步：
把链表 a1-b1-a2-b2-a3-b3-a4-...
转为链表 b1-a1-b2-a2-a3-b3-a4-...
以此类推........
*/
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode ans;
		ListNode* a1 = head;
		ListNode* b1 = head->next;
		ListNode* a2 = b1->next ? b1->next : nullptr;
		ListNode* b2 = a2 && a2->next ? a2->next : nullptr;
		ListNode* temp = &ans;
		while (a1 && b1) {
			a1->next = a2;
			b1->next = a1;
			temp->next = b1;
			temp = a1;
			a1 = a2;
			b1 = b2;
			a2 = b1 && b1->next ? b1->next : nullptr;
			b2 = a2 && a2->next ? a2->next : nullptr;
		}
		return ans.next;
	}
};