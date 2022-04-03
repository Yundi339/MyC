bool cmp(const ListNode* l1, const ListNode* l2) {
	return l1->val < l2->val;
}

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		vector<ListNode*> vt;
		for (ListNode*& t : lists) {
			while (t != nullptr) {
				vt.push_back(t);
				t = t->next;
			}
		}
		if (vt.size() == 0)return nullptr;
		if (vt.size() == 1)return vt[0];
		sort(vt.begin(), vt.end(), cmp);
		ListNode head = ListNode(0);
		ListNode* temp = &head;
		for (ListNode*& t : vt) {
			temp->next = t;
			temp = temp->next;
		}
		temp->next = nullptr;
		return head.next;
	}
};