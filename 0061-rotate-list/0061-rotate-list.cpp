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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0 ){
            return head;
        }
        ListNode* prev =head;
        ListNode* curr =head;
        int c=0;
        while(curr!=NULL){
            curr=curr->next;
            c++;
        }
        if(k%c==0){
            return head;
        }
        int x=k;
        if(k>c){
            x=k%c;
        }
        curr=prev->next;
        for(int i=0;i<c-x-1;i++){
            curr=curr->next;
            prev=prev->next;
        }
        ListNode* res= prev->next;
        prev->next=NULL;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=head;
        return res;
    }
};