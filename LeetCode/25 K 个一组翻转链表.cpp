class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k==1 || !head || !head->next) return head;
		ListNode ans;
		ListNode* temp = &ans;
		ListNode* fast = head;
		ListNode* slow = head;
		stack<ListNode*>mystack;
		int count = 0;
		while (count == k || fast) {
			if (count != k) {
				++count;
				mystack.push(fast);
				fast = fast->next;
			}
			else {
				while (count) {
                    --count;
					temp->next = mystack.top();
					temp = temp->next;
					mystack.pop();
				}
				slow = fast;
			}
		}
		temp->next = slow;
		return ans.next;
	}
};