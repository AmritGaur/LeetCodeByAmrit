/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next || !head->next->next || !head->next->next->next){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        slow=slow->next;
        fast=fast->next->next;
        while(slow!=fast && fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        }
        if(slow!=fast){
            return NULL;
        }
        fast=head;
        while(slow!=fast){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};