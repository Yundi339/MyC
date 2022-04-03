/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head || !head->next) return nullptr;
		n = n + 1;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != nullptr && n) {
			fast = fast->next;
			--n;
		}
		while (fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		if (!n) {
			slow->next = slow->next->next;
		}
		else {
			head = head->next;
		}
		return head;
	}
};