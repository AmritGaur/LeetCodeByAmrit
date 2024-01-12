/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(+x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head->next==NULL){
            return head;
        }
        ListNode*prev=NULL;
        ListNode*curr=head;
        while(curr!=NULL){
            ListNode*next1=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next1;
        }
        head=prev;
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* dummy= new ListNode(-1);
        ListNode* curr=dummy;
        int carry=0;
        while(curr1!=NULL && curr2!=NULL){
            int x= (curr1->val + curr2->val + carry)%10 ;
            curr->next= new ListNode(x);
            carry = (curr1->val + curr2->val +carry)/10;
            curr=curr->next;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        while(curr1!=NULL){
            int x= (curr1->val + carry )%10;
            curr->next= new ListNode(x);
            carry = (curr1->val+carry)/10;
            curr=curr->next;
            curr1=curr1->next;
        }
        while(curr2!=NULL){
            int x= (curr2->val+ carry)%10;
            curr->next= new ListNode(x);
            carry = (curr2->val+carry)/10;
            curr=curr->next;
            curr2=curr2->next;
        }
        if(carry!=0){
            curr->next =new ListNode(1);
        }
        return dummy->next;
    }
};