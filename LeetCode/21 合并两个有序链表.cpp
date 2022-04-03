void link(ListNode*& temp, ListNode*& list) {
	temp->next = list;
	temp = temp->next;
	list = list->next;
}

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (!list1)	return list2;
		if (!list2)	return list1;
		ListNode* ans = new ListNode();
		ListNode* temp = ans;
		while (list1 && list2) {
			if (list1->val <= list2->val) {
				link(temp, list1);
			}
			else {
				link(temp, list2);
			}
		}
		if (!list2) {
			temp->next = list1;
		}
		else if (!list1) {
			temp->next = list2;
		}
		temp = ans;
		ans = ans->next;
		delete temp;
		return ans;
	}
};