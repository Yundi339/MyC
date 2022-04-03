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
		vector<int> v;
		while (l1_index != nullptr && l2_index != nullptr) {
			next_num += l1_index->val + l2_index->val;
			v.push_back(next_num % 10);
			next_num /= 10;
			l1_index = l1_index->next;
			l2_index = l2_index->next;
		}
		// l1_index == nullptr OR l2_index == nullptr
		ListNode* temp;
		if (l1_index != nullptr)
			temp = l1_index;
		else
			temp = l2_index;
		while (temp != nullptr) {
			next_num += temp->val;
			v.push_back(next_num % 10);
			next_num /= 10;
			temp = temp->next;
		}
		if (next_num > 0) {
			v.push_back(next_num);
		}

		ListNode* res;
		temp = nullptr;
		for (vector<int>::iterator it = v.end() - 1; it != v.begin()-1; --it) {
			res = new ListNode(*it, temp);
			temp = res;
		}
		return res;
	}
};

int main()
{
	return 0;
}
