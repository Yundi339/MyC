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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* thead = new ListNode;
        thead->next = head;
        ListNode* temp = head;
        ListNode* temp2;
        while(temp != nullptr){
            temp2 = temp->next;
            if (temp2 != nullptr && temp2->val == temp->val){
                temp->next = temp2->next;
                delete temp2;
            }
            else{
                temp = temp->next;
            }
        }

        temp = thead->next;
        delete thead;
        return temp;
    }
};