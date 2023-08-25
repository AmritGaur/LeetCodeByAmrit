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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1=list1;
        ListNode* head2=list2;
        if(head1==NULL){
            return list2;
        }
        if(head2==NULL){
            return list1;
        }
        ListNode* res=NULL;
        ListNode* temp=NULL;
        ListNode* ans=NULL;
        if(list1->val<list2->val){
            temp=list1->next;
                res=list1;
                list1->next=NULL;
                list1=temp;
        }
        else{
            temp=list2->next;
                res=list2;
                list2->next=NULL;
                list2=temp;
        }
        ans=res;
        while(list1 && list2){
            if(list1->val<list2->val){
                temp=list1->next;
                res->next=list1;
                list1->next=NULL;
                list1=temp;
                res=res->next;
            }
            else{
                temp=list2->next;
                res->next=list2;
                list2->next=NULL;
                list2=temp;
                res=res->next;
            }
        }
        while(list1){
            temp=list1->next;
                res->next=list1;
                list1->next=NULL;
                list1=temp;
                res=res->next;
        } 
        while(list2){
            temp=list2->next;
                res->next=list2;
                list2->next=NULL;
                list2=temp;
                res=res->next;
        }
        return ans;
    }
};