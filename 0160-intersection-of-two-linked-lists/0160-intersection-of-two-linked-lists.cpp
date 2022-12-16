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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       int x=0;
       int y=0;
       ListNode*currA=headA;
       ListNode*currB=headB; 
       while(currA!=NULL){
           currA=currA->next;
           x++;
       } 
        while(currB!=NULL){
           currB=currB->next;
           y++;
       }
        ListNode*tempA=headA;
        ListNode*tempB=headB;
        if(x>y){
            
            for(int i=0;i<x-y;i++){
                tempA=tempA->next;
            }
        }
        else{
            for(int i=0;i<y-x;i++){
                tempB=tempB->next;
        }    }
        while(tempA!=NULL){
            if(tempA==tempB){
                return tempA;
            }
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;
    }
};