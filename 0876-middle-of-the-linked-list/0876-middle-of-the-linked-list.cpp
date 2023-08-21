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
    ListNode* middleNode(ListNode* head) {
        ListNode*curr=head;
        int ct=0;
        while(curr!=NULL){
            ct++;
            curr=curr->next;
        }
        int x=0;
        curr=head;
        while(x<(ct/2)){
            x++;
            curr=curr->next;
        }
        return curr;
    }
};