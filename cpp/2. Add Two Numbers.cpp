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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        int digit=l1->val+l2->val;
        ListNode* reborn=new ListNode(digit);
        ListNode* sta=reborn;
        while(l1->next!=NULL&&l2->next!=NULL){
            l1=l1->next;
            l2=l2->next;
            if(reborn->val>=10){
                reborn->val-=10;
                digit=l1->val+l2->val+1;
            }
            else digit=l1->val+l2->val;       
            ListNode* pNewNode=new ListNode(digit);
            reborn->next=pNewNode;
            reborn=pNewNode;
        }
        if(l1->next==NULL&&l2->next!=NULL){
            while(l2->next!=NULL){
            l2=l2->next;
            if(reborn->val>=10){
                reborn->val-=10;
                digit=l2->val+1;
            }
            else digit=l2->val;       
            ListNode* pNewNode=new ListNode(digit);
            reborn->next=pNewNode;
            reborn=pNewNode;
            }
        }
        if(l2->next==NULL&&l1->next!=NULL){
            while(l1->next!=NULL){
            l1=l1->next;
            if(reborn->val>=10){
                reborn->val-=10;
                digit=l1->val+1;
            }
            else digit=l1->val;       
            ListNode* pNewNode=new ListNode(digit);
            reborn->next=pNewNode;
            reborn=pNewNode;
            }
        }
        if(reborn->val>=10){
            reborn->val-=10;
            ListNode* pNewNode=new ListNode(1);
            reborn->next=pNewNode;
            reborn=pNewNode;
        }
        return sta;
    }
};
