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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result=new ListNode(0);
        ListNode* s=result;
        while(l1&&l2){
            if(l1->val<l2->val){
                s->next=l1;
                l1=l1->next;
            }
            else{
                s->next=l2;
                l2=l2->next;
            }
            s=s->next;
        }
        if(l1)s->next=l1;
        else s->next=l2;
        return result->next;
    }
};
