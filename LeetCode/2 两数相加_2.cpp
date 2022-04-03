#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* l1_index = l1;
		ListNode* l2_index = l2;
		int next_num = 0;

		ListNode res;
		ListNode* temp_node;
		ListNode *res_cur = &res;
		while (l1_index || l2_index || next_num) {
			next_num += (l1_index?l1_index->val:0) + (l2_index ? l2_index->val : 0);
			temp_node = new ListNode(next_num % 10);
			res_cur->next = temp_node;
			res_cur = res_cur->next;
			next_num /= 10;
			if (l1_index) {
				l1_index = l1_index->next;
			}
			if (l2_index) {
				l2_index = l2_index->next;
			}
		}
		return res.next;
	}
};

int main()
{
	return 0;
}
