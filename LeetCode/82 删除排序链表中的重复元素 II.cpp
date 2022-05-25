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
    vector<int> test();
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* t_head = new ListNode();
        t_head->next = head;
        ListNode* t_node = head;
        ListNode* t_left = t_head;
        while (t_node != nullptr) {
            int data = t_node->val;
            bool flag = false;
            while (t_node->next != nullptr && t_node->next->val == data) {
                flag = true;
                ListNode* t = t_node;
                t_node = t_node->next;
                delete t;
            }
            if (flag) {
                ListNode* t = t_node;
                t_node = t_node->next;
                t_left->next = t_node;
                delete t;
            }
            else{
                t_left->next = t_node;
                t_node = t_node->next;
                t_left = t_left->next;            
            }
        }
        t_left->next = nullptr;
        head = t_head->next;
        return head;
    }
};