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
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;       
        ListNode* m = head;
        ListNode* e = head->next;
        while(e && e->next) {
            m = m->next;
            e = e->next->next;
        }     
        ListNode* right = sortList(m->next);
        m->next = NULL;
        ListNode* left = sortList(head);      
        return merge(left, right);
    }   
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode* result=new ListNode(0);
        result->next=l1;
        ListNode* target1=result;
        ListNode* target2=new ListNode(0);
        target2->next=l2;
        while(target1->next!=NULL&&target2->next!=NULL){
            if(target1->next->val<=target2->next->val)target1=target1->next;
            else{
                l1=target1->next;
                l2=target2->next;
                target2->next=target2->next->next;
                l2->next=target1->next;
                target1->next=l2;
                target1=target1->next;
            }
        }
        if(target1->next==NULL)target1->next=target2->next;
        return result->next;
    }
};
